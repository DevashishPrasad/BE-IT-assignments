#include<iostream>
#include<vector>

using namespace std;

int main(){
	// Variables of the program
	vector<vector<int>> tapes;
	vector<int> orig_progs,;
	
	float mrt;
	
	cout<<"\n===============================  Optimal Storage Tapes problem ===================================\n";
	// Take input of number of tapes from user
	cout<<"\n Enter number of tapes : ";
	cin>>no_tapes;
	c = new int[no_tapes];
	
	tapes = new int[no_tapes];
	// Take input of capacity of tapes from user
	cout<<"\n Enter the capacity of each tape : ";
	for(int i=0;i<no_tapes;i++){
		cout<<"\n Enter the capacity of tape "<<i+1<<" : ";
		cin>>c[i];
		tapes[i] = [c[i]]
	}
	
	return 0;
}
