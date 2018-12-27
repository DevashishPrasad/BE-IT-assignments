//============================================================================
// Name        : Assignment1.cpp
// Author      : Devashish K Prasad
// Version     : 1.0
// Copyright   : General Public License
// Description :
//============================================================================

#include <iostream>
#include <stdio.h>
#include "StackLL.h"
#include "StackLL.cpp"

using namespace std;

int lasso(char op)
{
	if(op == '^')
		return 0;
	else
		return 1;
}
int priority(char op)
{
	switch(op)
	{
		case '^':
			return 5;
		case '*':
			return 4;
		case '/':
			return 3;
		case '+':
			return 2;
		case '-':
			return 1;
	}
}

int determine(char ch)
{
	if((ch >= 65 && ch <= 91) || (ch >= 97 && ch <= 123))
		return 1;
	else if(ch == 40)
		return 2;
	else if(ch == 41)
		return 3;
	else
		return 0;
}

void infix2postpre(char exp[25], int pushorpop)
{
	StackLL <char>s;

	char ch;

	for(int i=0; exp[i]; i++)
	{
		ch = (char) exp[i];

		int control = determine(ch);

		switch(control)
		{
			case 0:
				if(!s.isempty())
				{
					if(pushorpop == 1)
					{
						while(priority(s.peep()) >= priority(ch) && lasso(ch))
						{				 	
							cout<<s.pop();
						}
						while(priority(s.peep()) > priority(ch) &&  !lasso(ch))
						{				 	
							cout<<s.pop();
						}
					}
					else
					{
						while(priority(s.peep()) >= priority(ch) && !lasso(ch))
						{				 	
							cout<<s.pop();
						}
						while(priority(s.peep()) > priority(ch) && lasso(ch))
						{				 	
							cout<<s.pop();
						}
					}
					s.push(ch);
				}
				else
				{
					s.push(ch);
				}
				break;
			case 1:
				cout<<ch;
				break;
			case 2:
				s.push(ch);
				break;
			case 3:
				while(s.peep() != '(')
					cout<<s.pop();
				break;
		}
	}

	while(!s.isempty())
		cout<<s.pop();
}

int main() {

	int ch;
	char exp[25];

	do
	{
		cout<<"\n --------- MENU ---------";
		cout<<"\n 1. Infix to Postfix  ";
		cout<<"\n 2. Infix to Prefix  ";
		cout<<"\n 3. Postfix Evaluation ";
		cout<<"\n 4. Prefix Evaluation ";
		cout<<"\n 5. Exit ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\n\n Enter the expression in infix - ";
				cin>>exp;
				infix2postpre(exp,1);
				break;
			case 2:
				cout<<"\n\n Enter the expression in infix - ";
				cin>>exp;
				infix2postpre(exp,0);
				break;
			case 5:
				return 0;
		}
	}while(1);

	return 0;
}
