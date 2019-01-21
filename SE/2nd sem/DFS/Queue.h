/*
 * Queue.h
 *
 *  Created on: 17-Jan-2019
 *      Author: Devashish Krishna Prasad
 */

#ifndef QUEUE_H_
#define QUEUE_H_

template <class T>
class Queue {
	struct Node
	{
		T obj;
		int priority;
		struct Node * next;
	};
	struct Node * front;
	struct Node * rear;
	int length;

public:
	Queue();
	virtual ~Queue();
	struct node * getnode();
	int isempty();
	int isfull();
	void enqueue(T obj, int p);
	T dequeue();
	T* display();
};

#endif /* QUEUE_H_ */
