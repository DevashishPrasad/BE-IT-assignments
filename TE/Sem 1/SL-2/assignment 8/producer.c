// gcc producer.c -o pro.out

// Include header files
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
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

	// Start writing to the shared memory
	while(running) {
		while(shared_stuff->written_by_you == 1) {
			sleep(1);
			printf("waiting for client...\n");
		}
		printf("Enter some text: ");
		fgets(buffer, BUFSIZ, stdin);
		strncpy(shared_stuff->some_text, buffer, TEXT_SZ);
		shared_stuff->written_by_you = 1;
		
		// Magic string end to stop the program		
		if (strncmp(buffer, "end", 3) == 0) {
			running = 0;
		}
	}

	// Shared memory is detached and then deleted
	if (shmdt(shared_memory) == -1) {
		fprintf(stderr, "shmdt failed\n");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
