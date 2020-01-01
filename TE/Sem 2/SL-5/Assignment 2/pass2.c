#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char buffer2D[4][10];

// custom function to split strings
void split(char *str,char sep){
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

void main(int argc, char *argv[]){
	if(argc != 2){
		printf("\n [ERROR] Please specify input program file \n\n");
		return;
	}
	
	printf("=========================== 2 PASS ASSEMBLER ==========================");

	// Variables for the program
	FILE *write_IC, *read_keywords, *read_program, *write_symbol;
	char ch, buffer1D[400], IS[10][8], DL[2][4], AD[5][8], REG[4][5];
	int num_chars = 0, num_spaces = 0, num_lines = 0,num_keywords[32], i, j, flg;

	// Open the keywords file for reading
	read_keywords = fopen("keywords.txt","r");
			
	// Populate the keywords array IS, DS, AD, REG
	printf("\n [INFO] Initializing keywords in all arrays IS, DL, AD, REG");	
	flg=1;
	for(j=0;flg!=-1;j++){
		flg = fscanf(read_keywords,"%s",buffer1D); 
		if(j<=12)
			strcpy(IS[j],buffer1D);
		else if(j<=17)
			strcpy(AD[j-12],buffer1D);
		else if(j<=19)
			strcpy(DL[j-17],buffer1D);
		else 
			strcpy(REG[j-19],buffer1D);
	}
		
	fclose(read_keywords);	
	
	printf("\n [INFO] Initializing Symbol table and IC");
	// Open the input program file for reading
	read_program = fopen(argv[1],"r");
	split(argv[1],'.');
	strcat(buffer2D[0],"_");
	// Creating and opening the file for writing symbol table
	write_symbol = fopen(strcat(buffer2D[0],"symbol_table.txt"),"w");
	
	
    if(read_fp == NULL){ 
	// Check if this filePointer is null 
    // which maybe if the file does not exist 
        printf("\n [ERROR] Unable to open file %s ",argv[1]);
        return; 
    }
    else
    {                
		printf("\n [INFO] Reading the input program ");	    
		// Read character by character
        ch = fgetc(read_fp);
 
 		i = 0;
 		               
        // Reading the data using fgets() method 
        while(ch != EOF) 
        { 
            // Print the data  
             printf("%c",ch); 

			// Writing to a file
			// fputc(ch,write_fp);
			
			// Count number of characters
			if(isalpha(ch))
				num_chars++;
			if(ch == ' ')
				num_spaces++;
			if(ch == '\n'){
				num_lines++;
				flg = 0;
				char *ptr;
				// Search the line for keywords
				for(j=0;j<12;j++){
					*ptr = strstr(buffer1D, IS[j]);
					if (ptr != NULL){
						flg = 1;
						break;
					}	
				}
				for(j=0;j<5 && flg==0;j++){
					*ptr = strstr(buffer1D, AD[j]);
					if (ptr != NULL){
						flg = 1;
						break;
					}	
				}
				for(j=0;j<2 && flg==0;j++){
					*ptr = strstr(buffer1D, IS[j]);
					if (ptr != NULL){
						flg = 1;
						break;
					}	
				}
				for(j=0;j<4 && flg==0;j++){
					*ptr = strstr(buffer1D, IS[j]);
					if (ptr != NULL){
						flg = 1;
						break;
					}	
				}
				for(j=0;buffer1D[j];j++)
					buffer1D[j] = '-';
				if(flg == 0)
					printf("[ERROR] Missing Mnemonics on line number %d ",num_lines);
				i=0;
			}
			else{
				// Put character in buffer
				buffer1D[i] = ch;
				i++;
			}
			// Read character by character
          	ch = fgetc(read_fp);
        } 
        
        // Print the file statistics
        printf("\nNumber of Characters in the file - %d",num_chars);
        printf("\nNumber of Spaces in the file - %d",num_spaces);        
        printf("\nNumber of Lines in the file - %d\n",num_lines);        
        // print keywords stats
        /*for(j=0;j<32;j++)
	        printf("\n%s --> %d ",num_keywords[j],num_keywords[j]);*/
    }

	fclose(read_program);
	fclose(write_symbol);	
}
