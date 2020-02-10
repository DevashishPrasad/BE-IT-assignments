#include<stdio.h>
#include<iostream>

using namespace std;

int check_sorted(int *arr, int n){
	int flg = 1;
	for(int i=1;i<n;i++){
		if(arr[i-1]>=arr[i]){
			flg = 0;
			break;
		}
	}
	return flg;
}

void min_max(int *arr, int *min, int *max, int start, int end){
	if(end - start <= 1){
		if(arr[start]>*max)
			*max = arr[start];
		if(arr[end]>*max)
			*max = arr[end];			
		if(arr[start]<*min)
			*min = arr[start];
		if(arr[end]<*min)
			*min = arr[end];			
	}
	else{
		min_max(arr, min, max, start, (start+end)/2);			
		min_max(arr, min, max, ((start+end)/2)+1, end);
	}
}

int main(){
	int *arr,n,min=9999,max=0;
	
	// Number of elements
	cout<<"\n Enter the number of elements in the array : ";
	cin>>n;
	arr = new int[n];
	
	// Input elements from the user
	cout<<"\n Enter the elements : ";
	for(int i=0;i<n;i++){
		cout<<"\n Element ["<<i<<"] : ";
		cin>>arr[i];
	}
	
	// If already sorted then don't divide and conquer
	if(check_sorted(arr,n)){
		min = arr[0];
		max = arr[n-1];
		cout<<"\n Minimum in the Array : "<<min;
		cout<<"\n Maximum in the Array : "<<max;		
		cout<<"\n";				
		return 0;
	}
	
	// If not sorted then divide and conquer
	min_max(arr,&min,&max,0,n-1);	
	cout<<"\n Minimum in the Array : "<<min;
	cout<<"\n Maximum in the Array : "<<max;
	
	cout<<"\n";		
	
	return 0;
}
