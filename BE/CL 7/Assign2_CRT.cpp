#include<iostream>
 
using namespace std; 

int findMinX(int num[], int rem[], int k) { 
    int x = 1; 

    while (true){ 
        int j; 
        for (j=0; j<k; j++ ) 
            if (x%num[j] != rem[j]) 
               break; 

        if (j == k) 
            return x; 
        x++; 
    } 
  
    return x; 
} 

int main(void) { 
	int n;
	cout<<"\nEnter n : ";
	cin>>n;
	int  num[n], rem[n];
	
	cout<<"\nEnter num : ";
	for(int i=0;i<n;i++)
		cin>>num[i];
	
	cout<<"\nEnter rem : ";
	for(int i=0;i<n;i++)
		cin>>rem[i];
	
    //int num[n] = {3, 4, 5, 7}; 
    //int rem[] = {2, 3, 1, 2}; 
    
    int k = sizeof(num)/sizeof(num[0]); 
    cout << "\nx is " << findMinX(num, rem, k); 
   
    return 0; 
} 
