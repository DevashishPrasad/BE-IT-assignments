// gcc reader_writer_mutex.c -lpthread -o rw.out

#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <math.h>
#include <pthread.h>

// Mutex locks
pthread_mutex_t rwlock,lock;

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
	
	// Initialize the Mutexes;
	res =  pthread_mutex_init(&rwlock, NULL);
	if (res != 0) {
		printf("\n ERROR :: Semaphore initialization failed");
		printf("\n ERROR :: Failed to proceed");
		exit(EXIT_FAILURE);
	}
	res = pthread_mutex_init(&lock, NULL);
	if (res != 0) {
		printf("\n ERROR :: Mutex initialization failed");
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
		int temp = rand()%2,i;
		if (temp == 0)
			temp = 2;
		sleep(temp);

		pthread_mutex_lock(&lock);
			// Critical section for readers
			readcount++;
			if(readcount == 1)		
				pthread_mutex_lock(&rwlock);
		pthread_mutex_unlock(&lock);

		// The critical section for reader and writers
		printf("\n\n\n R : Entered in READER no <%d> ",*num);
		// Read the data
		temp = data;
		printf("\n R : DATA => %d ",temp);
		printf("\n R : Exited from READER no <%d> ",*num);

		pthread_mutex_lock(&lock);
			// Critical section for readers
			readcount--;
			if(readcount == 0)		
				pthread_mutex_unlock(&rwlock);
		pthread_mutex_unlock(&lock);
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

		pthread_mutex_lock(&rwlock);
			// The Critical section for readers ad writers
			printf("\n\n\n W : Entered in WRITER  no <%d> ",*num);
			// Write the data
			data = temp * 12;
			printf("\n W : The data was changed");		
			printf("\n W : Exited from WRITER no <%d> ",*num);
		pthread_mutex_unlock(&rwlock);		
		// Remainder section
	}	
}

