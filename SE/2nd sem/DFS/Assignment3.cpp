//============================================================================
// Name        : Assignment3.cpp
// Author      : Devashish
// Version     : 1.0
// Copyright   : GNU Public Lincense
// Description : Binary Tree
//============================================================================

#include <iostream>
#include "BinaryTree.cpp"
#include "BinaryTree.h"

using namespace std;

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
		cout<<"\n|  5. Exit                           |";
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
                tree.displayRoot();		
				break;
			case 4:
				break;
			case 5:
				return 0;
            default:
                cout<<"\n Please Enter a valid choice, Try Again !";
                break;
		}
	}while(1);
}
