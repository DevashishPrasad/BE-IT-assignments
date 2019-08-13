// gcc dining_philosopher.c -lpthread -o dp.out

#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <math.h>
#include <pthread.h>

// Number of philosophers
#define N 5

// States of philosophers
enum {EATING, HUNGRY, THINKING} states[N];

// Mutex locks
pthread_mutex_t lock;

// Semaphores for chopsticks
sem_t fork[N];

// Thread function for philosopher 
void *philosopher(void *no);

// Other functions
void takefork(int i);
void putfork(int i);
void test(int i);
void think(int i);
void eat(int i);

// Main function
void main(){
	
	// Declare the variables for the program
	int res,nord,nowrt,i;
	int *arg;
	printf("\n ================= CLASSICAL PROBLEM OF DINING PHILOSOPHERS ==================");

	// Create threads
	pthread_t philosophers;

	// Initialize the Mutexes;
	res = pthread_mutex_init(&lock, NULL);
	if (res != 0) {
		printf("\n ERROR :: Mutex initialization failed");
		printf("\n ERROR :: Failed to proceed");
		exit(EXIT_FAILURE);
	}
	// Initialize the semapahores;
	for(i=0;i<N;i++){
		res =  sem_init(&fork[i], 0, 1);
		if (res != 0) {
			printf("\n ERROR :: Semaphore initialization failed");
			printf("\n ERROR :: Failed to proceed");
			exit(EXIT_FAILURE);
		}
	}
	
	// Create philosopher threads
	printf("\n Creating Philosopher Threads");
	for(i=0;i<=N;i++){		
		printf("\n Creating Philosopher number [%d] ",i);
		arg = (int *) malloc(sizeof(int));
		*arg = i;
		res = pthread_create(&philosophers,NULL,philosopher,arg);
		if (res != 0) {
			printf("\n ERROR :: Thread Creation failed for Philosopher number [%d]",i);
			printf("\n ERROR :: Failed to proceed");
			exit(EXIT_FAILURE);
		}	
	}
	
	// Waiting for the threads to finish
	res = pthread_join(philosophers, NULL);		
	if (res != 0) {
		printf("\n ERROR :: Thread Waiting failed");
		printf("\n ERROR :: Failed to proceed");
		exit(EXIT_FAILURE);
	}	
}

// Function for the Philosopher thread
void *philosopher(void *no){
	int *num = (int*) no;
	while(1){
		think();
		takefork();
		Eat();
		putfork();
	}	
}

// Function for Think
void *think(){
	int temp = rand()%2,i;
	if (temp == 0)
		temp = 2;
	sleep(temp);
}

