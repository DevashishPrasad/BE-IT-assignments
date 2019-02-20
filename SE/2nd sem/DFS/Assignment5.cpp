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
	int hl,hr;
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

		if(root == NULL)
		{
			root = new Node;
			root->left = NULL;
			root->right = NULL;
			root->data = d;
			cout<<"\n Root node added successfully";
			return;
		}
		int i=0;
		while(1)
		{
			i++;
			if(d > temp->data)
			{
				if(temp->right == NULL)
				{
					temp->right = new Node;
					temp = temp->right;
					temp->left = NULL;
					temp->right = NULL;
					temp->data = d;
					cout<<"\n\n INFO: Data was inserted in the tree successfully at level "<<i;
					return;
				}
				temp = temp->right;
			}
			else if(d < temp->data)
			{
				if(temp->left == NULL)
				{
					temp->left = new Node;
					temp = temp->left;
					temp->left = NULL;
					temp->right = NULL;
					temp->data = d;
					cout<<"\n\n INFO: Data was inserted in the tree successfully at level "<<i;
					return;
				}
				temp = temp->left;
			}
			else
			{
				cout<<"\n\n INFO: Cannot insert given data, duplicate data values not allowed";
				return;
			}
		}
	}

	void remove(int d)
	{
		root = deleteNode(root,d);
	}

	Node* deleteNode(Node *root, int key)
	{
		if (root == NULL) return root;
	    if (key < root->data)
	        root->left = deleteNode(root->left, key);
	    else if (key > root->data)
	        root->right = deleteNode(root->right, key);
	    else
	    {
	        if (root->left == NULL)
	        {
	            Node *temp = root->right;
	            delete root;
				cout<<"\n\n  INFO: Node deleted successfully ! ";
	            return temp;
	        }
	        else if (root->right == NULL)
	        {
	            Node *temp = root->left;
	            delete root;
				cout<<"\n\n  INFO: Node deleted successfully ! ";
	            return temp;
	        }

	        Node* temp = minValueNode(root->right);
	        root->data = temp->data;
	        root->right = deleteNode(root->right, temp->data);

	    }

		cout<<"\n\n  INFO: Node not found in the tree ! ";

	    return root;
	}

	Node* minValueNode(Node* node)
	{
	    Node* current = node;

	    while (current->left != NULL)
	        current = current->left;

	    return current;
	}

	void search(int d)
	{
		Node *temp = root;

		while(temp)
		{
			if(temp->data == d)
			{
				cout<<"\n\n INFO: Data was successfully found in the tree";
				return;
			}
			else if(d > temp->data)
				temp = temp->right;
			else if(d < temp->data)
				temp = temp->left;
		}

		cout<<"\n\n INFO: Cannot find given data in the tree";
		return;
	}

	Node* mirrorImage(Node *root){
		Node *temp;
		if(root != NULL)
		{
			temp = root->left;
			root->left = root->right;
			root->right = temp;
			mirrorImage(root->left);
			mirrorImage(root->right);
		}
		return root;
	}
	void mirror(Node* temp)
	{
		root = mirrorImage(root);
	}

	void display(int d=1)
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
			case 4:
				cout<<"\n\n INFO: Level Order Traversal of the Tree - ";
				levelorder(root);
				break;
			default:
				break;
		}
	}

	int height(Node *temp)
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
			if (temp->left != NULL) {
				q.enqueue(temp->left,1);
			}
			if (temp->right != NULL) {
				q.enqueue(temp->right,1);
			}
			if (q.isempty())
				temp = NULL;
			else
				temp = q.dequeue();
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
					ch = 0;
					while(ch == 0)
					{
						cout<<"\n\n Select the traversal \n 1. Inorder \n 2. Preorder \n 3. Postorder \n 4. Level order \n Enter your choice - ";
						cin>>ch;
						if(ch < 1 || ch > 4)
						{
							cout<<"\n\n Please enter a valid choice Try again ";
							ch = 0;
						}
					}
					bst.display(ch);
					break;
			case 6:
					bst.display(4);
					break;
			case 7:
					cout<<"\n\n Height of the BST is - "<<bst.height(bst.getRoot());
					break;
			case 8:
					return 0;
            default:
	                cout<<"\n\n INFO: Please Enter a valid choice, Try Again !";
	                break;
		}
	}while(1);
}
