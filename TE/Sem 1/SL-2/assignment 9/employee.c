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
	int fd, sz, choice, cnt;
	char *buf = (char *) calloc(100, sizeof(char)); 
	char c;
	struct employee emp;

	printf("\n Using file -> thefile.txt with file descriptor number -> %d", fd); 
		
	while(1){
		printf("\n ============================================");
		printf("\n |                   MENU                   |");
		printf("\n ============================================");
		printf("\n | 1. Add record                            |");		
		printf("\n | 2. Remove record                         |");
		printf("\n | 3. Update record                         |");	
		printf("\n | 4. View records                          |");	
		printf("\n | 5. Exit                                  |");		
		printf("\n ============================================");	
		printf("\n Enter your choice - ");
		scanf("%d",&choice);
	
		switch(choice){
			case 1:
				// Take input from user
				printf("\n Enter the name of the employee -> ");
				scanf("%s",&emp.name);
				printf("\n Enter the id of the employee -> ");
				scanf("%d",&emp.id);			
				printf("\n Enter the salary of the employee -> ");
				scanf("%d",&emp.salary);
			
				// Open the file
				fd = open("thefile.txt", O_WRONLY | O_APPEND);  
			
				// Insert the record
				sz = write(fd, emp.name, strlen(emp.name));
				sz = write(fd, "\t", strlen("\t"));
				sprintf(buf, "%d", emp.id);
				sz = write(fd, buf, strlen(buf));
				sz = write(fd, "\t", strlen("\t"));				
				sprintf(buf, "%d", emp.salary);			
				sz = write(fd, buf, strlen(buf));	
				sz = write(fd, "\n", strlen("\n"));				
						
				printf("\n Record was written successfully");
				break;
			case 2:
				printf("\n Enter the id of the employee -> ");
				scanf("%d",&emp.id);		
				
				fd = open("thefile.txt", O_RDONLY);
				
				cnt = 0;
				
				while(1){
					c = read(fd,&c,1);
					if(c == '\n')
						cnt = 0;
					if(c == '\t')
						cnt++;
					if(cnt == 1)
						printf("%c",c);
				}
				
				break;			
			case 3:
				printf("\n Enter the id of the employee -> ");
				scanf("%d",&emp.id);			
				break;
			case 4:
				// Open the file
				fd = open("thefile.txt", O_RDONLY);
				printf("\n Name\tid\tsalary\n");
				while(read(fd,&c,1))
					printf("%c",c);
				break;
			case 5:
				exit(0);
			default:
				printf("\n Please Enter a valid choice");
		}	
	}	
	return 0; 
}
