//============================================================================
// Name        : Assignment5.cpp
// Author      : Devashish
// Version     : 1.0
// Copyright   : GNU Public License
// Description : Perform following operations using Binary Search Tree
// 				 1. Insert
//				 2. Delete
//				 3. Search
//				 4. Mirror Image
//				 6. Display
//				 7. Display level wise
//				 8. Height of the tree
//============================================================================
#include <iostream>
#include "Queue.h"
#include "Queue.cpp"

using namespace std;

//========================= Class for Binary Search Tree =====================
typedef struct Node
{
	struct Node *left;
	struct Node *right;
	int data;
}Node;

class BinarySearchTree
{
	Node *root;
public:
	BinarySearchTree()
	{
		root = NULL;
	}
	Node* getRoot()
	{
		return root;
	}
	void insert(int d)
	{
		Node* temp = root;

		while(1)
		{
			if(temp == NULL)
			{
				temp = new Node;
				temp->left = NULL;
				temp->right = NULL;
				temp->data = d;
				cout<<"\n\n INFO: Data was inserted in the tree successfully";
				return;
			}
			else
			{
				if(d > temp->data)
					temp = temp->right;
				else if(d > temp->data)
					temp = temp->left;
				else
				{
					cout<<"\n\n INFO: Cannot insert given data, duplicate data values not allowed";
					return;
				}
			}
		}
	}

	void remove(int d)
	{

	}

	void search(int d)
	{

	}

	Node* mirror(Node* temp)
	{
		return root;
	}

	void display(int d)
	{
		switch(d)
		{
			case 1:
				cout<<"\n\n INFO: In Order Traversal of the Tree - ";
				rinorder(root);
				break;
			case 2:
				cout<<"\n\n INFO: Pre Order Traversal of the Tree - ";
				rpreorder(root);
				break;
			case 3:
				cout<<"\n\n INFO: Post Order Traversal of the Tree - ";
				rpostorder(root);
				break;
			case 3:
				cout<<"\n\n INFO: Post Order Traversal of the Tree - ";
				levelorder(root);
				break;
			default:
				break;
		}
	}

//====================== Recursive tree traversals ===================
	void rinorder(Node *temp)
	{
		if(temp!=NULL)
		{
			rinorder(temp->left);
			cout<<" "<<temp->data<<" ";
			rinorder(temp->right);
		}
	}

	void rpreorder(Node *temp)
	{
		if(temp!=NULL)
		{
			cout<<" "<<temp->data<<" ";
			rpreorder(temp->left);
			rpreorder(temp->right);
		}
	}

	void rpostorder(Node *temp)
	{
		if(temp!=NULL)
		{
			rpostorder(temp->left);
			rpostorder(temp->right);
			cout<<" "<<temp->data<<" ";
		}
	}

	void levelorder(Node *temp)
	{
		Queue<Node*> q;

		while(temp!=NULL)
		{
			cout<<" "<<temp->data<<" ";
			q.enqueue(temp->left,1);
			q.enqueue(temp->right,1);

			if(!q.isempty())
			{
				temp = q.dequeue();
			}
			else
				temp = NULL;
		}
	}

};
int main()
{
	BinarySearchTree bst;
	int choice,temp=0,ch=0;

	do
	{
		cout<<"\n\n\n ____________________________________";
	    cout<<"\n|                                    |";
		cout<<"\n|                MENU                |";
		cout<<"\n|____________________________________|";
	    cout<<"\n|                                    |";
		cout<<"\n|  1. Insert                         |";
		cout<<"\n|  2. Delete                         |";
		cout<<"\n|  3. Search                         |";
		cout<<"\n|  4. Mirror Image                   |";
		cout<<"\n|  5. Display                        |";
		cout<<"\n|  6. Display level wise             |";
		cout<<"\n|  7. Height of the tree             |";
		cout<<"\n|  8. Exit                           |";
	    cout<<"\n|____________________________________|";
		cout<<"\n Enter your choice - ";
		cin>>choice;

		switch(choice)
		{
			case 1:
					cout<<"\n\n Enter the value to be inserted in the BST - ";
					cin>>temp;
					bst.insert(temp);
					break;
			case 2:
					cout<<"\n\n Enter the value to be deleted from the tree - ";
					cin>>temp;
					bst.remove(temp);
					break;
			case 3:
					cout<<"\n\n Enter the value to be searched in the tree - ";
					cin>>temp;
					bst.search(temp);
					break;
			case 4:
					bst.mirror(bst.getRoot());
					cout<<"\n\n INFO: The tree was mirrored successfully";
					break;
			case 5:
					bst.display();
					break;
			case 6:
					bst.display(4);
					break;
			case 7:
					cout<<"\n\n Height of the BST is - "<<bst.height();
					break;
			case 8:
					return 0;
            default:
	                cout<<"\n\n INFO: Please Enter a valid choice, Try Again !";
	                break;
		}
	}while(1);
}
