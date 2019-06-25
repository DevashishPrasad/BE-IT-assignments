/*
 * StackLL.h
 *
 *  Created on: 20-Dec-2018
 *      Author: ml-18
 */

#ifndef STACKLL_H_
#define STACKLL_H_

namespace std {

template <class T>
class StackLL {

	struct Node
	{
		T data;
		struct Node * next;
	};
	struct Node* top;
	int max;

public:

	StackLL();
	virtual ~StackLL();
	void push(T d);
	T pop();
	int isfull();
	int isempty();
	int amount();
	T peep();
};

} /* namespace std */

#endif /* STACKLL_H_ */
