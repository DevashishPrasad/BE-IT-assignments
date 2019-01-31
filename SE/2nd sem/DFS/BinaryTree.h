/*
 * BinaryTree.h
 *
 *  Created on: 31-Jan-2019
 *      Author: h11
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

class BinaryTree {
	struct Node{
		struct Node *left;
		struct Node *right;

	};
public:
	BinaryTree();
	virtual ~BinaryTree();

};

#endif /* BINARYTREE_H_ */
