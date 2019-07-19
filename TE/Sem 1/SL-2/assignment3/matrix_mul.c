// gcc matrix_mul.c -lpthread
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

// structure for passing parameters
struct params{
	int i,j,c;
};

// function for thread
void *multiply(void *arg);

// Global Matrices for result
int *A,*B,*Result;

int main(){

	// -----------------  Declare Variables ------------------
	// variable for result status of thread creation
	int res,r1,c1,r2,c2,c,d;
	// structure for parameters
	struct params p;
	// declare the threads
	pthread_t *TA;
	

	// ------------------ Input from user --------------------
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
	for (c = 0; c < r1; c++)
		for (d = 0; d < c1; d++){
			printf("\n Enter element [%d][%d] - ",c,d);
			scanf("%d", (A + c*c1 + d));
		}
 
	printf("\n Enter elements of second matrix - \n");
	for (c = 0; c < r2; c++)
		for (d = 0; d < c2; d++){
 			printf("\n Enter element [%d][%d] - ",c,d);
			scanf("%d", (B + c*c1 + d));
		}

	// ------------------ Display Matrices --------------------------
	for (c = 0; c < r1; c++){ 
		for (d = 0; d <c1; d++)
			printf(" %d ",*(A+c*c2+d));
		printf("\n");
	}
	for (c = 0; c < r2; c++){ 
		for (d = 0; d <c2; d++)
			printf(" %d ",*(B+c*c2+d));
		printf("\n");
	}
	// ------------------ Multiply using threads --------------------
	for (c = 0; c < r1; c++) 
		for (d = 0; d <c2; d++){
			p.i=c;
			p.j=d;
			p.c=c2;
			res = pthread_create((TA+c*c2+d),NULL,multiply,&p);
			// check for thread creation failure
			if (res != 0) {
				perror("Thread creation failed");
				exit(EXIT_FAILURE);
			}
		}
	
	// ------------------ Wait for threads to finish ----------------
	printf(" Waiting for threads to finish...\n");
	// joining or waiting for thread to finish
	for (c = 0; c < r1; c++) 
		for (d = 0; d <c2; d++){
			printf(" %d %d \n",c,d);
			res = pthread_join(*(TA+c*c2+d), NULL);	
			// check for thread join failure
			if (res != 0) {
				perror("Thread join failed");
				exit(EXIT_FAILURE);
			}
		}
	printf(" Result of execution -\n");
	for (c = 0; c < r1; c++){ 
		for (d = 0; d <c2; d++)
			printf(" %d ",*(Result+c*c2+d));
		printf("\n");
	}
}

// function executed by the thread
void *multiply(void *arg) {
	int k;
	struct params *p = arg;
	printf("\n\n i=%d j=%d \n",p->i,p->j);
	*(Result + p->i*p->c + p->j)=0;
	for (k = 0; k < p->c; k++){
		printf(" k=%d\n",k);
		printf("\n a = %d b = %d",*(A + p->i*p->c + k),*(B + k*p->c + p->j));
		*(Result + p->i*p->c + p->j)+=*(A + p->i*p->c + k)**(B + k*p->c + p->j);
		printf("\n Result = %d",*(Result + p->i*p->c + p->j));
	}
	pthread_exit("Thank you for the CPU time");
}
