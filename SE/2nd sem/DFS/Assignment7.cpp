//=================================================================================
// Name        : Assignment6.cpp
// Author      : Devashish (23364)
// Version     : 1.0
// Copyright   : GNU Public License
// Description : Represent any real world graph using adjacency list /adjacency 
//               matrix find minimum spanning tree using Kruskal’s algorithm.
//=================================================================================

#include <iostream>
#include <string.h>

using namespace std;

//==============================  Class declarations ==============================

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
	bool visited;
	Vertex* downlink;
	Graphedge* edgelink;

	Vertex()
	{
		name = new char[20];
		visited = false;
		downlink = NULL;
		edgelink = NULL;
	}

	void makeuser()
	{
		cout<<"\n INFO: Adding new user, Please enter the following details - ";
		cout<<"\n Name - ";
		cin>>name;
	}

	void putdata()
	{
		cout<<"\n";
		cout<<"\t"<<name;
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

// Check cycles
void checkcycle(Vertex* temp)
{
	temp->putdata();
	Graphedge* g = temp->edgelink;
	while(g!=NULL)
	{
		traversedfs(g->neighbourlink);
		g = g->nextlink;
	}
}

// Add a new user to the network
startnode* addNode(startnode *startn)
{
	cout<<"\n\n INFO: Creating new Node in the graph";
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
	
	cout<<"\n\n INFO: Node was added successfully in the graph";
	return temp;
}

// Add edge 
startnode* addEdge(startnode *startn, char* name1, char* name2)
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
		cout<<"\n INFO:	The node specified as \" "<<name1<<" \"does not exist in the graph, please try again !!!";
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
		cout<<"\n INFO: The node specified as \" "<<name2<<" \" does not exist in the graph, please try again !!!";
		return temp;
	}

	int weight = 0;

	cout<<"\n Enter the weight of the edge - ";
	cin>>weight;

	// Graphedge *ge1,*ge2;

	// while(v1->edgelink != NULL)
	// 	v1->edgelink = v1->edgelink->nextlink;
	
	// ge1 = new Graphedge;
	// ge1->neighbourlink = v1;
	// ge1->weight = weight;
	// ge1->nextlink = NULL;
	// v1->edgelink = ge1;

	// while(v2->edgelink != NULL)
	// 	v2->edgelink = v2->edgelink->nextlink;
	
	// ge2 = new Graphedge;
	// ge2->neighbourlink = v1;
	// ge2->weight = weight;
	// ge2->nextlink = NULL;
	// v2->edgelink = ge2;


	Graphedge *ge1,*ge2;

	// edge from v1 to v2
	ge1 = v1->edgelink;

	if(ge1 == NULL)
	{
		ge1 = new Graphedge;
		ge1->neighbourlink = v2;
		ge1->weight = weight;
		ge1->nextlink = NULL;
		v1->edgelink = ge1;
	
		return temp;
	}

	while(ge1->nextlink != NULL)
		ge1 = ge1->nextlink;

	ge1->nextlink = new Graphedge;
	ge1 = ge1->nextlink;
	ge1->weight = weight;
	ge1->neighbourlink = v2;
	ge1->nextlink = NULL;

	// edge from v2 to v1
	ge2 = v2->edgelink;

	if(ge2 == NULL)
	{
		ge2 = new Graphedge;
		ge2->neighbourlink = v1;
		ge2->weight = weight;	
		ge2->nextlink = NULL;
		v2->edgelink = ge2;
	
		return temp;
	}

	while(ge2->nextlink != NULL)
		ge2 = ge2->nextlink;

	ge2->nextlink = new Graphedge;
	ge2 = ge2->nextlink;
	ge2->weight = weight;	
	ge2->neighbourlink = v1;
	ge2->nextlink = NULL;

	cout<<"\n INFO: The edge was successfully added between \" "<<v1->name<<" \" and \" "<<v2->name<<" \"";

	return temp;
}

// Swapping edges
void swap(Graphedge *xp, Graphedge *yp) 
{ 
    Graphedge temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

// Sort the edges
void sortEdges(startnode *graph)
{
	Vertex *v = graph->start;
	Graphedge *gearr[30];
	int index = 0;

	while(v!=NULL)
	{
		Graphedge *ge = v->edgelink;
		
		while(ge != NULL)
		{
			gearr[index] = ge;
			cout<<"\n "<<gearr[index]->weight<<" - "<<index;
			index++;
			ge = ge->nextlink; 
		}
		v = v->downlink;
	}

	// // bubble sort
	// int i, j, n=30; 
   	// for (i = 0; i < n-1; i++)       
    //    // Last i elements are already in place    
    //    for (j = 0; j < n-i-1; j++)  
    //        if (gearr[j]->weight > gearr[j+1]->weight) 
    //           swap(gearr[j], gearr[j+1]); 

	cout<<"\n sorted - ";
	for(int i = 0;gearr[i] != NULL; i++)
	{
		cout<<"\n"<<gearr[i]->weight;
	}
}

// Kruskal MST
void kruskal(startnode *graph)
{
	sortEdges(graph);
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
		cout<<"\n|  1. Create New Node   ";
		cout<<"\n|  2. Add edges";
		cout<<"\n|  3. Create MST (kruskal)";
		cout<<"\n|  4. Traverse the graph";
		cout<<"\n|  5. Exit                          ";
		cout<<"\n|____________________________________";
		cout<<"\n Enter your choice - ";
		cin>>choice;

		switch(choice)
		{
			case 1:
				graph = addNode(graph);
				break;
			case 2:
				cout<<"\n Enter name of vertex 1 - ";
				cin>>name1;
				cout<<"\n Enter name of vertex 2 - ";
				cin>>name2;
				graph = addEdge(graph, name1, name2);
				break;
			case 3:
				kruskal(graph);
				break;
			case 4:
				cout<<"\t Name ";
				initvisit(graph);
				traversedfs(graph->start);
				break;
			case 5:
				return 0;
			default:
				break;
		}

	}while(1);

	return 0;
}
