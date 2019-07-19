// COMPILE : gcc binary_search.c -o binary
// EXECUTE : ./binary

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

// function to print the array on console
void print_arr(int arr[100],int n){
	int i;

	printf("\n Your array is - \n [ ");

	for(i=0; i<n-1; i++)
		printf(" %d, ",arr[i]);

	printf(" %d ]\n",arr[i]);
}

// binary search
void binary_search(int arr[100],int no,int search){
	int first,last,mid;
	first = 0;
	last = no-1;
	mid = (first + last)/2;

	while(first<=last){
		if(arr[mid] < search)
			first=mid+1;
		else if(arr[mid] == search){
			printf("\n Element was found in the array at location --> %d\n\n",mid);
			break;
		}
		else
			last = mid-1;
		mid = (first + last)/2;
	}

	if(first>last)
		printf("\n Element was NOT found in the array \n\n");
}

// main function of the program
void main(int argc, char* argv[], char* envp){

	int arr[argc-1],search;

	for(int i=1;i<argc;i++)
		arr[i-1]=atoi(argv[i]);

	print_arr(arr,argc-1);		

	printf("\n Enter the value to be searched --> ");
	scanf("%d",&search);

	binary_search(arr,argc-1,search);
}
