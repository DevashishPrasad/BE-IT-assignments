// gcc employee.c -o emp.out

// Include header files
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
extern int errno; 

struct employee{
	char name[30]; 	
	int id, salary;
};
// Main function
int main()
{
	int choice;
	int fd, sz;
	char *buf = (char *) calloc(100, sizeof(char)); 
	struct employee emp;
		
	printf("\n ============================================");
	printf("\n |                   MENU                   |");
	printf("\n ============================================");
	printf("\n | 1. Add record                            |");		
	printf("\n | 2. Remove record                         |");
	printf("\n | 3. Update record                         |");	
	printf("\n | 4. View records                          |");	
	printf("\n ============================================");	
	printf("\n Enter your choice - ");
	scanf("%d",&choice);
	
	switch(choice){
		case 1:
			printf("\n Enter the name of the employee -> ");
			scanf("%s",&emp.name);
			printf("\n Enter the id of the employee -> ");
			scanf("%s",&emp.id);			
			printf("\n Enter the salary of the employee -> ");
			scanf("%s",&emp.slaray);
			sz = write(fd, "hello gais\n", strlen("hello gais\n"));
			break;
		case 2:
			printf("\n Enter the id of the employee -> ");
			scanf("%s",&emp.id);			
			printf("\n Enter the salary of the employee -> ");
			scanf("%s",&emp.slaray);			
			break;			
		default:
			printf("\n Please Enter a valid choice");
	}	
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
