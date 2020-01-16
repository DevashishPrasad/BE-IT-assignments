#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

// Literal data structures
typedef struct literal_pool{
	char literal[10];
}lit_pool;

typedef struct literal_table{
	int i;
	char literal[10];
	int address;
}lit_table;

typedef struct pool_tab{
	int i;
}pool_t;

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
	// Search for a Literal
	if(buf[0] == '=' && buf[1] == '\''){
		Op[0]=8;
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
int write_mnemonic(FILE *write_IC, int Op[2], char *buffer1D, int verbose, int LC){
	// Temporary buffer
	char s[5];
	
	// Select Class 
	if(Op[0] == 2){
		strcpy(s,"IS");
		LC++;
	}
	if(Op[0] == 3)
		strcpy(s,"AD");
	if(Op[0] == 4){
		strcpy(s,"DL");
		LC++;
	}
		
	// write Instruction Counter
	sprintf(buffer1D,"%d ",LC);
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
	
	return LC;
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
	fputs("C,",write_IC);
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
	fputs("S,",write_IC);
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
		if(!strcmp(symbol_table[i],buffer1D)){
			return i;
		}
		else if(symbol_table[i][0] == '\0'){
			strcpy(symbol_table[i],buffer1D);
			return i;
		}
	}
}

// Insert address in Symbol Table
int insert_address_symbol_table(char symbol_table[30][100],int temp,int LC,int size){
	int i,j;
	char buff[20];
	sprintf(buff,",%d,%d-",LC,size);
	
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
	//printf("%s",symbol_table[temp]);
	return LC+size;
}

// Function to insert labels in symbol table
void update_literal_data(lit_pool lp[10], lit_table[10], char *buffer1D){
	// Insert Label at first empty index
	int i;
	char no[100];
	
	for(i=0;i<10;i++){
		if(lit_pool[i].[0] == '\0'){
			strcpy(literal_pool[i],buffer1D);
			break;
		}
	}

	for(i=0;i<10;i++){
		if(literal_table[i][0] == '\0'){
			sprintf(no," %d ", i);
			strcpy(no,buffer1D);
			strcpy(literal_table[i],no);
			return;
		}
	}
}

// Insert address in Symbol Table
int insert_address_literal_data(char literal_table[10][70],int temp,int LC,int size){
	int i,j;
	char buff[20];
	sprintf(buff,",%d,%d-",LC,size);
	
	i=0;
	for(j=0;j<100;j++){
		if(literal_table[temp][j])
			continue;

		literal_table[temp][j] = buff[i];
		if(buff[i] == '-')
			break;
		i++;
	}
	literal_table[temp][j] = '\n';
	//printf("%s",symbol_table[temp]);
	return LC+size;
}

// Function to insert labels in Literal Pool
int check_update_literal_pool(char literal_pool[10][20], char literal_table[10][70], char *buffer1D){
	// Insert Label at first empty index
	int i,j;

	for(i=0;i<30;i++){
		if(!strcmp(literal_table[i],buffer1D)){
			return i;
		}
		else if(literal_table[i][0] == '\0'){
			strcpy(literal_table[i],buffer1D);
			return i;
		}
	}
}

