/*
 * BinaryTree.cpp
 *
 * Created on: 31-Jan-2019
 *     Author: Devashish Prasad
 */

#include "BinaryTree.h"
#include "Queue.h"
#include "Queue.cpp"
#include <iostream>

using namespace std;

BinaryTree::BinaryTree() {
	// TODO Auto-generated constructor stub
	root = NULL;
	hl=0;
	hr=0;
}

BinaryTree::~BinaryTree() {
	// TODO Auto-generated destructor stub
	delete root;
}

int BinaryTree::isempty()
{
	if(root == NULL)
		return 1;
	else
		return 0;
}

Node* BinaryTree::getroot()
{
	return root;
}

void BinaryTree::insert(int d)
{
	if(isempty())
	{
		root = new Node;
		root->data = d;
		cout<<"\n Root node added successfully";
		return;
	}
	else
	{
		int ch;
		Node *temp = root;

		while(1)
		{
			ch = 0;
			cout<<"\n\nCurrent Node - "<<temp->data;

			while(ch == 0)
			{
				cout<<"\n Enter \n 1. to traverse left \n 2. to traverse right \n from current node - ";
				cin>>ch;
				if(ch!=1 && ch!=2)
				{
					cout<<"\n Please enter a valid choice... Try again !";
					ch = 0;
					continue;
				}
				break;
			}

			if(ch == 1)
			{
				if(temp->left == NULL)
				{
					temp->left = new Node;
					temp = temp->left;
					temp->data = d;
					cout<<"\n New Node added successfully";
					return;
				}
				else
					temp = temp->left;
			}
			if(ch == 2)
			{
				if(temp->right == NULL)
				{
					temp->right = new Node;
					temp = temp->right;
					temp->data = d;
					cout<<"\n New Node added successfully";
					return;
				}
				else
					temp = temp->right;
			}
		}
	}
}

void BinaryTree::display(int c)
{
	Node *temp = root;
	switch (c)
	{
		case 1:
			cout<<"\n In Order Traversal of the Tree - ";
			inorder(temp);
			break;
		case 2:
			cout<<"\n Pre Order Traversal of the Tree - ";
			preorder(temp);
			break;
		case 3:
			cout<<"\n Post Order Traversal of the Tree - ";
			postorder(temp);
			break;
		case 4:
			cout<<"\n Level Order Traversal of the Tree - ";
			levelorder(temp);
			break;
		default:
			break;
	}
}

void BinaryTree::inorder(Node *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		cout<<" "<<temp->data<<" ";
		inorder(temp->right);
	}
}

void BinaryTree::preorder(Node *temp)
{
	if(temp!=NULL)
	{
		cout<<" "<<temp->data<<" ";
		preorder(temp->left);
		preorder(temp->right);
	}
}

void BinaryTree::postorder(Node *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		cout<<" "<<temp->data<<" ";
	}
}

void BinaryTree::levelorder(Node *temp)
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

int BinaryTree::height(Node *temp)
{
	if(temp==NULL)
		return 0;
	else
	{
		hl = 1 + height(temp->left);
		hr = 1 + height(temp->right);
	}
	if(hl>hr)
		return hl;
	else
		return hr;
}

void BinaryTree::displayleaves(Node *temp)
{
	if(temp != NULL)
	{
		if(temp->left==NULL and temp->right==NULL)
		{
			cout<<" "<<temp->data<<" ";
		}
		displayleaves(temp->left);
		displayleaves(temp->right);
	}
}

Node* BinaryTree::copy(Node *temp)
{
	Node *t=NULL;
 	if(temp != NULL)
 	{
 		t = new Node;
 		t->data = temp->data;
 		t->left = copy(temp->left);
 		t->right = copy(temp->right);
 	}
 	return t;
}
