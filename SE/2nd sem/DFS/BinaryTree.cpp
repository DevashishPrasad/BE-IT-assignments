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

template <class T>
BinaryTree<T>::BinaryTree() {
	// TODO Auto-generated constructor stub
	root = new struct Node;
	root->data = -1;
}

template <class T>
BinaryTree<T>::~BinaryTree() {
	// TODO Auto-generated destructor stub
	delete root;
}

template <class T>
void BinaryTree<T>::displayRoot() {
	cout<<root->data;
}

template <class T>
int BinaryTree<T>::isempty()
{
	if(root->data == -1)
		return 1;
	else
		return 0;
}

template <class T>
void BinaryTree<T>::insert(T d)
{	
	if(root->data == -1)
	{
		root->data = d;
		cout<<"\n Root node added successfully";
		return;
	}	
	else
	{
		int ch;
		struct Node *temp = root;

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
					temp->left = new struct Node;
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
					temp->right = new struct Node;
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

template <class T>
void BinaryTree<T>::display(int c)
{
	struct Node *temp = root;
	switch (c)
	{
		case 1:
			cout<<"\n Inorder Traversal of the Tree - ";
			inorder(temp);
			break;
		case 2:
			cout<<"\n Preorder Traversal of the Tree - ";
			preorder(temp);
			break;
		case 3:
			cout<<"\n Postorder Traversal of the Tree - ";
			postorder(temp);
			break;
		case 4:
			cout<<"\n Levelorder Traversal of the Tree - ";
			levelorder(temp);
			break;	
		default:
			break;
	}
}

template <class T>
void BinaryTree<T>::inorder(Node *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		cout<<" "<<temp->data<<" ";
		inorder(temp->right);
	}
}

template <class T>
void BinaryTree<T>::preorder(Node *temp)
{
	if(temp!=NULL)
	{
		cout<<" "<<temp->data<<" ";
		preorder(temp->left);
		preorder(temp->right);
	}
}

template <class T>
void BinaryTree<T>::postorder(Node *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		cout<<" "<<temp->data<<" ";
	}
}

template <class T>
void BinaryTree<T>::levelorder(Node *temp)
{
	Queue<struct Node*> q;
	
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