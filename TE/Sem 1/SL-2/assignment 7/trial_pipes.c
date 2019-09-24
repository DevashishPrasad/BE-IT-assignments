// gcc trial_pipes.c -o tp.out
#include<sys/types.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(void){

	char child_msg[BUFFER_SIZE] = "Hello";
	char parent_msg[BUFFER_SIZE] = "Hi there!";
	char read_msg[BUFFER_SIZE];
	int fd[2],fd1[2];
	pid_t pid;
	
	/* create the pipes */
	if (pipe(fd) == -1) {
		fprintf(stderr,"Pipe failed");
		return 1;
	}
	/* create the pipes */
	if (pipe(fd1) == -1) {
		fprintf(stderr,"Pipe failed");
		return 1;
	}
	
	/* fork a child process */
	pid = fork();
	if (pid < 0) { 
		/* error occurred */
		fprintf(stderr, "Fork Failed");
		return 1;
	}
	if (pid > 0) { 
		/* parent process */

		sleep(2);
		// READ
		/* close the unused end of the pipe */
		close(fd[WRITE_END]);
		/* read from the pipe */
		read(fd[READ_END], read_msg, BUFFER_SIZE);
		printf("\nparent read %s",read_msg);
		/* close the write end of the pipe */
		close(fd[READ_END]);

		// WRITE
		// close the unused end of the pipe 
		close(fd1[READ_END]);
		// write to the pipe 
		write(fd1[WRITE_END], parent_msg, strlen(parent_msg)+1);
		// close the write end of the pipe 
		close(fd1[WRITE_END]);
		printf("\ndone");
		wait(NULL);

	}
	else { 
		/* child process */

		// WRITE
		/* close the unused end of the pipe */
		close(fd[READ_END]);
		/* write to the pipe */
		write(fd[WRITE_END], child_msg, strlen(child_msg)+1);
		/* close the write end of the pipe */
		close(fd[WRITE_END]);

		sleep(4);
		
		// READ
		// close the unused end of the pipe 
		close(fd1[WRITE_END]);
		// read from the pipe 
		read(fd1[READ_END], read_msg, BUFFER_SIZE);
		printf("\nchild read %s",read_msg);
		// close the write end of the pipe 
		close(fd1[READ_END]);

	}

	return 0;
}
