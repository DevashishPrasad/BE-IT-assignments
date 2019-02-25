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
	Vertex* orignal;
	Graphedge* nextlink;
};

class Vertex
{
	char* name;
	Date dob;
	int comments;
	Vertex* downlink;
	Graphedge* edgelink;
	bool visited;

	public:
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
	}
	void putdata()
	{
		cout<<"\n Name - "<<name;
		cout<<"\n Date of Birth - "<<dob.putdate();
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
	Vertex* start;
	public:
	void creategraph()
	{
		cout<<"\n\n INFO: Making new User in the network";
		Vertex *temp = start;

		while(temp!=NULL)
			temp=temp->downlink;

		temp = new Vertex;
		temp->makeuser();
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
	return 0;
}
