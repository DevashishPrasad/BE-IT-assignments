#include<iostream>
#include<vector>
#include<bits/stdc++.h> 

using namespace std;

float retrieve(vector<int>tape){
	if(tape.size() == 0)
		return 0;
	float rt=0;
	for(int y=0;y<tape.size();y++)
		rt+=tape[y];
	return rt/(float)tape.size();
}

int tape_vol(vector<int>tape){
	int total=0;
	for(int y=0;y<tape.size();y++)
		total+=tape[y];
	return total;
}

int main(int argc, char *args[]){

	// Variables of the program
	vector< vector<int> > tapes;
	vector<int> orig_progs,sorted_progs,capacities;
	float mrt;
	int no_tapes,no_programs,buffer,debug=0,ch,buffer2;
	
	if(argc == 2)
		debug = atoi(args[1]);
	
	cout<<"\n=============  Optimal Storage Tapes problem using Greedy method ===============\n";
	// Take input of number of tapes from user
	cout<<"\n Enter the number of tapes : ";
	cin>>no_tapes;
	// Take input of capacity of tapes from user
	cout<<"\n Enter the capacity of each tape : ";
	for(int i=0;i<no_tapes;i++){
		cout<<"\n Enter the capacity of tape "<<i+1<<" : ";
		cin>>buffer;
		capacities.push_back(buffer);
		tapes.push_back(std::vector<int>());
	}
	
	// Take input of capacity of tapes from user
	cout<<"\n Enter the number of programs : ";
	cin>>no_programs;	
	cout<<"\n Enter the programs : ";
	for(int i=0;i<no_programs;i++){
		cout<<"\n Enter the length of program "<<i+1<<" : ";
		cin>>buffer;
		orig_progs.push_back(buffer);
		sorted_progs.push_back(buffer);
	}
	
	// Sort the programs
	sort(sorted_progs.begin(), sorted_progs.end());

	if(debug != 0){
		// Print the programs
		cout<<"\n Original Programs : ";
		for(int x=0;x<orig_progs.size();x++)
			cout<<orig_progs[x]<<" ";
		cout<<"\n Sorted Programs : ";
		for(int x=0;x<sorted_progs.size();x++)
			cout<<sorted_progs[x]<<" ";
	}

	// Switch users choice
	while(1){
		cout<<"\n =============================";
		cout<<"\n |           MENU            |";
		cout<<"\n =============================";
		cout<<"\n | 1. Round Robin            |";								
		cout<<"\n | 2. Normal                 |";
		cout<<"\n | 3. Exit                   |";		
		cout<<"\n =============================";
		cout<<"\n Enter your choice : ";
		cin>>ch;				
		switch(ch){
			case 1:
				// Round Robin
				buffer = 0;
				for(int i=0;i<no_programs;i++){ 										
					int j=buffer%tapes.size();
					if(capacities[j]>=(tape_vol(tapes[j])+sorted_progs[i])){
						buffer2 = 0;
						tapes[j].push_back(sorted_progs[i]);
					}
					else{
						i--;	
						buffer2++;
					}
					buffer++;					
					if(buffer2>=no_tapes)
						break;
				}
				cout<<"\n Contents of the Tapes : ";
				for(int x=0;x<tapes.size();x++){
					cout<<"\nTAPE ["<<x<<"] : ";
					for(int y=0;y<tapes[x].size();y++)
						cout<<tapes[x][y]<<" ";
					cout<<"\n";											
				}
				
				cout<<"\n Mean Retirval time of Tapes : ";
				for(int x=0;x<tapes.size();x++)
					cout<<"\n MRT of TAPE ["<<x<<"] : "<<retrieve(tapes[x]);				
				break;
			case 2:
				// Normal
				buffer = 0;
				for(int i=0;i<no_tapes;i++){ 
					int j=capacities[i];
					while(j>0){			
						j=j-sorted_progs[buffer];
						if(j>=0){
							tapes[i].push_back(sorted_progs[buffer]);
							buffer++;
						}
					}
				}
				cout<<"\n Contents of the Tapes : ";
				for(int x=0;x<tapes.size();x++){
					cout<<"\nTAPE ["<<x<<"] : ";					
					for(int y=0;y<tapes[x].size();y++)
						cout<<tapes[x][y]<<" ";
					cout<<"\n";
				}
				
				cout<<"\n Mean Retirval time of Tapes : ";
				for(int x=0;x<tapes.size();x++)
					cout<<"\n MRT of TAPE ["<<x<<"] : "<<retrieve(tapes[x]);

				break;
			case 3:
				// Exit
				return 0;
		}
	}	
	return 0;
}
