// COMPILE : gcc p_exec.c -o p_exec.out
// EXECUTE : ./p_exec.out

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

// Function to print the array on console
void print_arr(int arr[100],int n){
	int i;

	printf("\n Your array is - \n [ ");

	for(i=0; i<n-1; i++)
		printf(" %d, ",arr[i]);

	printf(" %d ]",arr[i]);
}

// Quick sort
void quick_sort(int arr[100],int first,int last){

    int i,j,k,pivot,cmp=0,swap=0,temp;

    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;

        while(i<j)
        {
            while(arr[i] <= arr[pivot] && i<last)
                i++;

            while(arr[j] > arr[pivot])
                j--;

            cmp++;
            if(i<j)
            {
                swap++;
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }

        temp=arr[pivot];
        arr[pivot]=arr[j];
        arr[j]=temp;

        quick_sort(arr,first,j-1);
        quick_sort(arr,j+1,last);
    }
}

void main(){

	// Declare the variables
	int arr[100],n;
	pid_t child;

	// The main process starts
	printf("\n This is the main process - ");
	printf("\n Process Id -> %d",getpid());
	printf("\n Parent Id -> %d",getppid());

	// Take the array input
	printf("\n Enter the size of array - ");
	scanf("%d",&n);
	printf("\n Please enter the elements in the array - ");
	for(int i=0; i<n; i++){
		printf("\n Enter the element [%d] - ",i);
		scanf("%d",&arr[i]);
	}

	// Print the array
	print_arr(arr,n);

	// Sort the array
	printf("\n Sorted Array using Quick sort -> ");
	quick_sort(arr,0,n-1);

	// Print the sorted array
	print_arr(arr,n);

	// Fork System call
	printf("\n Forking the current process - ");
	child = fork();

	if(child == -1)
		printf("\n Unfortunately the child was not born");
	else if(child == 0){
		// Inside child process
		printf("\n\n\n Hello from the child process !");
		printf("\n My id is -> %d",getpid());

		char *buffer[n+1];
		int i;

		// Arg 0 = name of executable file
		buffer[0] = "./binary";
				
		for(i=1;i<n+1;i++){
			buffer[i] = malloc(7);
			snprintf(buffer[i], 7, "%d", arr[i-1]);
		}

		buffer[i] = NULL;

		execv("./binary",buffer);
		
		printf("\n\n [INFO] Child executed successfully \n\n\n	");
	}
	else{
		// Inside parent process
		printf("\n Hello from the parent process !");
		printf("\n My id is -> %d",getpid());
		printf("\n Child Id -> %d",child);		
		printf("\n -------- Parent is waiting for child to complete --------");
		wait(NULL);
		printf("\n\n [INFO] Parent executed successfully \n\n\n");
	}
}

