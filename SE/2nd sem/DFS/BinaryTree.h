/*
 * BinaryTree.h
 *
 *  Created on: 31-Jan-2019
 *      Author: h11
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

typedef struct Node{
		struct Node *left;
		struct Node *right;
		int data;
}Node;

class BinaryTree {
	int hl,hr;
	Node *root;
public:
	Node* getroot();
	BinaryTree();
	virtual ~BinaryTree();
	void insert(int d);
	void display(int c=1);
	int height(Node* t);
	void displayleaves(Node *t);
	void inorder(Node *t);
	void preorder(Node *t);
	void postorder(Node *t);
	void levelorder(Node *t);
	Node* copy(Node *t);
	int isempty();
};

#endif /* BINARYTREE_H_ */
