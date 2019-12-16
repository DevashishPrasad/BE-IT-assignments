#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

void main(){

	printf("===========================  File Input Output Program ==========================");

	// Variables for the program
	FILE *read_fp, *write_fp;
	char ch, buffer[400], keywords[32][10] = { "auto", "break", "case", "char", "const", "continue",	"default", "do", "double", "else",
						 	"enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short",
						 	"signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", 
						 	"volatile", "while"};
	int num_chars = 0,num_spaces = 0,num_lines = 0, num_keywords[32],i,j;
	
	// Initialize the array
	for(j=0;j<32;j++)
		num_keywords[j] = 0;
		
	// Open the file for reading
	read_fp = fopen("file_ip_op.c","r");
	// Open the file for reading
	write_fp = fopen("output.c","w");
	
	// Check if this filePointer is null 
    // which maybe if the file does not exist 
    if(read_fp == NULL) 
        printf( "file_ip_op.c file failed to open." ) ; 
    else
    { 
        printf("\n The file is now opened.\n"); 

        printf("\n\n Data from file -->  \n\n"); 
                
		// Read character by character
        ch = fgetc(read_fp);  
 
 		i = 0;
 		               
        // Reading the data using fgets() method 
        while(ch != EOF) 
        { 
            // Print the data  
            printf("%c",ch); 

			// Writing to a file
			fputc(ch,write_fp);
			
			// Count number of characters
			if(isalpha(ch))
				num_chars++;
			if(ch == ' ')
				num_spaces++;
			if(ch == '\n'){
				num_lines++;
				// Search the line for keywords
				for(j=0;j<32;j++){
					char *ptr = strstr(buffer, keywords[j]);
					if (ptr != NULL)
						num_keywords[j]++;
				}
				for(j=0;buffer[j];j++)
					buffer[j] = '-';
				i=0;
			}
			else{
				// Put character in buffer
				buffer[i] = ch;
				i++;
			}
			// Read character by character
          	ch = fgetc(read_fp);
        } 
        
        // Print the file statistics
        fprintf(write_fp,"\nNumber of Characters in the file - %d",num_chars);
        fprintf(write_fp,"\nNumber of Spaces in the file - %d",num_spaces);        
        fprintf(write_fp,"\nNumber of Lines in the file - %d\n",num_lines);        
        // print keywords stats
        for(j=0;j<32;j++)
	        printf("\n%s --> %d ",keywords[j],num_keywords[j]);
    }

	fclose(read_fp);
}
