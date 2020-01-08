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
	
	// Search for REG keyword
	for(j=0;j<4;j++){
		if(strcmp(buf, REG[j]) == 0){
			Op[0]=6;
			Op[1]=j+1;
			return;
		}
	}	
	// Search for Constant
	for(i=0,flag=0;buf[i];i++)
		if(buf[i]=='0'||buf[i]=='1'||buf[i]=='2'||buf[i]=='3'||buf[i]=='5'||buf[i]=='6'||buf[i]=='7'||buf[i]=='8'||buf[i]=='9')
		 	flag++;
		 	
	if(flag==i){
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
	// Search the word for keywords
	// Search for IS keyword
	for(j=0;j<13;j++){
		if (strcmp(buf, IS[j]) == 0){
			Op[0]=2;
			Op[1]=j;
			return;
		}
	}
	// Search for AD keyword
	for(j=0;j<5;j++){
		if (strcmp(buf, AD[j]) == 0){
			Op[0]=3;
			Op[1]=j+1;
			return;
		}
	}
	// Search for DL keyword
	for(j=0;j<2;j++){
		if (strcmp(buf, DL[j]) == 0){
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

// Function to write mnemonics in file
void write_mnemonic(FILE *write_IC, int Op[2], char *buffer1D, int verbose, int IC){
	// Temporary buffer
	char s[5];
	
	// Select Class 
	if(Op[0] == 2){
		strcpy(s,"IS");
		IC++;
	}
	if(Op[0] == 3)
		strcpy(s,"AD");
	if(Op[0] == 4){
		strcpy(s,"DL");
		IC++;
	}
		
	// write Instruction Counter
	sprintf(buffer1D,"%d ",IC);
	fputs(buffer1D,write_IC);

	// Bracket open
	fputc('(',write_IC);

	// write class
	fputs(s,write_IC);	

	// Comma separation
	fputc(',',write_IC);

	// Write Opcode
	sprintf(buffer1D,"%d",Op[1]);
	fputs(buffer1D,write_IC);
	
	// Print Opcode
	if(verbose)            
	   printf("\n Class : %d Opcode : %s ",Op[0],buffer1D);
	
	fputc(')',write_IC);
}

// Fucntion to write registers in file
void write_register(FILE *write_IC, int Op[2], char *buffer1D, int verbose){
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
	
	// Print Register
	if(verbose)            
	   printf("\n Register : %d ",Op[1]);
}

// Fucntion to write constants in file
void write_constant(FILE *write_IC, char *buffer1D, int verbose){
	// Write constant
	fputc('(',write_IC);
	fputs("c,",write_IC);
	fputs(buffer1D,write_IC);
	fputc(')',write_IC);
	
	// Print Register
	if(verbose)            
	   printf("\n Constant : %s ",buffer1D);	
}

// Fucntion to write symbol in file
void write_symbol(FILE *write_IC, char *buffer1D, int verbose){
	// Write Symbol
	fputc('(',write_IC);
	fputs("s,",write_IC);
	fputs(buffer1D,write_IC);
	fputc(')',write_IC);
	
	// Print Register
	if(verbose)            
	   printf("\n Symbol : %s ",buffer1D);	
}

// Function to insert labels in symbol table
int check_update_symbol_table(char symbol_table[30][100],char *buffer1D){
	// Insert Label at first empty index
	int i,j;

	for(i=0;i<30;i++){
		if(!strcmp(symbol_table[i],buffer1D))
			return i;
		else{
			strcat(buffer1D,",");
			strcpy(symbol_table[i],buffer1D);
			return i;
		}
	}
}

// Insert address in Symbol Table
void insert_address_symbol_table(char symbol_table[30][100],int temp,int IC,int size){
	int i,j;
	char buff[20];
	sprintf(buff,"%d,%d-",IC,size);
	
	i=0;
	for(j=0;j<100;j++){
		if(symbol_table[temp][j])
			continue;

		symbol_table[temp][j] = buff[i];
		if(buff[i] == '-')
			break;
		i++;
	}
	symbol_table[temp][j] = '\n';
}

// Main function
void main(int argc, char *argv[]){
	time_t t;
    time(&t);
	int verbose;
	
	// Check commandline arguments
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
	FILE *write_IC, *read_keywords, *read_program, *write_symbol_file;
	char ch, buffer1D[400],buffer2D[3][10],symbol_table[30][100];
	int num_lines, num_keywords[32], i, j, flg, count, Op[2], IC, temp;

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

	// Populate Symbol Table
	if(verbose)
		printf("\n[INFO] Initializing Symbol Table Data Structures");	
	// Initialze Symbol Table Data Structure
	for(i=0;i<30;i++)
		for(j=0;j<10;j++)
			symbol_table[i][j] = '\0';
			
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
		printf("\n[INFO] Initializing Symbol table and Intermediate Code files");

	// Opening the input program file for reading
	read_program = fopen(argv[1],"r");
	
	// Processing program name
	split(buffer2D,argv[1],'.');

	// Creating and opening the file for writing symbol table
	write_symbol_file = fopen(strcat(buffer2D[0],"_symbol_table.txt"),"w");
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
		// Read character by character
		if(verbose)            
			printf("\n[INFO] Reading the input program \n");    

	    ch = fgetc(read_program);
	    count = 0;
		i = 0;
		           
	    // Reading the data using fgets() method
	    while(ch != EOF){
			// Encoutered space
			if(ch == ' ' || ch == '\n'){
				buffer1D[i] = '\0';
				
			    // Print words  
			    if(verbose)            
				   printf("\n String : %s Count : %d",buffer1D,count);

				i = 0;
				
				// 1st word in line
				if(count == 0){
					// Check for appropriate label syntax
					check_label(Op,buffer1D);
					// Correct Label found
					if(Op[0] == 1){
						// Check for mnemonic class and respective opcode
						check_mnemonics(Op,buffer1D);
						if(Op[0] != 1){
							// Write mnemonic in IC file
							// Print Opcode
							write_mnemonic(write_IC, Op, buffer1D,verbose,IC);
						}
						else{
							// Check and Update the symbol table
							temp = check_update_symbol_table(symbol_table,buffer1D);
							insert_address_symbol_table(symbol_table,temp,IC,1);
						}
					}
					else if(Op[0] == 0)
						printf("\n [ERROR] Incorrect Mnemonics or Label :: LINE NUMBER %d ",num_lines);
				}
				
				// 2nd word in line
				else if(count == 1){
					// Process mnemonic
					if(Op[0] == 1){
						check_mnemonics(Op,buffer1D);
						// Label cannot be repeated after Label
						if(Op[0] == 1)
							printf("\n [ERROR] Missing Mnemonics :: LINE NUMBER %d ",num_lines);
						else{
							// Write mnemonic in IC file
							write_mnemonic(write_IC, Op, buffer1D,verbose,IC);
						}
					}
					// IS class preceded : Process Operand
					if(Op[0] == 2){
						// Opcode wise Operand selection (Skip STOP)
						if(Op[1] > 0){
							check_operand(Op, buffer1D);
							if(Op[0] == 5){
								// Check and update Symbol table
								temp = check_update_symbol_table(symbol_table,buffer1D);
								sprintf(buffer1D,"%d",temp);
								write_symbol(write_IC,buffer1D,verbose);
							}
							else if(Op[0] == 6){
								// Write register in IC file
								write_register(write_IC, Op, buffer1D,verbose);
							}
							else if(Op[0] == 7){
								// Write constant
								write_constant(write_IC, buffer1D, verbose);
							}
						}
					}
					// AD class preceded : Process Operand
					else if(Op[0] == 3){
						// Opcode wise Operand selection (Initialize IC with START, Skip END)
						if(Op[1] == 1){
							check_operand(Op, buffer1D);
							if(Op[0] == 5 || Op[0] == 6){
								printf("\n [ERROR] START Assembler Directive cannot use Registers or symbols :: LINE NUMBER %d ",num_lines);
							}
							else if(Op[0] == 7){
								IC = atoi(buffer1D);
								// Write constant
								write_constant(write_IC, buffer1D, verbose);
							}
						}
						else if(Op[1] == 2){
							printf("\n [ERROR] END cannot have operands %d ",num_lines);
						}
						else{
							check_operand(Op, buffer1D);
							if(Op[0] == 5){
								// Check and update Symbol table
								temp = check_update_symbol_table(symbol_table,buffer1D);
								sprintf(buffer1D,"%d",temp);
								write_symbol(write_IC,buffer1D,verbose);
							}
							else if(Op[0] == 6){
								printf("\n [ERROR] Assembler Directives cannot use Registers %d ",num_lines);
							}
							else if(Op[0] == 7){
								// Write constant
								write_constant(write_IC, buffer1D, verbose);
							}
						}
					}
					else if(Op[0] == 4){
	   					// DL
					}										
				}
				// 3rd word in line
				else if(count == 2){
					// Process Operand
					//if(Op[0] == 2){
						// Opcode wise Operand selection
						//if(Op[0] == 2){
							check_operand(Op, buffer1D);
							printf("eeeee %d ",Op[0]);
							if(Op[0] == 5){
								// Check and update Symbol table
								temp = check_update_symbol_table(symbol_table,buffer1D);
								sprintf(buffer1D,"%d",temp);
								write_symbol(write_IC,buffer1D,verbose);
							}
							else if(Op[0] == 6){
								// Write register in file
								write_register(write_IC, Op, buffer1D, verbose);
							}
							else if(Op[0] == 7){
								// Write constant
								write_constant(write_IC, buffer1D, verbose);
							}
						//}
					//}
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
					buffer1D[j] = '\0';
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
			else if(ch != ' '){
				// Put character in buffer
				buffer1D[i] = ch;
				i++;
			}
			// Read character by character
			ch = fgetc(read_program);
		}	 
	}

	// store symbol table in file
	for(i=0;symbol_table[i][0];i++)
		fprintf(write_symbol_file,"%s",symbol_table[i]);

	fclose(read_program);
	fclose(write_symbol_file);
	fclose(write_IC);
}
