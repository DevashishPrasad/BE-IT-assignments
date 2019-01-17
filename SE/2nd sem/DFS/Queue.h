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
		struct node * next;
	};

	struct node * front;
	struct node * rear;

public:
	Queue();
	virtual ~Queue();
	struct node * getnode();
	int isempty();
	int isfull();
	void enqueue(T obj);
	int dequeue();
};

#endif /* QUEUE_H_ */
