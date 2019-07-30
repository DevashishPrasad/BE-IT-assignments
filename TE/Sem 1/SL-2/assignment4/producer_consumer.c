// gcc producer_consumer.c -lpthread -o pc.out
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <math.h>
#include <pthread.h>
#define BUF_SIZE 5

// Counting Semaphores
sem_t empty,full;

// Mutex lock
pthread_mutex_t lock;

// Thread functions for producer and consumer 
void *producer_thread(void *no);
void *consumer_thread(void *no);

// The Buffer
int buffer[BUF_SIZE];

// Current Indices
int pidx,cidx;

// Main function
void main(){

	// Declare the variables for the program
	int res,nopro,nocon,i;
	int *arg;
	printf("\n ================== PRODUCER CONSUMER ====================");
	printf("\n Enter the number of PRODUCERS => ");
	scanf("%d",&nopro);
	printf("\n Enter the number of CONSUMERS => ");
	scanf("%d",&nocon);

	// Create threads
	pthread_t producer,consumer;
	
	// Initialize the semapahores;
	res =  sem_init(&empty, 0, BUF_SIZE);
	if (res != 0) {
		printf("\n ERROR :: Semaphore initialization failed");
		printf("\n ERROR :: Failed to proceed");
		exit(EXIT_FAILURE);
	}	
	res = sem_init(&full, 0, 0);
	if (res != 0) {
		printf("\n ERROR :: Semaphore initialization failed");
		printf("\n ERROR :: Failed to proceed");
		exit(EXIT_FAILURE);
	}	
	
	// Initalize Mutex
	res = pthread_mutex_init(&lock, NULL);
	if (res != 0) {
		printf("\n ERROR :: Mutex initialization failed");
		printf("\n ERROR :: Failed to proceed");
		exit(EXIT_FAILURE);
	}	

	// Initialize the indices
	pidx = 0;
	cidx = 0;
	
	// Create producers threads
	printf("\n Creating Producer Threads");
	for(i=1;i<=nopro;i++){		
		printf("\n Creating Producer number <%d> ",i);
		arg = (int *) malloc(sizeof(int));
		*arg = i;
		res = pthread_create(&producer,NULL,producer_thread,arg);
		if (res != 0) {
			printf("\n ERROR :: Thread Creation failed");
			printf("\n ERROR :: Failed to proceed");
			exit(EXIT_FAILURE);
		}	
	}
	// Create consumers threads	
	printf("\n Creating Consumer Threads");
	for(i=1;i<=nocon;i++){		
		printf("\n Creating Consumer number <%d> ",i);	
		arg = (int *) malloc(sizeof(int));
		*arg = i;
		res = pthread_create(&consumer,NULL,consumer_thread,arg);	
		if (res != 0) {
			printf("\n ERROR :: Thread Creation failed");
			printf("\n ERROR :: Failed to proceed");
			exit(EXIT_FAILURE);
		}	
	}
	
	// Waiting for both threads to finish
	res = pthread_join(producer, NULL);		
	if (res != 0) {
		printf("\n ERROR :: Thread Waiting failed");
		printf("\n ERROR :: Failed to proceed");
		exit(EXIT_FAILURE);
	}	
	res = pthread_join(consumer, NULL);		
	if (res != 0) {
		printf("\n ERROR :: Thread Waiting failed");
		printf("\n ERROR :: Failed to proceed");
		exit(EXIT_FAILURE);
	}	
}

void *producer_thread(void *no){
	int *num = (int*) no;
	while(1){
		// Entry section
		int temp = rand()%3,i;
		if (temp == 0)
			temp = 2;
		sleep(temp);
		sem_wait(&empty);
		pthread_mutex_lock(&lock);
		// The critical section
		printf("\n\n Entered in PRODUCER no <%d> ",*num);
		// Produce an item in buffer
		buffer[pidx] = temp;
		// Print the BUFFER
		printf("\n\n [ ");
		for(i=0;i<BUF_SIZE;i++)
			printf(" %d ",buffer[i]);
		printf(" ]");
		// Update the index value
		pidx = (pidx + 1)%BUF_SIZE;				
		printf("\n\n Exited from PRODUCERno <%d> ",*num);
		pthread_mutex_unlock(&lock);		
		sem_post(&full);		
		// Remainder section
	}	
}

void *consumer_thread(void *no){
	int *num = (int*) no;
	while(1){
		// Entry section
		int temp = rand()%7,i;
		if (temp == 0)
			temp = 2;
		sleep(temp);
		sem_wait(&full);
		pthread_mutex_lock(&lock);
		// Critical section
		printf("\n\n Entered in CONSUMER  no <%d> ",*num);
		// Consumer an item from the buffer
		buffer[cidx] = 0;		
		// Print the BUFFER
		printf("\n\n [ ");
		for(i=0;i<BUF_SIZE;i++)
			printf(" %d ",buffer[i]);
		printf(" ]");
		// Update the index value
		cidx = (cidx + 1)%BUF_SIZE;				
		printf("\n\n Exited from CONSUMER no <%d> ",*num);
		pthread_mutex_unlock(&lock);		
		sem_post(&empty);		
		// Remainder section
	}	
}
