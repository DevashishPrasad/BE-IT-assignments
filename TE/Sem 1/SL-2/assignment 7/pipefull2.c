
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
    int fd1; 
  
    // FIFO file path 
    char * myfifo1 = "/tmp/myfifo1";
    char * myfifo2 = "/tmp/myfifo2";  
  
    // Creating the named file(FIFO) 
    // mkfifo(<pathname>,<permission>) 
    mkfifo(myfifo1, 0666); 
    mkfifo(myfifo2, 0666);
  
    char str1[80], str2[80]; 
    while (1) 
    { 
        // First open in read only and read 
        fd1 = open(myfifo1,O_RDONLY); 
        read(fd1, str1, 80); 
  
        // Print the read string and close 
        printf("User1: %s\n", str1); 
        close(fd1); 
  
        // Now open in write mode and write 
        // string taken from user. 
        fd1 = open(myfifo2,O_WRONLY); 
        fgets(str2, 80, stdin); 
        write(fd1, str2, strlen(str2)+1); 
        close(fd1); 
    } 
    return 0; 
} 

