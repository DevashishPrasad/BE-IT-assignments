/*
 * BinaryTree.h
 *
 *  Created on: 31-Jan-2019
 *      Author: h11
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

template <class T>
class BinaryTree {
	struct Node{
		struct Node *left;
		struct Node *right;
		T data;
	};
	struct Node *root;
public:
	BinaryTree();
	virtual ~BinaryTree();
	void insert(T d);
	void display(int c=1);
	int depth();
	void displayleaves();
	void inorder(Node *t);
	void preorder(Node *t);
	void postorder(Node *t);
	void levelorder(Node *t);
	int isempty();
	void displayRoot();
};

#endif /* BINARYTREE_H_ */
