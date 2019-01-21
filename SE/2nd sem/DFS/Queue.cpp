
/*
 * Queue.cpp
 *
 *  Created on: 17-Jan-2019
 *      Author: h11
 */

#include "Queue.h"
#include <iostream>

using namespace std;

template <class T>
Queue<T>::Queue() {
	// TODO Auto-generated constructor stub
	front = NULL;
	rear = NULL;
	length = 0;
}

template <class T>
Queue<T>::~Queue() {
	// TODO Auto-generated destructor stub
	while(!isempty())
		dequeue();
}

template <class T>
int Queue<T>::isempty()
{
	if(rear == NULL && front == NULL)
		return 1;
	else
		return 0;
}

template <class T>
int Queue<T>::isfull()
{
	cout<<"\n No limit carry on ";
	return 0;
}

template <class T>
void Queue<T>::enqueue(T ob, int p)
{
	struct Node *temp = new struct Node;
	temp->obj = ob;
	temp->priority = p;
	length++;

	if(isempty())
	{
		rear = temp;
		front = temp;
	}
	else
	{
		rear->next = temp;
		rear = rear->next;
	}
}

template <class T>
T Queue<T>::dequeue()
{
	if(!isempty())
	{
		struct Node *max = front;
		struct Node *temp = front->next;

		while(temp!=NULL)
		{
			if(temp->priority > max->priority)
				max = temp;
			temp = temp->next;
		}
		return max;
	}

	return NULL;
}


template <class T>
T* Queue<T>::display()
{
	T * arr = new T[length];
	struct Node* temp = front;
	if(!isempty())
	{
		for(int i = 0;temp!=NULL;i++)
		{
			arr[i] = temp->obj;
			temp = temp->next;
		}
		return arr;
	}
	return NULL;
}


