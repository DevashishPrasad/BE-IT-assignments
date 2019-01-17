//============================================================================
// Name        : Assignment1.cpp
// Author      : Devashish K Prasad
// Version     : 1.0
// Copyright   : General Public License
// Description :
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "StackLL.h"
#include "StackLL.cpp"

using namespace std;

// Reversing the expression
void reverse(char str[25])
{
	int len = strlen(str);

	for(int i=0; i<len/2; i++)
		swap(str[i],str[(len-1)-i]);

	for(int i=0; i<len;i++)
	{
		if(str[i] == '(')
			str[i] = ')';
		else if(str[i] == ')')
			str[i] = '(';
	}
}

// Checking left associativity
int lasso(char op)
{
	if(op == '^')
		return 0;
	else
		return 1;
}

// Priority of operators
int priority(char op)
{
	switch(op)
	{
		case '^':
			return 4;
		case '%':
			return 3;
		case '*':
			return 2;
		case '/':
			return 2;
		case '+':
			return 1;
		case '-':
			return 1;
		case '(':
			return 0;
	}
}

// Determine the character is operand operator or parenthesis
int determine(char ch)
{
	if((ch >= 65 && ch <= 91) || (ch >= 97 && ch <= 123) || (ch >= 48 && ch <= 57))
		return 1;
	else if(ch == 40)// (
		return 2;
	else if(ch == 41)// )
		return 3;
	else
		return 0;
}

// Function of postfix and prefix conversion
// if pushorpop bit is set then postfix conversion
// else prefix conversion
void infix2postpre(char exp[25], char res[25], int pushorpop)
{
	StackLL <char>s;
	char ch;
	int k = 0;

	if(pushorpop == 0)
		reverse(exp);

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
							res[k] = s.pop();
							k++;
						}
						while(priority(s.peep()) > priority(ch) &&  !lasso(ch))
						{
							res[k] = s.pop();
							k++;
						}
					}
					else
					{
						while(priority(s.peep()) >= priority(ch) && !lasso(ch))
						{
							res[k] = s.pop();
							k++;
						}
						while(priority(s.peep()) > priority(ch) && lasso(ch))
						{
							res[k] = s.pop();
							k++;
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
				res[k] = ch;
				k++;
				break;
			case 2:
				s.push(ch);
				break;
			case 3:
				while(s.peep() != '(')
				{
					res[k] = s.pop();
					k++;
				}
				if(s.peep()=='(')
				s.pop();
				break;
		}
	}

	while(!s.isempty())
	{
			res[k] = s.pop();
			k++;
	}

	if(pushorpop == 0)
		reverse(res);

	res[k] = '\0';
}

// perform operation
float performop(float op1, float op2, char op)
{
	switch(op)
	{
		case '+':
			return (op1 + op2);
		case '-':
			return (op1 - op2);
		case '*':
			return (op1 * op2);
		case '/':
			return (op1 / op2);
		case '%':
			return ((int)op1 % (int)op2);
		case '^':
			return pow(op1,op2);
	}
}

// function for evaluating an expression
void evaluate(char exp[25], int postpre)
{
	char ch;
	float op1,op2,t;
	StackLL <float>s;

	for(int i=0; exp[i]; i++)
	{
		ch = (char) exp[i];

		int control = determine(ch);

		if(control > 0)
		{
			t = ch - '0';
			s.push(t);
		}
		else
		{
			op1 = s.pop();
			op2 = s.pop();
			if(postpre)
				s.push(performop(op2,op1,ch));
			else
				s.push(performop(op1,op2,ch));
		}
	}

	cout<<"\n The evaluated result is - "<<s.pop();
}

