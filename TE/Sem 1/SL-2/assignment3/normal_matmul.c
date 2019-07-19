// gcc matrix_mul.c -lpthread
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>

// Global Matrices
int *A,*B,*Result;

int main(){

	// -----------------  Declare Variables ------------------
	// variable for result status of thread creation
	int res,r1,c1,r2,c2,c,d,k,t;
	// declare the threads
	pthread_t *TA;
	// clock
	clock_t start, end;	
	double totaltime;

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
	start = clock();
	for(t=0;t<100;t++){
		for (c = 0; c < r1; c++) 
			for (d = 0; d <c2; d++){
				for (k = 0; k < c1; k++){
					*(Result + c*c1 + d)+=*(A + c*c1 + k)**(B + k*c1 + d);
				}
			}
	}		
	// -------------------- Display the result --------------------
	printf(" Result of execution -\n");
	for (c = 0; c < r1; c++){ 
		for (d = 0; d <c2; d++)
			printf(" %d ",*(Result+c*c2+d));
		printf("\n");
	}
	
	end = clock();
	totaltime = ((double) (end - start)) / _SC_CLK_TCK;
	printf("\n Time for execution --> %f \n\n",totaltime);
}
