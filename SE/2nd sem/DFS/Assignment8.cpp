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

//==============================  structure declarations ==============================

int id = 0;

struct Vertex;

struct Graphedge
{
	bool prim;
	bool visited;
	int weight;
	Vertex* neighbourlink;
	Graphedge* nextlink;

	Graphedge()
	{
		visited = false;
		nextlink = NULL;
		neighbourlink = NULL;
	}
};

struct Vertex
{
	char* name;
	int id;
	bool prim;
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
		cout<<"\t"<<name<<" "<<id;
	}
};

// Starting Node of the graph
struct startnode
{
	int cnt;
	Vertex* start;
};

//==================================== Functions ==========================================
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

// Initialize visited flag for all edges
startnode* initedges(startnode *startn)
{
	startnode *temp = startn;
	Vertex *tempv = temp->start;
	
	while(tempv != NULL)
	{
		Graphedge *tempe = tempv->edgelink;
		while(tempe != NULL)
		{
			tempe->visited = false;
			tempe = tempe->nextlink;
		}	
		tempv = tempv->downlink;
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
		tempv->id = id;
		id++;
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
	tempv->id = id;
	id++;
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
	
		// return temp;
		cout<<"\n INFO: The edge was successfully added from \" "<<v1->name<<" \" to \" "<<v2->name<<" \"";

	}
	else
	{
		while(ge1->nextlink != NULL)
			ge1 = ge1->nextlink;

		ge1->nextlink = new Graphedge;
		ge1 = ge1->nextlink;
		ge1->weight = weight;
		ge1->neighbourlink = v2;
		ge1->nextlink = NULL;

		cout<<"\n INFO: The edge was successfully added from \" "<<v1->name<<" \" to \" "<<v2->name<<" \"";
	}

	// edge from v2 to v1
	ge2 = v2->edgelink;

	if(ge2 == NULL)
	{
		ge2 = new Graphedge;
		ge2->neighbourlink = v1;
		ge2->weight = weight;	
		ge2->nextlink = NULL;
		v2->edgelink = ge2;

		cout<<"\n INFO: The edge was successfully added from \" "<<v2->name<<" \" to \" "<<v1->name<<" \"";	
	}
	else
	{		
		while(ge2->nextlink != NULL)
			ge2 = ge2->nextlink;

		ge2->nextlink = new Graphedge;
		ge2 = ge2->nextlink;
		ge2->weight = weight;	
		ge2->neighbourlink = v1;
		ge2->nextlink = NULL;

		cout<<"\n INFO: The edge was successfully added from \" "<<v2->name<<" \" to \" "<<v1->name<<" \"";	
	}
	
	return temp;
}


int primtraverse(startnode *graph)
{
	startnode *temp = graph;
	Vertex *v = temp->start;

	int cost = 0;

	while(v!=NULL)
	{
		Graphedge *ge = v->edgelink;

		while(ge!=NULL)
		{
			if(ge->visited == true)
			{
				cout<<"\n"<<v->name<<" to "<<ge->neighbourlink->name;
				cost += ge->weight;
			}
			ge = ge->nextlink;
		}
		v = v->downlink;
	}
	return cost;
}

// Prims MST
void prim(startnode *graph)
{
	Vertex *v = graph->start;
	Graphedge *min = new Graphedge;
	
	initvisit(graph);
	initedges(graph);

	int n = 0;

	while(v!=NULL)
	{
		v=v->downlink;
		n++;
	}

	v = graph->start;
	v->visited = true;
	
	for(int i=0; i<n-1; i++)
	{
		min->weight = 9999;
		v = graph->start;
		
		while(v != NULL)
		{
			cout<<"\n -- 1";

			Graphedge *ge = v->edgelink;
			
			while(v->visited == true && ge != NULL && ge->visited == false &&  ge->neighbourlink->visited == false)
			{
				cout<<"\n -- 2";
				if(ge->weight < min->weight)
				{	
					min = ge; 
					cout<<" \n "<<min->weight;
				}
				ge = ge->nextlink; 
			}

			min->neighbourlink->visited = true;
			min->visited = true;

			v = v->downlink;
		}
	}

	int cost = primtraverse(graph);
	cout<<"\n Minimal Spanning Tree cost - "<<cost;
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
		cout<<"\n|  3. Create MST (Prims)";
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
				prim(graph);
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
