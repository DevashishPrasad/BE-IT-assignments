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

	char filename[BUFFER_SIZE] = "thefile.txt";
	char read_msg[BUFFER_SIZE];
	int fd[2],fd1[2];
	FILE * filePointer; 
	pid_t pid;
	
	/* create the pipes */
	if (pipe(fd) == -1) {
		fprintf(stderr,"Pipe failed");
		return 1;
	}
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

		// WRITE
		// close the unused end of the pipe 
		close(fd[READ_END]);
		// write to the pipe 
		write(fd[WRITE_END], filename, strlen(filename)+1);
		// close the write end of the pipe 
		close(fd[WRITE_END]);
		printf("\n Parent sent the filename to the child !");
		
		sleep(2);

		/*
		// READ
		// close the unused end of the pipe 
		close(fd[WRITE_END]);
		// read from the pipe 
		read(fd[READ_END], read_msg, BUFFER_SIZE);
		printf("\nparent read %s",read_msg);
		// close the write end of the pipe 
		close(fd[READ_END]);
		*/
		wait(NULL);
	}
	else { 
		/* child process */

		sleep(1);
		
		// READ
		// close the unused end of the pipe 
		close(fd1[WRITE_END]);
		// read from the pipe 
		read(fd1[READ_END], read_msg, BUFFER_SIZE);
		printf("\n Child read the filename as %s ",read_msg);
		// close the write end of the pipe 
		close(fd1[READ_END]);
		
		// File handling by child
		fprintf(filePointer, "%s", "This is some random data written by child");		
		/*
		// WRITE
		// close the unused end of the pipe 
		close(fd[READ_END]);
		// write to the pipe 
		write(fd[WRITE_END], child_msg, strlen(child_msg)+1);
		// close the write end of the pipe 
		close(fd[WRITE_END]);	*/
	}

	return 0;
}
