// gcc consumer.c -o con.out

// Include header files
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
	// Variable to store identifier of shared memory
	int shmid;
	
	srand((unsigned int)getpid());
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
	shared_stuff->written_by_you = 0;

	// Start reading from the shared memory
	while(running) {
		if (shared_stuff->written_by_you) {
			printf("You wrote: %s", shared_stuff->some_text);
			sleep( rand() % 4 ); /* make the other process wait for us ! */
			shared_stuff->written_by_you = 0;
			
			// Magic string end to stop the program
			if (strncmp(shared_stuff->some_text, "end", 3) == 0) {
				running = 0;
			}
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
