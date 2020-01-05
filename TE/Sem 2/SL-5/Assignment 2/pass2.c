#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

// Global arrays
char IS[13][8], DL[2][4], AD[5][8], REG[4][5];

// Custom function to split strings
void split(char buffer2D[3][10], char *str,char sep){
	int i,j=0,k=0;

	for(i=0;i<4;i++)
		buffer2D[i][0] = '\0';

	for(i=0;str[i];i++){
		if(str[i] == sep){
			j+=1;
			k=0;
			continue;
		}
		buffer2D[j][k]=str[i];
		k+=1;
	}
}

// Function to check operands
void check_operand(int Op[2], char *buf){
	int j,flag=0,i;
	char *ptr;	
	// Search for REG keyword
	for(j=0;j<4;j++){
		ptr = strstr(buf, REG[j]);
		if (ptr != NULL){
			Op[0]=6;
			Op[1]=j+1;
			return;
		}
	}
	// Search for Constant
	for(i=0,flag=0;buf[i];i++)
		if(buf[i]=='0'||buf[i]=='1'||buf[i]=='2'||buf[i]=='3'||buf[i]=='5'||buf[i]=='6'||buf[i]=='7'||buf[i]=='8'||buf[i]=='9')
		 	flag++;
	if(flag==(i-1)){
		Op[0]=7;
		Op[1]=1;
		return;
	}	
	// Else a Symbol
	Op[0]=5;
	Op[1]=1;
	return;	
}

// Fucntion to check mnemonics class and opcode
void check_mnemonics(int Op[2], char *buf){
	int j;
	char *ptr;
	// Search the word for keywords
	// Search for IS keyword
	for(j=0;j<12;j++){
		ptr = strstr(buf, IS[j]);
		if (ptr != NULL){
			Op[0]=2;
			Op[1]=j;
			return;
		}
	}
	// Search for AD keyword
	for(j=0;j<5;j++){
		ptr = strstr(buf, AD[j]);
		if (ptr != NULL){
			Op[0]=3;
			Op[1]=j+1;
			return;
		}
	}
	// Search for DL keyword
	for(j=0;j<2;j++){
		ptr = strstr(buf, DL[j]);
		if (ptr != NULL){
			Op[0]=4;
			Op[1]=j+1;
			return;
		}
	}
	Op[0]=1;
	Op[1]=1;
}

// Fuction to check basic label
void check_label(int Op[2],char *buf){
	if(isalpha(buf[0])){
		Op[0]=1;
		Op[1]=1;
		return;
	}
	Op[0]=0;
	Op[1]=0;
}

