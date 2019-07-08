// COMPILE : gcc Assignment2.c -o op1.out
// EXECUTE : ./op1.out
	
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void merge_sort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        merge_sort(arr, l, m); 
        merge_sort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

void main(){

	// Declare the variables
	int arr[100],n,i,choice;
	pid_t newpid,child;

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

	printf("\n --------- MENU ---------");
	printf("\n 1. Normal Execution ");
	printf("\n 2. Zombie ");
	printf("\n 3. Orphan ");
	printf("\n Enter your choice - ");
	scanf("%d",&choice);
	
	switch(choice){
		case 1:
			// Fork System call
			printf("\n Forking the process - ");
			newpid = fork();

			if(newpid == -1)
				printf("\n Unfortunately the child was not born");
			else if(newpid == 0){
				// Inside child process
				printf("\n\n\n Hello from the child process !");
				printf("\n My id is -> %d",getpid());		
				printf("\n Sorted Array using Quick sort -> ");
				quick_sort(arr,0,n-1);
				print_arr(arr,n);
				printf("\n\n [INFO] Child executed successfully \n\n\n	");
			}
			else{
				// Inside parent process
				int status;
				child = wait(&status);
				if (child != -1)
					printf("\n\n\n Waited for child with pid %d\n", child);
				printf("\n Hello from the parent process !");
				printf("\n My id is -> %d",getpid());
				printf("\n Child Id -> %d",newpid);		
				printf("\n Sorted Array using Merge sort -> ");
				merge_sort(arr,0,n-1);
				print_arr(arr,n);
				printf("\n\n [INFO] Parent executed successfully \n\n\n");
			}
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			printf("\n OOPS! INVALID INPUT");
	}

}
