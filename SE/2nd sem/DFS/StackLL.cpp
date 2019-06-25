/*
 * StackLL.cpp
 *
 *  Created on: 20-Dec-2018
 *      Author: ml-18
 */

#include "StackLL.h"
#include <iostream>

namespace std {

template <class T>
StackLL<T>::StackLL() {
	// TODO Auto-generated constructor stub
	top = NULL;
	max = 10;
}

template <class T>
StackLL<T>::~StackLL() {
	// TODO Auto-generated destructor stub
	while(!isempty())
	{
		pop();
	}
}

template <class T>
void StackLL<T>::push(T d)
{
	if(isfull())
		cout<<"\n The stack is full";
	else
	{
		struct Node* temp = new struct Node;
		temp->data = d;
		temp->next = top;
		top = temp;
	}
}

template <class T>
T StackLL<T>::pop()
{
	if(isempty())
	{
		cout<<"\n Stack is empty";
		return 0;
	}
	else
	{
		struct Node * temp = top;
		top = temp->next;
		T d = temp->data;
		delete temp;
		return d;
	}
}

template <class T>
int StackLL<T>::isempty()
{
	if(top == NULL)
		return 1;
	return 0;
}

template <class T>
int StackLL<T>::isfull()
{
	if(amount() == max)
		return 1;
	return 0;
}

template <class T>
int StackLL<T>::amount()
{
	int cnt = 0;
	struct Node *temp = top;

	while(temp != NULL)
	{
		cnt++;
		temp = temp->next;
	}

	return cnt;
}

template <class T>
T StackLL<T>::peep()
{
	if(!isempty())
		return top->data;
		else
		return '\0';
}
} /* namespace std */
