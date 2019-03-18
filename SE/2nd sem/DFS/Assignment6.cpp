//=================================================================================
// Name        : Assignment6.cpp
// Author      : Devashish (23364)
// Version     : 1.0
// Copyright   : GNU Public License
// Description : Graph DFS and BFS
//				 1. DOB and No. of comments
//				 2. Find who has maximum and minimum comments
//				 3. Find who is having birthday this month
//				 4. Find who has maximum friends
//=================================================================================

#include <iostream>

using namespace std;

//==============================  Class declarations ==============================

class Date
{
	int day;
	int month;
	int year;

	public:

	void getdate()
	{
		cout<<"\n Please enter the date in following format -> (dd-mm-yyy)";
		cout<<"\n Enter the day - ";
		cin>>day;
		cout<<"\n Enter the month - ";
		cin>>month;
		cout<<"\n Enter the year - ";
		cin>>year;
	}
	void putdate()
	{
		cout<<"\n Date (dd-mm-yyy) - "<<day<<"-"<<month<<"-"<<year;
	}

};

class Vertex;

class Graphedge
{
	int weight;
	public:
	Vertex* orignal;
	Graphedge* nextlink;
};

class Vertex
{
	char* name;
	Date dob;
	int comments;
	bool visited;

	public:
	Vertex* downlink;
	Graphedge* edgelink;
	
	Vertex()
	{
		name = new char[20];
		comments = 0;
		visited = false;
		downlink = NULL;
		edgelink = NULL;
	}
	void makeuser()
	{
		cout<<"\n INFO: Adding new user, Please enter the following details - ";
		cout<<"\n Name - ";
		cin>>name;
		cout<<"\n Date of Birth - ";
		dob.getdate();
		downlink = NULL;
	}
	void putdata()
	{
		cout<<"\n Name - "<<name;
		cout<<"\n Date of Birth - ";
		dob.putdate();
		cout<<"\n Comments - "<<comments;
	}
	void setvisited()
	{
		visited = true;
	}
	bool checkvisited()
	{
		return visited;
	}
	void visitinit()
	{
		visited = false;
	}
//	void addfriend()
//	{
//
//		cout<<"\n INFO: Adding new friend of the current user - ";
//		cout<<"\n Enter the name of the friend - ";
//		cin>>
//	}
};

class startnode
{
	int cnt;
	public:
	Vertex* start;
	void createNode()
	{
		cnt = 0;
		cout<<"\n\n INFO: Making new User in the network";
		Vertex *temp = start;

		if(temp == NULL)
		{
			temp = new Vertex;
			temp->makeuser();	
			return;
		}

		while(temp->downlink!=NULL)
		{
			cnt++;
			temp=temp->downlink;
		}

		temp->downlink = new Vertex;
		temp->makeuser();
	}
	void initvisit()
	{
		Vertex *temp = start; 
		while(temp != NULL)
		{
			temp->visitinit();
			temp= temp->downlink;
		}
	}
};

void traverse(Vertex* temp)
{
	temp->setvisited();
	temp->putdata();
	Graphedge* g = temp->edgelink;
	while(g!=NULL)
	{
		if(g->orignal->checkvisited() != true)
			traverse(g->orignal);
		g = g->nextlink;
	}
}

int main() {
	startnode *graph = new startnode;
	Vertex *startv = NULL;
	graph->start = startv;
	
	int choice;
	do
	{
		cout<<"\n\n\n ____________________________________";
		cout<<"\n|                                    ";
		cout<<"\n|                MENU                ";
		cout<<"\n|____________________________________";
		cout<<"\n|                                    ";
		cout<<"\n|  1. Create New User   ";
		cout<<"\n|  2. Make friends";
		cout<<"\n|  3. Maximum friends    ";
		cout<<"\n|  4. Maximum and minimum friends";
		cout<<"\n|  5. Users having birthday this month";
		cout<<"\n|  6. Traverse the graph";
		cout<<"\n|  7. Exit                          ";
		cout<<"\n|____________________________________";
		cout<<"\n Enter your choice - ";
		cin>>choice;

		switch(choice)
		{
			case 1:
				graph->createNode();
				break;
			case 2:
				cout<<"\n Enter your name - ";
				cin>>
				cout<<"\n Enter the name of the person who you";
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				graph->initvisit();
				traverse(startv); 
				break;
			case 7:
				break;
			default:
				break;
		}
	}while(1);
	return 0;
}
