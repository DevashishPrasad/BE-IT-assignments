// gcc pro2.c -o p2.out

// Include header files
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>		
#include "shm_com.h" // header file containing the structure of shared memory

// Main function
int main()
{
	// User defined flag
	int running = 1;
	// Null pointer
	void *shared_memory = (void *)0;
	// Instance of shared datastructure
	struct shared_use_st *shared_stuff;
	// Buffer for Writing
	char buffer[BUFSIZ];
	// Variable to store identifier of shared memory
	int shmid;
	// Other vartiables
	int choice;
	
	// Create the shared memory space
	shmid = shmget((key_t)1234, sizeof(struct shared_use_st), 0666 | IPC_CREAT);
	// Check the successful creation of the shared memory
	if (shmid == -1) {
		fprintf(stderr, "shmget failed\n");
		exit(EXIT_FAILURE);
	}
	
	// Attach the created shared memory
	shared_memory = shmat(shmid, (void *)0, 0);
	// Check the successful attachment of the shared memory
	if (shared_memory == (void *)-1) {
		fprintf(stderr, "shmat failed\n");
		exit(EXIT_FAILURE);
	}

	// Initialize the shared memory for usage
	printf("Memory attached at %X\n", (int)shared_memory);
	shared_stuff = (struct shared_use_st *)shared_memory;

	// Start using the shared memory
	while(running) {
		printf("\n Enter '1' to read and '2' to write and '3' to exit - ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("\n You wrote: %s", shared_stuff->some_text);
				break;
			case 2:
				printf("\n Enter the string to write - ");
				scanf("\n");				
				fgets(buffer, BUFSIZ, stdin);
				strncpy(shared_stuff->some_text, buffer, TEXT_SZ);
				break;
			case 3:
				running = 0;
				break;
			default:
				printf("\n ");
		}
	}

	// Shared memory is detached and then deleted
	if (shmdt(shared_memory) == -1) {
		fprintf(stderr, "shmdt failed\n");
		exit(EXIT_FAILURE);
	}
	if (shmctl(shmid, IPC_RMID, 0) == -1) {
		fprintf(stderr, "shmctl(IPC_RMID) failed\n");
		exit(EXIT_FAILURE);
	}
	
	exit(EXIT_SUCCESS);
}
