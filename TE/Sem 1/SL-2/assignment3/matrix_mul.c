// gcc matrix_mul.c -lpthread
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

// function for thread
void *multiply(void *arg);
void *take_input1(void *arg);
void *take_input2(void *arg);
void *put_output(void *arg);


// message to be printed
int *A;
int *B;
int result[10][10];

int main() {
	// -----------------  Declare Variables -------------------------------
	// variable for result status of thread creation
	int res,r1,c1,r2,c2;
	// for taking result after joining
	void *thread_result;

	printf("\n Enter the number of rows for Matrix 1 - ");
	scanf("%d",&r1);
	printf("\n Enter the number of columns for Matrix 1 - ");
	scanf("%d",&c1);
	printf("\n Enter the number of rows for Matrix 2 - ");
	scanf("%d",&r2);
	printf("\n Enter the number of columns for Matrix 2 - ");
	scanf("%d",&c2);

	//declare matrices
	A =  (int *)malloc(r1 * c1 * sizeof(int));
	B =  (int *)malloc(r2 * c2 * sizeof(int));

	*(A + 0*c1 + 0)=2;
	*(B + 0*c1 + 0)=2;
	int * params[2];
	// declare the threads
	pthread_t TA[r1][c1];
	pthread_t TB[r2][c2];
	
	params[0] = (A + 0*c1 + 0);
	params[1] = (B + 0*c1 + 0);
	/*for(int i=0;i<r1;i++)
		for(int j=0;j<r2;j++)*/
			res = pthread_create(&TA[0][0], NULL, take_input1, (void *)params);
/*
	for (int i = 0; i <  r1; i++) {
	      	for (int j = 0; j < c1; j++)
        		printf(" %d ",*(A + i*c1 + j));
		printf("\n");
	}
/*
	// check for thread creation failure
	if (res != 0) {
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}
	// thread created successfully
	printf("Waiting for thread to finish...\n");
	// joining or waiting for thread to finish
	res = pthread_join(the_thread, &thread_result);
	// check for thread join failure
	if (res != 0) {
		perror("Thread join failed");
		exit(EXIT_FAILURE);
	}
	// thread joined successfully
	printf("Thread joined, it returned %s\n", (char *)thread_result);
	printf("Message is now %s\n", message);
	exit(EXIT_SUCCESS);*/
}

// function executed by the thread
void *multiply(void *arg) {
	/*printf("thread_function is running. Argument was %s\n", (char *)arg);
	sleep(3);
	strcpy(message, "Bye!");
	pthread_exit("Thank you for the CPU time");*/
}
void *take_input1(void *arg){
	printf("%d",(*(int*)arg[0] * *(int*)arg[1]));
	//memcpy(arg,6,sizeof(int*));
}
void *take_input2(void *arg){
	//memcpy(arg,2,sizeof(int));
}
