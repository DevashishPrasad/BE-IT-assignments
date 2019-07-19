// gcc matrix_mul.c -lpthread
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

// structure for passing parameters
struct params{
	int *a,*b;
};

// function for thread
void *multiply(void *arg);
void *take_input1(void *arg);
void *take_input2(void *arg);
void *put_output(void *arg);

int main() {
	// -----------------  Declare Variables ------------------
	// variable for result status of thread creation
	int res,r1,c1,r2,c2;
	// for taking result after joining
	void *thread_result;
	// Matrices	
	int *A;
	int *B;
	int *result;
	// structure for parameters
	struct params p;
	// declare the threads
	pthread_t *TA;
	
	// ------------------ input from user --------------------
	printf("\n Enter the number of rows for Matrix 1 - ");
	scanf("%d",&r1);
	printf("\n Enter the number of columns for Matrix 1 - ");
	scanf("%d",&c1);
	printf("\n Enter the number of rows for Matrix 2 - ");
	scanf("%d",&r2);
	printf("\n Enter the number of columns for Matrix 2 - ");
	scanf("%d",&c2);

	if (c1 != r2){
		printf("The matrices can't be multiplied with each other.\n");
		exit(0);
	}
	
	// allocate matrices
	A =  (int *)malloc(r1 * c1 * sizeof(int));
	B =  (int *)malloc(r2 * c2 * sizeof(int));
	Result = (int *)malloc(r1 * c2 * sizeof(int));
	TA = (pthread_t *)malloc(r1 * c2 * sizeof(pthread_t));
	
	printf("\n Enter elements of first matrix - \n");
	for (int r` = 0; c < r1; c++)
		for (int d = 0; d < c1; d++){
			printf("\n Enter element [%d][%d] - ",c,d);
			scanf("%d", (A + c*c1 + d));
		}
 
	printf("\n Enter elements of second matrix - \n");
	for (c = 0; c < r2; c++)
		for (d = 0; d < c2; d++){
 			printf("\n Enter element [%d][%d] - ",c,d);
			scanf("%d", (B + c*c1 + d));
		}

	// ------------------ Multiply using threads --------------------
	for (c = 0; c < r1; c++) 
		for (d = 0; d <c2; d++){ 
			for (k = 0; k < r1; k++) {
				p.a += (A + c*c1 + k);
				p.b += (B + k*c1 + d);
			}
		}
		
	
	for (int c = 0; c <  r1; c++) {
	      	for (int d = 0; d < c2; d++)
        			pthread_join(the_thread, (Result + c*c2 + d));
		printf("\n");
	}
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
