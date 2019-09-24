
// C program to implement one side of FIFO 
// This side reads first, then reads 
#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
int main() 
{ 
    int fd1,sen,wor; 
  
    // FIFO file path 
    char * myfifo = "/tmp/myfifo"; 
  
    // Creating the named file(FIFO) 
    // mkfifo(<pathname>,<permission>) 
    mkfifo(myfifo, 0666); 
  
    char str1[180], str2[180]; 
    while (1) 
    { 
        // First open in read only and read 
        fd1 = open(myfifo,O_RDONLY); 
        read(fd1, str1, 180); 
  
        // Print the read string and close 
        printf("User1: %s\n", str1); 
        close(fd1); 
        
        // Counting sentences and words
        sen = 0;
        wor = 0;
        
        for(int i = 0; str1[i] != '\0'; i++){
        	if(str1[i] == ' ')
        		wor++;
        	if(str1[i] == '.')
        		sen++;
        }
        
        sprintf(str2,"Words : %d Sentences : %d",wor,sen);
				
        // Now open in write mode and write 
        // string taken from user. 
        fd1 = open(myfifo,O_WRONLY); 
		scanf("\n");
        write(fd1, str2, strlen(str2)+1); 
        close(fd1); 
    }
     
    return 0; 
} 

