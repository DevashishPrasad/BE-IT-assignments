// gcc file_handling.c -o fh.out

// Include header files
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
extern int errno; 
// Main function
int main()
{
	int fd, sz; 
	char *c = (char *) calloc(100, sizeof(char)); 
	
	// if file is not in directory  
	// then file foo.txt is created. 
	fd = open("foo.txt", O_RDWR | O_CREAT);  

	printf("fd = %d\n", fd); 

	if (fd <-1){ 
		// print which type of error have in a code 
		printf("Error Number % d\n", errno);  
		// print program detail "Success or failure" 
		perror("Program");                 
		exit(1); 
	} 
	
	sz = read(fd, c, 20);
	 
	printf("called read(%d, c, 10).  returned that"
	 " %d bytes  were read.\n", fd, sz); 
	c[sz] = '\0'; 
	printf("Those bytes are as follows: %s\n", c); 

	sz = write(fd, "hello gais\n", strlen("hello gais\n")); 
	
	if (close(fd) < 0){
		perror("c1"); 
		exit(1); 
	}  
	printf("closed the fd\n"); 
	return 0; 
}
