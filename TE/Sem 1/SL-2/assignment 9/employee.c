// gcc employee.c -o emp.out

// Include header files
#include <stdlib.h>
#include <stdio.h>
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
	int fd, sz, choice, cnt, ibuf, id, tfd, sbuf,wrt;
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
		printf("\n | 4. Search record                         |");	
		printf("\n | 5. View records                          |");	
		printf("\n | 6. Exit                                  |");		
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
				sprintf(buf, "%d\t%s\t%d\n", emp.id, emp.name, emp.salary);
				sz = write(fd, buf, strlen(buf));
						
				printf("\n Record was written successfully");
				break;
			case 2:
				// Remove record
				printf("\n Enter the id of the employee -> ");
				scanf("%d",&emp.id);		
				
				fd = open("thefile.txt", O_RDONLY);
				tfd = open("temp.txt", O_WRONLY | O_CREAT);
				cnt = 0;
				emp.salary=0;
				emp.name[0]='\0';
				ibuf=0;
				sbuf=0;
				id=0;
				wrt=0;
				while(read(fd,&c,1)){
					if(c != '\n'){
						if(c == '\t'){
							cnt++;
							continue;
						}
						if(cnt==0){
							ibuf = atoi(&c);
							id += ibuf;
							id *= 10;
						}	
						if(cnt==1){
							if((id/10) == emp.id){
								wrt = 1;
							}
							strncat(emp.name,&c,1);
						}
						if(cnt==2){	
							sbuf = atoi(&c);
							emp.salary += sbuf;
							emp.salary *= 10;	
						}
					}
					else{
						cnt = 0;
						if(wrt==0){
							sprintf(buf, "%d\t%s\t%d\n", (id/10), emp.name, (emp.salary/10));
							sz = write(tfd, buf, strlen(buf));
						}
						emp.salary=0;
						emp.name[0]='\0';
						ibuf=0;
						sbuf=0;
						id=0;
						wrt = 0;
					}
				}
				rename("thefile.txt","temp2.txt");
				rename("temp.txt","thefile.txt");
				remove("temp2.txt");
				break;			
			case 3:
				// Update record
				printf("\n Enter the id of the employee -> ");
				scanf("%d",&emp.id);		
				
				fd = open("thefile.txt", O_RDONLY);
				tfd = open("temp.txt", O_WRONLY | O_CREAT);
				cnt = 0;
				emp.salary=0;
				emp.name[0]='\0';
				ibuf=0;
				sbuf=0;
				id=0;
				wrt=0;
				while(read(fd,&c,1)){
					if(c != '\n'){
						if(c == '\t'){
							cnt++;
							continue;
						}
						if(cnt==0){
							ibuf = atoi(&c);
							id += ibuf;
							if(id == emp.id){
								wrt = 1;
							}
							id *= 10;
						}	
						if(cnt==1)
							strncat(emp.name,&c,1);
						if(cnt==2){	
							sbuf = atoi(&c);
							emp.salary += sbuf;
							emp.salary *= 10;	
						}
					}
					else{
						cnt = 0;
						if(wrt==0){
							sprintf(buf, "%d\t%s\t%d\n", (id/10), emp.name, (emp.salary/10));
							sz = write(tfd, buf, strlen(buf));
						}
						else{
							printf("\n Enter new name of the employee -> ");
	                        scanf("%s",&emp.name);
	                        printf("\n Enter new id of the employee -> ");
	                        scanf("%d",&emp.id);			
	                        printf("\n Enter new salary of the employee -> ");
	                        scanf("%d",&emp.salary);						        
							sprintf(buf, "%d\t%s\t%d\n", emp.id, emp.name, emp.salary);
							sz = write(tfd, buf, strlen(buf));
						}
						emp.salary=0;
						emp.name[0]='\0';
						ibuf=0;
						sbuf=0;
						id=0;
						wrt = 0;
					}
				}
				rename("thefile.txt","temp2.txt");
				rename("temp.txt","thefile.txt");
				remove("temp2.txt");			
				break;
				
	        case 4:
		        // Search record
				printf("\n Enter the id of the employee -> ");
				scanf("%d",&emp.id);		
				
				fd = open("thefile.txt", O_RDONLY);
				cnt = 0;
				emp.salary=0;
				emp.name[0]='\0';
				ibuf=0;
				sbuf=0;
				id=0;
				wrt=0;
				while(read(fd,&c,1)){
					if(c != '\n'){
						if(c == '\t'){
							cnt++;
							continue;
						}
						if(cnt==0){
							ibuf = atoi(&c);
							id += ibuf;
							id *= 10;
						}	
						if(cnt==1){
							if((id/10) == emp.id)
								wrt = 1;
							strncat(emp.name,&c,1);
						}
						if(cnt==2){	
							sbuf = atoi(&c);
							emp.salary += sbuf;
							emp.salary *= 10;	
						}
					}
					else{
						if(wrt == 1){
						    printf("\n RECORD FOUND - ");
							printf("\n ID\tNAME\tSALARY\n");						    
							printf("\n%d\t%s\t%d\n", (id/10), emp.name, (emp.salary/10));
						}
						emp.salary=0;
						emp.name[0]='\0';
						ibuf=0;
						sbuf=0;
						id=0;
						wrt = 0;
						cnt = 0;
					}
				}	
		        break;
			case 5:
				// Open the file
				fd = open("thefile.txt", O_RDONLY | O_CREAT);
				printf("\n ID\tNAME\tSALARY\n");
				while(read(fd,&c,1))
					printf("%c",c);
				break;
			case 6:
				exit(0);
			default:
				printf("\n Please Enter a valid choice");
		}	
	}	
	return 0; 
}
