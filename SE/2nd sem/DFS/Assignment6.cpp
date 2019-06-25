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
#include <string.h>
#include <queue>

using namespace std;

//==============================  Class declarations ==============================

// Date as a user defined data type
class Date
{
	int day;
	int month;
	int year;

	public:

	void getdate()
	{
		cout<<"\n Please enter the date ";
		cout<<"\n Enter the day (dd) - ";
		cin>>day;
		cout<<"\n Enter the month (mm) - ";
		cin>>month;
		cout<<"\n Enter the year (yyyy) - ";
		cin>>year;
	}
	int getmonth()
	{
		return month;
	}
	void putdate()
	{
		cout<<"\t"<<day<<"-"<<month<<"-"<<year;
	}
};

struct Vertex;

struct Graphedge
{
	int weight;
	Vertex* neighbourlink;
	Graphedge* nextlink;
};

struct Vertex
{
	char* name;
	Date dob;
	int comments;
	bool visited;
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
		cout<<"\n Enter the number of comments - ";
		cin>>comments;
	}

	void putdata()
	{
		cout<<"\n";
		cout<<"\t"<<name;
		dob.putdate();
		cout<<"\t"<<comments;		
	}
};

// Starting Node of the graph
struct startnode
{
	int cnt;
	Vertex* start;
};

// Initialize visited flag for all nodes
void initvisit(startnode *startnode)
{
	Vertex *temp = startnode->start;
	while(temp != NULL)
	{
		temp->visited = false;
		temp= temp->downlink;
	}
}

// Depth first traversal
void traversedfs(Vertex* temp)
{
	temp->visited = true;
	temp->putdata();
	Graphedge* g = temp->edgelink;
	while(g!=NULL)
	{
		if(g->neighbourlink->visited != true)
			traversedfs(g->neighbourlink);
		g = g->nextlink;
	}
}

// Depth first traversal
void traversebfs(Vertex* temp)
{
	Vertex *t = temp;
	
	queue<Vertex*> q;
	q.push(t);

	temp->visited = true;
	
	while(!q.empty())
	{
		t = q.front();
		t->putdata();
		q.pop();

		Graphedge* g = t->edgelink;

		while(g!=NULL)
		{
			if(!g->neighbourlink->visited)
			{
				q.push(g->neighbourlink);
				g->neighbourlink->visited = true;
			}
			g = g->nextlink;
		}

		t = t->downlink;
	}
}

// Add a new user to the network
startnode* addNode(startnode *startn)
{
	cout<<"\n\n INFO: Creating new User in the network";
	startnode *temp = startn;
	Vertex *tempv = temp->start;
	
	if(tempv == NULL)
	{
		tempv = new Vertex;
		tempv->makeuser();
		tempv->downlink = NULL;
		temp->start = tempv;
		return temp;
	}

	while(tempv->downlink!=NULL)
	{
		startn->cnt++;
		tempv=tempv->downlink;
	}

	tempv->downlink = new Vertex;
	tempv = tempv->downlink;
	tempv->downlink = NULL;
	tempv->makeuser();
	
	cout<<"\n\n INFO: User was added successfully in the network";
	return temp;
}