// Main function
void main(int argc, char *argv[]){
	time_t t;
    time(&t);
	int verbose;

	if(argc < 2){
		printf("[ERROR] Please specify input program file \n\n");
		return;
	}
	else if(argc == 2)
		verbose = 0;
	else if(argc == 3)
		verbose = atoi(argv[2]);

	if(verbose){
		printf("=========================== 2 PASS ASSEMBLER ==========================");
		printf(" %s ",ctime(&t));
	}

	// Variables for the program
	FILE *write_IC, *read_keywords, *read_program, *write_symbol;
	char ch, buffer1D[400],buffer2D[3][10];
	int num_lines, num_keywords[32], i, j, flg, count, Op[2];

	// Open the keywords file for reading
	read_keywords = fopen("keywords.txt","r");

	// Populate the keywords array IS, DS, AD, REG
	if(verbose)
		printf("\n[INFO] Initializing keywords in all arrays IS, DL, AD, REG");
	flg=1;
	for(j=0;flg!=-1;j++){
		flg = fscanf(read_keywords,"%s",buffer1D);
		if(j<=12)
			strcpy(IS[j],buffer1D);
		else if(j<=17)
			strcpy(AD[j-13],buffer1D);
		else if(j<=19)
			strcpy(DL[j-18],buffer1D);
		else if(flg!=-1)
			strcpy(REG[j-20],buffer1D);
	}
	// Print out the arrays
	if(verbose){
		printf("\n[INFO] IS array :");
		for(i=0;i<=12;i++)
			printf(" %s ",IS[i]);
		printf("\n[INFO] DL array :");  
		for(i=0;i<2;i++)
			printf(" %s ",DL[i]);
		printf("\n[INFO] AD array :");  
		for(i=0;i<5;i++)
			printf(" %s ",AD[i]);
		printf("\n[INFO] REG array :");  
		for(i=0;i<4;i++)
			printf(" %s ",REG[i]);
	  }

	// Close the file
	fclose(read_keywords);

	if(verbose)
		printf("\n[INFO] Initializing Symbol table and IC");

	// Opening the input program file for reading
	read_program = fopen(argv[1],"r");
	
	// Processing program name
	split(buffer2D,argv[1],'.');

	// Creating and opening the file for writing symbol table
	write_symbol = fopen(strcat(buffer2D[0],"_symbol_table.txt"),"w");
	split(buffer2D,buffer2D[0],'_');
	write_IC = fopen(strcat(buffer2D[0],"_ic.txt"),"w");


	// Start with main algorithm
	if(read_program == NULL){
		// Check if this filePointer is null
		// which maybe if the file does not exist
	    printf("\n[ERROR] Unable to open program file %s ",argv[1]);
		return;
	}
	else{    
		if(verbose)            
			printf("\n[INFO] Reading the input program \n");    

		// Read character by character
	    ch = fgetc(read_program);
	    count = 0;
		i = 0;
		           
	    // Reading the data using fgets() method
	    while(ch != EOF){

			// Encoutered space
			if(ch == ' '){
				buffer1D[i] = '\0';
			    // Print words  
			    if(verbose)            
				   printf("%s \n",buffer1D);

				i = 0;
				// 1st word in line
				if(count == 0){
					// Appropriate label syntax
					check_label(Op,buffer1D);
					if(Op[0] == 1){
						// Check for mnemonic class and respective opcode
						check_mnemonics(Op,buffer1D);
						if(Op[0] != 1){
							// Write in intermediate code file
							fputc('(',write_IC);

							// Write Class 
							if(Op[0] == 2)
								fputs("IS",write_IC);
							if(Op[0] == 3)
								fputs("AD",write_IC);
							if(Op[0] == 4)
								fputs("DL",write_IC);
							fputc(',',write_IC);
							
							// Write Opcode
							sprintf(buffer1D,"%d",Op[1]);
							fputs(buffer1D,write_IC);

							// Print Opcode
							if(verbose)            
							   printf("%d %s \n",Op[0],buffer1D);
							
							fputc(')',write_IC);
						}
						else{
							// Check and update the symbol table
						}
					}
					else if(Op[0] == 0)
						printf("[ERROR] Incorrect Mnemonics or Label on line number %d ",num_lines);
				}
				// 2nd word in line
				else if(count == 1){
					// Process mnemonic
					if(Op[0] == 1){
						check_mnemonics(Op,buffer1D);
						// Label cannot be repeated after Label
						if(Op[0] == 1)
							printf("[ERROR] Missing Mnemonics on line number %d ",num_lines);
						else{
							fputc('(',write_IC);

							// Write Class 
							if(Op[0] == 2)
								fputs("IS",write_IC);
							else if(Op[0] == 3)
								fputs("AD",write_IC);
							else if(Op[0] == 4)
								fputs("DL",write_IC);
							fputc(',',write_IC);
							
							// Write Opcode
							sprintf(buffer1D,"%d",Op[1]);
							fputs(buffer1D,write_IC);
							
							fputc(')',write_IC);
						}
					}
					// Process Operand
					if(Op[0] == 2){
						// Opcode wise Operand selection
						if(Op[1] > 0){
							check_operand(Op, buffer1D);
							if(Op[0] == 5){
								// Check and update Symbol table
							}
							else if(Op[0] == 6){
								// Process register
								// Write in intermediate code file
								fputc('(',write_IC);

								// Write Reg Class 
								if(Op[1] == 1)
									fputs("1",write_IC);
								if(Op[1] == 2)
									fputs("2",write_IC);
								if(Op[1] == 3)
									fputs("3",write_IC);
								if(Op[1] == 4)
									fputs("4",write_IC);								
																
								fputc(')',write_IC);
							}
							else if(Op[0] == 7){
								// Write constant
								fputc('(',write_IC);
								fputs("c",write_IC);
								fputs(buffer1D,write_IC);
								fputc(')',write_IC);
							}
						}
					}
					else if(Op[0] == 3){
						// AD	   
					}
					else if(Op[0] == 4){
	   					// DL
					}										
				}
				// 3rd word in line
				else if(count == 2){
					// Process Operand
					if(Op[0] == 2){
						// Opcode wise Operand selection
						if(Op[1] > 0){
							check_operand(Op, buffer1D);
							if(Op[0] == 5){
								// Check and update Symbol table
							}
							else if(Op[0] == 6){
								// Process register
								// Write in intermediate code file
								fputc('(',write_IC);

								// Write Reg Class 
								if(Op[1] == 1)
									fputs("1",write_IC);
								if(Op[1] == 2)
									fputs("2",write_IC);
								if(Op[1] == 3)
									fputs("3",write_IC);
								if(Op[1] == 4)
									fputs("4",write_IC);								
																
								fputc(')',write_IC);
							}
							else if(Op[0] == 7){
								// Write constant
								fputc('(',write_IC);
								fputs("c",write_IC);
								fputs(buffer1D,write_IC);
								fputc(')',write_IC);
							}
						}
					}
					if(Op[0] == 5){
					}					
					if(Op[0] == 6){
					}					
					if(Op[0] == 7){
					}					
					else if(Op[0] == 3){
						// AD	   
					}
					else if(Op[0] == 4){
	   					// DL
					}										
				}
				for(j=0;buffer1D[j];j++)
					buffer1D[j] = '-';
					count++;
			}
			if(ch == '\n'){
				count = 0;
				num_lines++;
				
				// Empty the buffer
				for(j=0;buffer1D[j];j++)
					buffer1D[j] = '\0';

		        fputc('\n',write_IC);
				i=0;
			}
			else{
				// Put character in buffer
				buffer1D[i] = ch;
				i++;
			}
			// Read character by character
			ch = fgetc(read_program);
		}	 
	}
	fclose(read_program);
	fclose(write_symbol);
	fclose(write_IC);
}
