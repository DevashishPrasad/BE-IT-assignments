//============================================================================
// Name        : Assignment4.cpp
// Author      : Devashish
// Version     :
// Copyright   : GNU Public Lincense
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include "StackLL.cpp"
#include "StackLL.h"
using namespace std;




//======================= Structure for Tree Node ==========================
typedef struct Node{
	struct Node *left;
	struct Node *right;
	char data;
}Node;
//============================ Structure End ================================





//======================== Global Stack Instance ===========================
StackLL<Node*> stack;
//==========================================================================





//=========================VV Custom Functions VV===============================

//======= Determine the character is operand operator or parenthesis =========
int determine(char ch)
{
	if((ch >= 65 && ch <= 91) || (ch >= 97 && ch <= 123) || (ch >= 48 && ch <= 57))
		return 1;
	else if(ch == 40)// ASCII for (
		return 2;
	else if(ch == 41)// ASCII for )
		return 3;
	else
		return 0;
}
//============================== End Determine  ==============================






//============================ Class for Tree ===============================
class BinaryTree {
	int hl,hr;
	Node *root;
	void rinorder(Node *t);
	void rpreorder(Node *t);
	void rpostorder(Node *t);
	void nrinorder();
	void nrpreorder();
	void nrpostorder();
public:
	Node* getroot();
	BinaryTree();
	virtual ~BinaryTree();
	void create(char* exp);
	void displayNoRecur(int c=1);
	void displayRecur(int c=1);
	int isempty();
};

BinaryTree::BinaryTree() {
	root = NULL;
	hl=0;
	hr=0;
}

BinaryTree::~BinaryTree() {
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

void BinaryTree::create(char* exp)
{
	for(int i=0;exp;i++)
	{
		if(determine(exp[i]) == 1)
		{
			Node *newNode = new Node;
			newNode->data = exp[i];
			stack.push(newNode);
		}
		if(determine(exp[i]) == 0)
		{
			Node *newNode = new Node;
			newNode->right = stack.pop();
			newNode->left = stack.pop();
			stack.push(newNode);
		}
	}
	root = stack.pop();
}

void BinaryTree::displayRecur(int c)
{
	Node *temp = root;
	switch (c)
	{
		case 1:
			cout<<"\n In Order Traversal of the Tree - ";
			rinorder(temp);
			break;
		case 2:
			cout<<"\n Pre Order Traversal of the Tree - ";
			rpreorder(temp);
			break;
		case 3:
			cout<<"\n Post Order Traversal of the Tree - ";
			rpostorder(temp);
			break;
		default:
			break;
	}
}

void BinaryTree::displayNoRecur(int c)
{
	Node *temp = root;
	switch (c)
	{
		case 1:
			cout<<"\n In Order Traversal of the Tree - ";
			nrinorder();
			break;
		case 2:
			cout<<"\n Pre Order Traversal of the Tree - ";
			nrpreorder();
			break;
		case 3:
			cout<<"\n Post Order Traversal of the Tree - ";
			nrpostorder();
			break;
		default:
			break;
	}
}


//====================== Recursive tree traversals ===================
void BinaryTree::rinorder(Node *temp)
{
	if(temp!=NULL)
	{
		rinorder(temp->left);
		cout<<" "<<temp->data<<" ";
		rinorder(temp->right);
	}
}

void BinaryTree::rpreorder(Node *temp)
{
	if(temp!=NULL)
	{
		cout<<" "<<temp->data<<" ";
		rpreorder(temp->left);
		rpreorder(temp->right);
	}
}

void BinaryTree::rpostorder(Node *temp)
{
	if(temp!=NULL)
	{
		rpostorder(temp->left);
		rpostorder(temp->right);
		cout<<" "<<temp->data<<" ";
	}
}

//====================== Non Recursive tree traversals ===================
void BinaryTree::nrinorder()
{

}

void BinaryTree::nrpreorder()
{

}

void BinaryTree::nrpostorder()
{

}

//=========================== Class Tree Ends ================================


//=============================== Main function ===============================
int main() {
	BinaryTree tree;
	int choice,temp=0,ch=0;
	char* expr = NULL;

		do
		{
			cout<<"\n\n\n ____________________________________";
	        cout<<"\n|                                    |";
			cout<<"\n|                MENU                |";
			cout<<"\n|____________________________________|";
	        cout<<"\n|                                    |";
			cout<<"\n|  1. Enter the PostFix expression   |";
			cout<<"\n|  2. Display PostFix expression     |";
			cout<<"\n|  3. Create tree                    |";
			cout<<"\n|  4. Display Tree Non Recursive     |";
			cout<<"\n|  5. Display Tree Recursive         |";
			cout<<"\n|  6. Exit                           |";
	        cout<<"\n|____________________________________|";
			cout<<"\n Enter your choice - ";
			cin>>choice;

			switch(choice)
			{
				case 1:
					while(temp == 0)
	                {
						cout<<"\n Enter the PostFix Expression - ";
						cin>>expr;

						temp = 1;

						for(int i;expr;i++)
						{
							if(determine(expr[i]) == 3 || determine(expr[i]) == 2)
								temp = 0;
						}

						if(temp == 0)
						{
							cout<<"\n\n Invalid token found in the expression,"
							  	<<" Please try again !! ";
							continue;
						}
						else
						{
							break;
						}
	                }
					break;
				case 2:
					if(expr != NULL)
						cout<<"\n\n Your PostFix Expression is - "<<expr;
					else
						cout<<"\n\n No expression found, Please enter an Expression first ......";
					break;
				case 3:
					tree.create(expr);
					break;
				case 4:
					if(expr == NULL)
					{
						cout<<"\n No expression found, Please enter an Expression first ......";
						break;
					}
	                if(tree.isempty())
	                {
	                	cout<<"\n No tree found, Please create an Expression tree first ......";
	                	break;
	                }

	                ch = 0;
	                while(ch == 0)
					{
	                    cout<<"\n Please select the traversal algorithm for the tree - ";
	                    cout<<"\n 1. Inorder \n 2. Preorder \n 3. Postorder - ";
	                    cin>>ch;
	                    if(ch<1 || ch>3)
	                    {
	                        ch = 0;
	                        cout<<"\n Please Enter a valid choice, Try Again !";
	                    }
	                }
	                tree.displayNoRecur(ch);
					break;
				case 5:
					if(expr == NULL)
					{
						cout<<"\n No expression found, Please enter an Expression first ......";
						break;
					}
	                if(tree.isempty())
	                {
	                	cout<<"\n No tree found, Please create an Expression tree first ......";
	                	break;
	                }

	                ch = 0;
	                while(ch == 0)
					{
	                    cout<<"\n Please select the traversal algorithm for the tree - ";
	                    cout<<"\n 1. Inorder \n 2. Preorder \n 3. Postorder - ";
	                    cin>>ch;
	                    if(ch<1 || ch>3)
	                    {
	                        ch = 0;
	                        cout<<"\n Please Enter a valid choice, Try Again !";
	                    }
	                }
	                tree.displayRecur(ch);
					break;
				case 6:
					return 0;
	            default:
	                cout<<"\n Please Enter a valid choice, Try Again !";
	                break;
			}
		}while(1);
}