// validation for conversion
int validate(char exp[25])
{
	int len = strlen(exp);
	int bracket = 0;
	int ch;

	if((exp[0] == 40))
		ch = 2;
	else if(isalpha(exp[0]) || (exp[0] == 40) || (exp[0] == 41))
		ch = 1;
	else
		return 0;

	for(int i=0; i<len; i++)
	{
		if(exp[i]=='(')
			bracket++;
		if(exp[i]==')')
			bracket--;
		if(isalpha(exp[i]) || (exp[i] >= 40 && exp[i] <= 43) || (exp[i]!=45)
		|| (exp[i]!=47) || (exp[i] != 94))
		{

		}
		else
		{
			return 0;
		}
		if(i>0 && ch==3 && isalpha(exp[i]))
			return 0;
		if(i>0 && ch==2 && ((exp[i] >= 41 && exp[i] <= 43) || (exp[i]==45) || (exp[i]==47)
						|| (exp[i] == 94) || (exp[i] == 37)))
			return 0;
		else if(i>0 && ch==1 && isalpha(exp[i]))
			return 0;
		else if(i>0 && ch==0 && ((exp[i] >= 41 && exp[i] <= 43) || (exp[i]==45) || (exp[i]==47)
						|| (exp[i] == 94) || (exp[i] == 37)))
			return 0;
		if((exp[i] == 41))
			ch = 3;
		else if((exp[i] == 40))
			ch = 2;
		else if(isalpha(exp[i]))
			ch = 1;
		else
			ch = 0;
	}

	if(bracket == 0)
		return 1;
	else
		return 0;

	return 1;
}


// validation for evaluation
int evalidate(char exp[25])
{
	int len = strlen(exp);
	int bracket = 0;
	int ch;

	if((exp[0] == 40))
		ch = 2;
	else if(isdigit(exp[0]) || (exp[0] == 40) || (exp[0] == 41))
		ch = 1;
	else
		return 0;

	for(int i=0; i<len; i++)
	{
		if(exp[i]=='(')
			bracket++;
		if(exp[i]==')')
			bracket--;
		if(isdigit(exp[i]) || (exp[i] >= 40 && exp[i] <= 43) || (exp[i]!=45)
		|| (exp[i]!=47) || (exp[i] != 94))
		{

		}
		else
		{
			return 0;
		}
		if(i>0 && ch==3 && isdigit(exp[i]))
			return 0;
		if(i>0 && ch==2 && ((exp[i] >= 41 && exp[i] <= 43) || (exp[i]==45) || (exp[i]==47)
						|| (exp[i] == 94) || (exp[i] == 37)))
			return 0;
		else if(i>0 && ch==1 && isdigit(exp[i]))
			return 0;
		else if(i>0 && ch==0 && ((exp[i] >= 41 && exp[i] <= 43) || (exp[i]==45) || (exp[i]==47)
						|| (exp[i] == 94) || (exp[i] == 37)))
			return 0;


		if((exp[i] == 41))
			ch = 3;
		else if((exp[i] == 40))
			ch = 2;
		else if(isdigit(exp[i]))
			ch = 1;
		else
			ch = 0;
	}

	if(bracket == 0)
		return 1;
	else
		return 0;

	return 1;
}

// get expression from user
// if evalorconvert is set then perform validation for evaluation
// else perform validation for conversion
void getexpression(char exp[25], int evalorconvert)
{
	int temp = 1;

	while(temp)
	{
		cout<<"\n\n Enter the expression in infix - ";
		cin>>exp;

		if(evalorconvert)
		{
			if(!evalidate(exp))
				cout<<"\n Invalid expession.... Please try again ! ";
			else
				break;
		}
		else
		{
			if(!validate(exp))
				cout<<"\n Invalid expession.... Please try again ! ";
			else
				break;
		}
	}
}

int main() {

	int ch;
	char exp[25], res[25];

	do
	{
		cout<<"\n --------- MENU ---------";
		cout<<"\n 1. Infix to Postfix  ";
		cout<<"\n 2. Infix to Prefix  ";
		cout<<"\n 3. Postfix Evaluation ";
		cout<<"\n 4. Prefix Evaluation ";
		cout<<"\n 5. Exit ";
		cout<<"\n ENTER YOUR CHOICE NUMBER - ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				getexpression(exp,0);
				infix2postpre(exp,res,1);
				cout<<"\n The postfix expression is - "<<res;
				break;
			case 2:
				getexpression(exp,0);
				infix2postpre(exp,res,0);
				cout<<"\n The prefix expression is - "<<res;
				break;
			case 3:
				getexpression(exp,1);
				infix2postpre(exp,res,1);
				evaluate(res, 1);
				break;
			case 4:
				getexpression(exp,1);
				infix2postpre(exp,res,0);
				reverse(res);
				evaluate(res, 0);
				break;
			case 5:
				return 0;
		}
	}while(1);

	return 0;
}
