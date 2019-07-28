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
void *producer_thread();
void *consumer_thread();

// The Buffer
int buffer[BUF_SIZE];

// Current Index
int idx;

// Main function
void main(){

	// Declare the variables for the program
	int res;
	printf("\n ================== PRODUCER CONSUMER ====================");
		
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

	// Initialize the index
	idx = 0;
	
	// Create the threads
	printf("\n Creating a Producer");		
	res = pthread_create(&producer,NULL,producer_thread,NULL);
	if (res != 0) {
		printf("\n ERROR :: Thread Creation failed");
		printf("\n ERROR :: Failed to proceed");
		exit(EXIT_FAILURE);
	}	
	printf("\n Creating a Consumer");
	res = pthread_create(&consumer,NULL,consumer_thread,NULL);	
	if (res != 0) {
		printf("\n ERROR :: Thread Creation failed");
		printf("\n ERROR :: Failed to proceed");
		exit(EXIT_FAILURE);
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

void *producer_thread(){
	while(1){
		// Entry section
		int temp = rand()%10,i;
		sleep(temp);
		sem_wait(&empty);
		pthread_mutex_lock(&lock);
		// The critical section
		printf("\n\n Entered in PRODUCER");
		// Produce an item in buffer
		buffer[idx] = temp;
		// Print the BUFFER
		printf("\n\n [ ");
		for(i=0;i<BUF_SIZE;i++)
			printf(" %d ",buffer[i]);
		printf(" ]");
		// Update the index value
		idx = (idx + 1)%BUF_SIZE;				
		printf("\n\n Exited from PRODUCER");
		pthread_mutex_unlock(&lock);		
		sem_post(&full);		
		// Remainder section
	}	
}

void *consumer_thread(){
	while(1){
		// Entry section
		int temp = rand()%7,i;
		sleep(temp);
		sem_wait(&full);
		pthread_mutex_lock(&lock);
		// Critical section
		printf("\n\n Entered in CONSUMER");
		// Consumer an item from the buffer
		buffer[idx-1]=0;
		// Print the BUFFER
		printf("\n\n [ ");
		for(i=0;i<BUF_SIZE;i++)
			printf(" %d ",buffer[i]);
		printf(" ]");
		printf("\n\n Entered in CONSUMER");
		pthread_mutex_unlock(&lock);		
		sem_post(&empty);		
		// Remainder section
	}	
}

