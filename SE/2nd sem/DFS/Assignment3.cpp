//============================================================================
// Name        : Assignment3.cpp
// Author      : Devashish
// Version     : 1.0
// Copyright   : GNU Public Lincense
// Description : Binary Tree
//============================================================================

#include <iostream>
#include "Queue.cpp"
#include "Queue.h"

using namespace std;

template <class T>
class BinaryTree {
	public:
	typedef struct Node{
		struct Node *left;
		struct Node *right;
		T data;
	}Node;
	int hl,hr;
	Node *root;
	BinaryTree();
	virtual ~BinaryTree();
	void insert(T d);
	void display(int c=1);
	int height(Node* t);
	void displayleaves(Node *t);
	void inorder(Node *t);
	void preorder(Node *t);
	void postorder(Node *t);
	void levelorder(Node *t);
	// Node* copy(Node *t);
	int isempty();
};

template <class T>
BinaryTree<T>::BinaryTree() {
	// TODO Auto-generated constructor stub
	root = new Node;
	root->data = -1;
	hl=0;
	hr=0;
}

template <class T>
BinaryTree<T>::~BinaryTree() {
	// TODO Auto-generated destructor stub
	delete root;
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

template <class T>
int BinaryTree<T>::height(Node *temp)
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

template <class T>
void BinaryTree<T>::displayleaves(Node *temp)
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

// template <class T>
// Node* BinaryTree<T>::copy(Node *temp)
// {
// 	Node *t;
// 	if(root != NULL)
// 	{
// 		t = new Node;
// 		t->data = temp->data;
// 		t->left = copy(temp->left);
// 		t->right = copy(temp->right);
// 	}
// 	return t;
// }

int main()
{
BinaryTree<int> tree;
int choice,temp,ch=0;

	do
	{
		cout<<"\n\n\n ____________________________________";
        cout<<"\n|                                    |";
		cout<<"\n|                MENU                |";
		cout<<"\n|____________________________________|";
        cout<<"\n|                                    |";
		cout<<"\n|  1. Insert a new Node              |";
		cout<<"\n|  2. Display all Nodes in the Tree  |";
		cout<<"\n|  3. Depth of the Tree              |";
		cout<<"\n|  4. Display leaf Nodes             |";
		cout<<"\n|  5. Copy                           |";
		cout<<"\n|  6. Exit                           |";
        cout<<"\n|____________________________________|";
		cout<<"\n Enter your choice - ";
		cin>>choice;

		switch(choice)
		{
			case 1:
                cout<<"\n Enter the data for new node - ";
                cin>>temp;
				tree.insert(temp);
				break;
			case 2:
                if(tree.isempty())
                {
                    cout<<"\n Tree is empty ";
                    break;
                }
                ch = 0;
                while(ch == 0)
				{
                    cout<<"\n Please select the traversal algorithm for the tree - ";
                    cout<<"\n 1. Inorder \n 2. Preorder \n 3. Postorder \n 4. Levelorder - ";
                    cin>>ch;
                    if(ch<1 || ch>4)
                    {
                        ch = 0;
                        cout<<"\n Please Enter a valid choice, Try Again !";
                    }
                }
                tree.display(ch);
				break;
			case 3:
                cout<<"\n\n The current height of the tree is - "<<tree.height(tree.root);
				break;
			case 4:
				cout<<"\n\n Root nodes of the trees are - ";
				tree.displayleaves(tree.root);
				break;
			case 5:
				// BinaryTree<int>::Node *temp;
				// cout<<"\n\n New Copied tree is - ";
				// temp = tree.copy(tree.root);
				// tree.levelorder(temp);
				break;
			case 6:
				return 0;
            default:
                cout<<"\n Please Enter a valid choice, Try Again !";
                break;
		}
	}while(1);
}