// Function to insert labels in Literal Pool
int check_update_pool_tab(char literal_pool[10][20], char literal_table[10][70], char *buffer1D){
	// Insert Label at first empty index
	int i,j;

	for(i=0;i<30;i++){
		if(!strcmp(literal_table[i],buffer1D)){
			return i;
		}
		else if(literal_table[i][0] == '\0'){
			strcpy(literal_table[i],buffer1D);
			return i;
		}
	}

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
		printf("\n %s ",ctime(&t));
	}
	
	// Variables for the program
	FILE *write_IC, *read_keywords, *read_program, *write_symbol_file, *write_literal_file;
	char ch,buffer1D[400],buffer2D[3][10],symbol_table[30][100],maintain_symbol[20],literal_pool[10][20],literal_table[10][70],pool_tab[10][20];
	int num_lines, num_keywords[32], i, j, flg, count, Op[2], LC, temp;
	lit_pool lp[10];
	lit_table lt[10];
	pool_t pt[10];
			
	// Open the keywords file for reading
	read_keywords = fopen("keywords.txt","r");

	// Populate the keywords array IS, DS, AD, REG
	if(verbose)
		printf("\n[INFO] Initializing KEYWORDS in all arrays IS, DL, AD, REG");
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
	
	// Populate Literal Table
	if(verbose)
		printf("\n[INFO] Initializing Literal Table Data Structures");	
	
	// Initialze Literal Table Data Structure
	for(i=0;i<30;i++)
		for(j=0;j<10;j++)
			literal_table[i][j] = '\0';
	for(i=0;i<30;i++)
		for(j=0;j<10;j++)
			lit_table[i][j] = '\0';
	
	// Populate Literal Pool
	if(verbose)
		printf("\n[INFO] Initializing Literal Pool Data Structures");	
	// Initialze Literal Pool Data Structure
	for(i=0;i<30;i++)
		for(j=0;j<10;j++)
			literal_pool[i][j] = '\0';
	for(i=0;i<30;i++)
		for(j=0;j<10;j++)
			lit_pool[i][j] = '\0';
	
	// Populate Pool Tab
	if(verbose)
		printf("\n[INFO] Initializing Pool Tab Data Structures");	
	// Initialze Pool Tab Data Structure
	for(i=0;i<30;i++)
		for(j=0;j<10;j++)
			pool_tab[i][j] = '\0';
					
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

	// Creating and opening the file for writing symbol table
	split(buffer2D,buffer2D[0],'_');
	write_literal_file = fopen(strcat(buffer2D[0],"_literal.txt"),"w");

	// Start with main algorithm
	if(read_program == NULL){
		// Check if this filePointer is null
		// which maybe if the file does not exist
	    printf("\n[ERROR] Unable to open program file :: LINE NUMBER %s ",argv[1]);
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
							LC = write_mnemonic(write_IC, Op, buffer1D,verbose,LC);
						}
						else if(Op[1] == 2 || Op[1] == 5){
							LC = insert(write_IC, Op, buffer1D,verbose,LC);
						}
						else{
							// Maintain the symbol for DL statements
							strcpy(maintain_symbol,buffer1D);
						}
					}
					else if(Op[0] == 0)
						printf("\n [ERROR] Incorrect MNEMONICS or LABEL :: LINE NUMBER %d ",num_lines);
				}
				
				// 2nd word in line
				else if(count == 1){
					// Process mnemonic
					if(Op[0] == 1){
						check_mnemonics(Op,buffer1D);
						// Label cannot be repeated after Label
						if(Op[0] == 1)
							printf("\n [ERROR] Missing MNEMONICS :: LINE NUMBER %d ",num_lines);
						// Encountered a DL statement : Update symbol table
						else if(Op[0] == 4){
							// DC statement
							if(Op[1]==1){
								// Write Symbol in symbol table with the approproiate size
								temp = check_update_symbol_table(symbol_table,maintain_symbol);
			   					LC = insert_address_symbol_table(symbol_table,temp,LC,1);
							}
		   					// Write mnemonic in IC file
							LC = write_mnemonic(write_IC, Op, buffer1D,verbose,LC);
						}
						else{
							// Write address of label in Symbol table
							temp = check_update_symbol_table(symbol_table,maintain_symbol);
							LC = insert_address_symbol_table(symbol_table,temp,LC,1);
		   					// Write mnemonic in IC file
							LC = write_mnemonic(write_IC, Op, buffer1D,verbose,LC);							
						}
					}
					// IS class preceded : Process Operand
					else if(Op[0] == 2){
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
							else if(Op[0] == 8){
								printf("\n [ERROR] LITERALS not allowed in 1st OPERANDS :: LINE NUMBER %d ",num_lines);
							}	
							
						}
					}
					// AD class preceded : Process Operand
					else if(Op[0] == 3){
						// Opcode wise Operand selection (Initialize IC with START, Skip END)
						if(Op[1] == 1){
							check_operand(Op, buffer1D);
							if(Op[0] == 5 || Op[0] == 6){
								printf("\n [ERROR] START Assembler Directive cannot use REGISTERS or SYMBOLS :: LINE NUMBER %d ",num_lines);
							}
							else if(Op[0] == 7){
								LC = atoi(buffer1D);
								// Write constant
								write_constant(write_IC, buffer1D, verbose);
							}
						}
						else if(Op[1] == 2){
							printf("\n [ERROR] END cannot have operands :: LINE NUMBER %d ",num_lines);
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
								printf("\n [ERROR] ASSEMBLER DIRECTIVES cannot use REGISTER :: LINE NUMBER %d ",num_lines);
							}
							else if(Op[0] == 7){
								// Write constant
								write_constant(write_IC, buffer1D, verbose);
							}
						}
					}										
				}
				// 3rd word in line
				else if(count == 2){
					// Process Operand
					if(Op[0] == 2){
						// Opcode wise Operand selection
						//if(Op[0] == 2){
							check_operand(Op, buffer1D);
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
					}
					else if(Op[0] == 5){
						// 1st Operand is Symbol
						check_operand(Op, buffer1D);
						if(Op[0] == 5){
							printf("\n [ERROR] OPERANDS cannot be both symbols :: LINE NUMBER %d ",num_lines);
						}
						else if(Op[0] == 6){
							// Write register in file
							write_register(write_IC, Op, buffer1D, verbose);
						}
						else if(Op[0] == 7){
							// Write constant
							printf("\n [ERROR] CONSTANT and SYMBOL cannot be used both at a time as OPERANDS :: LINE NUMBER %d ",num_lines);
						}
						else if(Op[0] == 8){
							// Write literal
							printf("\n [ERROR] LITERAL and SYMBOL cannot be used both at a time as OPERANDS :: LINE NUMBER %d ",num_lines);
						}
					}					
					else if(Op[0] == 6){
						// 1st Operand is Register
						check_operand(Op, buffer1D);
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
						else if(Op[0] == 8){
							// Write literal
							update_literal_data(literal_pool,literal_table,buffer1D);
//							sprintf(buffer1D,"%d",temp);
//							write_litral(write_IC, buffer1D, verbose);
						}
					}					
					else if(Op[0] == 7){
						// 1st Operand is Constant
						check_operand(Op, buffer1D);
						if(Op[0] == 5){
							printf("\n [ERROR] CONTANT and SYMBOL cannot be used both at a time as OPERANDS :: LINE NUMBER %d ",num_lines);
						}
						else if(Op[0] == 6){
							// Write register in file
							write_register(write_IC, Op, buffer1D, verbose);
						}
						else if(Op[0] == 7){
							// Write constant
							printf("\n [ERROR] OPERANDS cannot be both CONTANTS :: LINE NUMBER %d ",num_lines);
						}					
						else if(Op[0] == 8){
							// Write literal
							printf("\n [ERROR] LITERAL and CONSTANT cannot be used both at a time as OPERANDS :: LINE NUMBER %d ",num_lines);
						}
	
					}	
					else if(Op[0] == 3){
						// AD	   
					}
					else if(Op[0] == 4){
	   					// DL statement
	   					if(Op[1]==2){
		   					check_operand(Op, buffer1D);
		   					if(Op[0] == 5){
		   						// Symbols not allowed
								printf("\n [ERROR] Symbol as operand not allowed in DL statement :: LINE NUMBER %d ",num_lines);
							}
							else if(Op[0] == 6){
								// Register not allowed
								printf("\n [ERROR] Register not allowed in DL statement :: LINE NUMBER %d ",num_lines);
							}
							else if(Op[0] == 7){
								// Constant size
								temp = check_update_symbol_table(symbol_table,maintain_symbol);
			   					LC = insert_address_symbol_table(symbol_table,temp,LC,atoi(buffer1D));
							}
						}
						/*else if(Op[1]==1){
		   					check_operand(Op, buffer1D);
		   					if(Op[0] == 5){
		   						// Symbols not allowed
								printf("\n [ERROR] Symbol as operand not allowed in DL statement :: LINE NUMBER %d ",num_lines);
							}
							else if(Op[0] == 6){
								// Register not allowed
								printf("\n [ERROR] Register not allowed in DL statement :: LINE NUMBER %d ",num_lines);
							}
							else if(Op[0] == 7){
								// Constant size
								temp = check_update_symbol_table(symbol_table,maintain_symbol);
			   					LC = insert_address_symbol_table(symbol_table,temp,LC,atoi(buffer1D));
							}
						}*/
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

	// store Literal Pool, Literal table and Pool Tab in file
	for(i=0;literal_pool[i][0];i++)
		fprintf(write_literal_file,"%s",literal_pool[i]);

	fprintf(write_literal_file,"\n\n");
	for(i=0;literal_table[i][0];i++)
		fprintf(write_literal_file,"%s",literal_table[i]);

	fprintf(write_literal_file,"\n\n");
	for(i=0;pool_tab[i][0];i++)
		fprintf(write_literal_file,"%s",pool_tab[i]);

	fclose(read_program);
	fclose(write_symbol_file);
	fclose(write_IC);
}