// Add friend 
startnode* addFriend(startnode *startn, char* name1, char* name2)
{
	int flg = 0;

	startnode *temp = startn;
	Vertex *v1 = startn->start; 
	Vertex *v2 = startn->start; 

	while(v1!=NULL)
	{	
		if(strcmp(v1->name,name1) != 0)
			v1=v1->downlink;
		else if(strcmp(v1->name,name1) == 0)
		{
			flg = 1;
			break;
		}
	}

	if(flg == 0)
	{
		cout<<"\n INFO:	The name specified as \" "<<name1<<" \"does not exist in the network, please try again !!!";
		return temp;
	}

	flg = 0;
	v2 = startn->start; 

	while(v2!=NULL)
	{	
		if(strcmp(v2->name,name2) != 0)
			v2=v2->downlink;
		else
		{
			flg = 1;
			break;
		}
	}

	if(flg == 0)
	{
		cout<<"\n INFO: The name specified as \" "<<name2<<" \" does not exist in the network, please try again !!!";
		return temp;
	}

	Graphedge *ge1,*ge2;

	// edge from v1 to v2
	ge1 = v1->edgelink;

	if(ge1 == NULL)
	{
		ge1 = new Graphedge;
		ge1->neighbourlink = v2;
		ge1->nextlink = NULL;
		v1->edgelink = ge1;
	
		return temp;
	}

	while(ge1->nextlink != NULL)
		ge1 = ge1->nextlink;

	ge1->nextlink = new Graphedge;
	ge1 = ge1->nextlink;
	ge1->neighbourlink = v2;
	ge1->nextlink = NULL;

	// edge from v2 to v1
	ge2 = v2->edgelink;

	if(ge2 == NULL)
	{
		ge2 = new Graphedge;
		ge2->neighbourlink = v1;
		ge2->nextlink = NULL;
		v2->edgelink = ge2;
	
		return temp;
	}

	while(ge2->nextlink != NULL)
		ge2 = ge2->nextlink;

	ge2->nextlink = new Graphedge;
	ge2 = ge2->nextlink;
	ge2->neighbourlink = v1;
	ge2->nextlink = NULL;

	return temp;
}

// Maximum friends
void maxfriends(startnode *graph)
{
	Vertex *temp = graph->start;
	Vertex *max = NULL;
	Graphedge *ge = NULL;

	int maxc = 0;

	while(temp != NULL)
	{
		int cnt=0;
		ge = temp->edgelink;
		while(ge != NULL)
		{
			cnt++;
			ge = ge->nextlink;
		}
		if(maxc < cnt)
		{
			max = temp;
			maxc = cnt;
		}
		temp = temp->downlink;
	}

	cout<<"\n The person having maximum friends is - ";
	if(max!=NULL)
		cout<<max->name;
	else
		cout<<"No one has friends";
}

// Max and minimum comments
void maxmincomments(startnode *graph)
{
	Vertex *temp = graph->start;
	Vertex *max = graph->start;
	Vertex *min = graph->start;
	
	int maxc = 0;
	int minc = 9999;

	while(temp != NULL)
	{
		int cnt = temp->comments;
		if(maxc < cnt)
		{
			max = temp;
			maxc = cnt;
		}
		else if(minc > cnt)
		{
			min = temp;
			minc = cnt;
		}
		temp = temp->downlink;
	}

	cout<<"\n The person having maximum comments is - "<<max->name;
	cout<<"\n The person having minimum comments is - "<<min->name;
}

// Birthday
void birthday(startnode *graph)
{
	Vertex *temp = graph->start;

	int cnt = 3;

	cout<<"\n The people having birthday this month are - ";

	while(temp != NULL)
	{
		if(cnt == temp->dob.getmonth())
			cout<<"\n "<<temp->name;
		temp = temp->downlink;
	}
}

int main()
{
	startnode *graph = new startnode;
	graph->start = NULL;

	char *name1 = new char[20], *name2 = new char[20];
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
		cout<<"\n|  4. Maximum and minimum comments";
		cout<<"\n|  5. Users having birthday this month";
		cout<<"\n|  6. Traverse the graph";
		cout<<"\n|  7. Exit                          ";
		cout<<"\n|____________________________________";
		cout<<"\n Enter your choice - ";
		cin>>choice;

		switch(choice)
		{
			case 1:
				graph = addNode(graph);
				break;
			case 2:
				cout<<"\n Enter your name - ";
				cin>>name1;
				cout<<"\n Enter the name of the person whom you want to make friend - ";
				cin>>name2;
				graph = addFriend(graph, name1, name2);
				break;
			case 3:
				maxfriends(graph);
				break;
			case 4:
				maxmincomments(graph);
				break;
			case 5:
				birthday(graph);
				break;
			case 6:
				cout<<"\n ================ DFS ================= \n";
				cout<<"\t Name \t DoB \t Comments";
				initvisit(graph);
				traversedfs(graph->start);
				cout<<"\n ================= BFS ================= \n";
				cout<<"\t Name \t DoB \t Comments";
				initvisit(graph);
				traversebfs(graph->start);
				break;
			case 7:
				return 0;
			default:
				break;
		}
	}while(1);

	return 0;
}
