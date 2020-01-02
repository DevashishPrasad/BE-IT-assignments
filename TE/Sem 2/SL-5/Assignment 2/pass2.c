#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include<time.h>

// custom function to split strings
char** split(char **buffer2D, char *str,char sep){
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
	
	return buffer2D;
} 

char IS[12][8], DL[2][4], AD[5][8], REG[4][5];

int* check_operand(char *buf){
	int j;
	// Search for REG keyword
	/*for(j=0;j<4;j++){
		ptr = strstr(buf, REG[j]);
		if (ptr != NULL)
			return 5;
	}*/

}
int* check_mnemonics(int* Op, char *buf){
	int j;
	char *ptr;
	// Search the word for keywords
	// Search for IS keyword
	for(j=0;j<12;j++){
		ptr = strstr(buf, IS[j]);
		if (ptr != NULL){
			Op[0]=2;
			Op[1]=j;
			return Op;
		}
	}
	// Search for AD keyword	
	for(j=0;j<5;j++){
		ptr = strstr(buf, AD[j]);
		if (ptr != NULL){
			Op[0]=3;
			Op[1]=j+1;
			return Op;
		}
	}
	// Search for DL keyword	
	for(j=0;j<2;j++){
		ptr = strstr(buf, DL[j]);
		if (ptr != NULL){
			Op[0]=4;
			Op[1]=j+1;
			return Op;

		}
	}
	Op[0]=1;
	Op[1]=1;	
	return Op;
}

int* check_label(int* Op,char *buf){
	if(isalpha(buf[0])){
		Op[0]=1;
		Op[1]=1;	
		return Op;
	}
	Op[0]=0;
	Op[1]=0;	
	return Op;
}

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
		else 
			strcpy(REG[j-20],buffer1D);
	}
	
	if(verbose){
		printf("\n[INFO] IS array :");	
		for(i=0;i<12;i++)
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

	fclose(read_keywords);	
	
	if(verbose)
		printf("\n[INFO] Initializing Symbol table and IC");
	
	// Opening the input program file for reading
	read_program = fopen(argv[1],"r");
	buffer2D = split(buffer2D,argv[1],'.');
	strcat(buffer2D[0],"_");
	
	// Creating and opening the file for writing symbol table
	write_symbol = fopen(strcat(buffer2D[0],"symbol_table.txt"),"w");
	
	
    if(read_program == NULL){ 
		// Check if this filePointer is null 
		// which maybe if the file does not exist 
        printf("\n[ERROR] Unable to open program file %s ",argv[1]);
        return; 
    }
    else
    {    
    	if(verbose)            
			printf("\n[INFO] Reading the input program ");	    
	
		// Read character by character
        ch = fgetc(read_program);
 
 		i = 0;
 		               
        // Reading the data using fgets() method 
        while(ch != EOF) 
        { 
            // Print the data  
           	if(verbose)            
	            printf("%c",ch); 
			
			if(ch == ' '){
				i = 0;
				if(count == 0){
					Op = check_label(Op,buffer1D));
					if(Op[0] == 1){
						Op = check_mnemonics(Op,buffer1D));
						if(Op[0] != 1){
							fputc(write_symbol,'(');
							if(Op[0] == 2)
								fputs(write_symbol,"IS");
							if(Op[0] == 3)	
								fputs(write_symbol,"DL");
							if(Op[0] == 4)	
								fputs(write_symbol,"AD");
							fputs(write_symbol,",");
							sprintf(buffer1D,"%s",Op[1]);
							fputs(write_symbol,buffer1D);
						}
					}
					else if(Op[0] == 0)
						printf("[ERROR] Incorrect Mnemonics or Label on line number %d ",num_lines);
				}
				else if(count == 1){
					if(Op[0] == 1){
						Op = check_mnemonics(Op,buffer1D);
						if(Op[0] == 1)
							printf("[ERROR] Missing Mnemonics on line number %d ",num_lines);
					}
				}
				for(j=0;buffer1D[j];j++)
					buffer1D[j] = '-';
	
				count++;
			}
			if(ch == '\n'){
				count = 0;
				num_lines++;

				for(j=0;buffer1D[j];j++)
					buffer1D[j] = '-';

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
}
