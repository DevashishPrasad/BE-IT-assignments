// gcc reader_writer_semaphore.c -lpthread -o rw.out

#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <math.h>
#include <pthread.h>

// Counting Semaphores
sem_t rwlock,mutex;

// We can also use Mutex lock instead of binary semaphore
/*// Mutex lock
pthread_mutex_t lock;*/

// Thread functions for reader and writer 
void *reader_thread(void *no);
void *writer_thread(void *no);

// The read count
int readcount;

// The shared data
int data;

// Main function
void main(){

	// Declare the variables for the program
	int res,nord,nowrt,i;
	int *arg;
	printf("\n ============== CLASSICAL PROBLEM OF READERS WRITERS ===============");
	printf("\n Enter the number of READERS => ");
	scanf("%d",&nord);
	printf("\n Enter the number of WRITERS => ");
	scanf("%d",&nowrt);

	// Create threads
	pthread_t reader,writer;
	
	// Initialize the semapahores;
	res =  sem_init(&rwlock, 0, 1);
	if (res != 0) {
		printf("\n ERROR :: Semaphore initialization failed");
		printf("\n ERROR :: Failed to proceed");
		exit(EXIT_FAILURE);
	}	
	res = sem_init(&mutex, 0, 1);
	if (res != 0) {
		printf("\n ERROR :: Semaphore initialization failed");
		printf("\n ERROR :: Failed to proceed");
		exit(EXIT_FAILURE);
	}	

	// Initialize the readcount
	readcount = 0;
	
	// Create read threads
	printf("\n Creating Reading Threads");
	for(i=1;i<=nord;i++){		
		printf("\n Creating Reader number <%d> ",i);
		arg = (int *) malloc(sizeof(int));
		*arg = i;
		res = pthread_create(&reader,NULL,reader_thread,arg);
		if (res != 0) {
			printf("\n ERROR :: Thread Creation failed");
			printf("\n ERROR :: Failed to proceed");
			exit(EXIT_FAILURE);
		}	
	}

	// Create writer threads	
	printf("\n Creating Writer Threads");
	for(i=1;i<=nowrt;i++){		
		printf("\n Creating Consumer number <%d> ",i);	
		arg = (int *) malloc(sizeof(int));
		*arg = i;
		res = pthread_create(&writer,NULL,writer_thread,arg);	
		if (res != 0) {
			printf("\n ERROR :: Thread Creation failed");
			printf("\n ERROR :: Failed to proceed");
			exit(EXIT_FAILURE);
		}	
	}
	
	// Waiting for the threads to finish
	res = pthread_join(reader, NULL);		
	if (res != 0) {
		printf("\n ERROR :: Thread Waiting failed");
		printf("\n ERROR :: Failed to proceed");
		exit(EXIT_FAILURE);
	}	
	res = pthread_join(writer, NULL);		
	if (res != 0) {
		printf("\n ERROR :: Thread Waiting failed");
		printf("\n ERROR :: Failed to proceed");
		exit(EXIT_FAILURE);
	}	
}

// Function for the reader thread
void *reader_thread(void *no){
	int *num = (int*) no;
	while(1){
		// Entry section
		int temp = rand()%4,i;
		if (temp == 0)
			temp = 2;
		sleep(temp);
		
		sem_wait(&mutex);
			// Critical section for readers
			readcount++;
			if(readcount == 1)		
				sem_wait(&rwlock);
		sem_post(&mutex);

		// The critical section for reader and writers
		printf("\n\n\n R <%d> : Entered in READER ",*num);
		// Read the data
		sleep(temp);
		temp = data;
		printf("\n R : DATA => %d ",temp);
		printf("\n R <%d> : Exited from READER ",*num);

		sem_wait(&mutex);
			// Critical section for readers
			readcount--;
			if(readcount == 0)		
				sem_post(&rwlock);
		sem_post(&mutex);
		// Remainder section
	}	
}

// Function for the writer thread
void *writer_thread(void *no){
	int *num = (int*) no;
	while(1){
		// Entry section
		int temp = rand()%7,i;
		if (temp == 0)
			temp = 2;
		sleep(temp);

		sem_wait(&rwlock);
			// The Critical section for readers ad writers
			printf("\n\n\n W <%d> : Entered in WRITER ",*num);
			// Write the data
			data = temp * 12;
			printf("\n W : The data was changed");		
			printf("\n W <%d> : Exited from WRITER ",*num);
		sem_post(&rwlock);		
		// Remainder section
	}	
}

