#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

void main(){

	printf("===========================  File Input Output Program ==========================");

	// Variables for the program
	FILE *read_fp, *write_fp, *read_keywords;
	char ch, buffer[400], keywords[10][10];
	int num_chars = 0,num_spaces = 0,num_lines = 0, num_keywords[10],i,j,flg=0;
	
	// Initialize the array
	for(j=0;j<10;j++)
		num_keywords[j] = 0;
		
	// Open the keywords file for reading
	read_keywords = fopen("keywords.txt","r");

	// Populate the keywords array
	for(j=0;j<32;j++){
		fscanf(read_keywords,"%s",buffer);
		strcpy(keywords[j],buffer);
	}
		
	fclose(read_keywords);	

	// Open the file for reading
	read_fp = fopen("prog.asm","r");
	// Open the file for reading
	write_fp = fopen("output.txt","w");
	
	// Check if this filePointer is null 
    // which maybe if the file does not exist 
    if(read_fp == NULL) 
        printf( "file_ip_op.c file failed to open." ) ; 
    else
    { 
        printf("\n\nData from file :  \n\n"); 
                
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
			if(ch == ' '){
				num_spaces++;
			}	
			if(ch == '\n'){
				if(buffer[0] == '-')
					break;
				flg = 0;
				num_lines++;
				// Search the line for keywords
				for(j=0;j<10;j++){
					char *ptr = strstr(buffer, keywords[j]);
					if (ptr != NULL){
						num_keywords[j]++;
						ptr = strchr(buffer, ' ');
						//for(j=0;j<10;j++){
						flg = 1;
					}
				}
				if(flg == 0){
					printf("\n[INFO] ERROR on line number %d : Keyword not found",num_lines);
					break;
				}
				
				for(j=0;buffer[j];j++)
					buffer[j] = '-';
				i=0;
			}
		
			// Put character in buffer
			buffer[i] = ch;
			i++;
		
			// Read character by character
          	ch = fgetc(read_fp);
        } 
 
 		printf("\n[INFO] No ERRORS found\n");       
        // Print the file statistics
        fprintf(write_fp,"\n Number of Characters in the file : %d",num_chars);
        fprintf(write_fp,"\n Number of Spaces in the file : %d",num_spaces);        
        fprintf(write_fp,"\n Number of Lines in the file : %d",num_lines);        
        // print keywords stats
        for(j=0;j<10;j++)
	        fprintf(write_fp,"\n%s : %d ",keywords[j],num_keywords[j]);
    }

	fclose(read_fp);
	fclose(write_fp);	
}