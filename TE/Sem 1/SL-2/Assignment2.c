// COMPILE : gcc Assignment2.c -o op1.out
// EXECUTE : ./op1.out
	
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void print_array(int arr[100]){

	printf("\n Your array is - \n [ ");
 
	for(i=0; i<n-1; i++)
		printf(" %d, ",arr[i]);

	printf(" %d ]",arr[i]);
}

void QuickSort(int arr[100],int first,int last){

    int i,j,k,pivot,cmp=0,swap=0;

    user temp;

    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;

        while(i<j)
        {
            while(strcmp(arr[i].name, arr[pivot].name) >= 0 && i<last)
                i++;

            while(strcmp(arr[j].name, arr[pivot].name) < 0)
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

        QuickSort(arr,first,j-1);
        QuickSort(arr,j+1,last);
    }

    p++;
    printf("\n PASS %d - ", p);

    print_arr(arr);

    printf("\n Compariosns - %d ", cmp);
    printf("\n Swaps - %d ", swap);
    printf("\n Pivot - %s ", arr[pivot]);
}


void main(){

	// Declare the variables
	int arr[100],n,i;

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
	print_arr(arr);

	printf("\n Forking the process - ");

	pid_t newpid;
	newpid = fork();

	if(newpid == -1)
		printf("\n Unfortunately the child was not born");
	else if(newpid == 0){
		printf("\n\n\n This is the child process -");
		printf("\n Hello from the child process !");
		printf("\n My id is -> %d",getpid());		
		printf("\n\n [INFO] Child executed successfully \n\n\n	");
	}
	else{
		printf("\n Hello from the parent process !");
		printf("\n My id is -> %d",getpid());
		printf("\n Child Id -> %d",newpid);		
		printf("\n\n [INFO] Parent executed successfully \n\n\n");
	}
}
