/*
 ============================================================================
 Name        : linked.c
 Author      : Devashish
 Version     : 1.0
 Copyright   : GNU Public Licence
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int exp;
	float coeff;
	struct Node *next;

}Node;

Node* getNode(int exp, float coeff)
{
	Node *temp;
	temp = (struct Node *) malloc(sizeof(temp));
	temp->exp = exp;
	temp->coeff = coeff;
	temp->next = NULL;
	return temp;
}

void display(Node *h)
{
	struct Node *p = h;
	while(p->next != h)
	{
		printf(" %fx^%d + ", p->coeff, p->exp);
		p = p->next;
	}
	printf(" %fx^%d", p->coeff, p->exp);
}

Node * insert(Node * head, Node *p)
{
	if(head == NULL)
	{
		head = p;
		head->next = p;
		return head;
	}

	Node *t = head;
	
	if(head->exp < p->exp)
	{
		p->next = head;
		
		while(t->next != head)
			t = t->next;
		
		t->next = p;
		head = p;

		return head;
	}
	while(t->next != head && p->exp <= t->exp)
		t = t->next;
	
	if(p->exp == t->exp)
		t->coeff += p->coeff;
	else
	{
		p->next = t->next;
		t->next = p;
	}

	return head;
}

Node * create_poly(Node * head)
{
	int n, ex, i;
	float co;
	printf("\n How many elements do you want to enter - ");
	scanf("%d", &n);

	Node * p;
	
	for(i = 0; i<n; i++)
	{
		printf("\n\n Enter the coefficient and exponent of %d term - ",i+1);
		scanf("%f %d", &co, &ex);
		p = getNode(ex, co);
		head = insert(head, p);
	}

	return head;
}


Node * addition(Node * head, Node *head2, Node* head3)
{
	Node * p = head;
	do
	{
		head3 = insert(head3, p);
		// printf("skdjdskjsdkjk0\n");
		p = p->next;	
	}while(p != head);

	// p = head2;
	
	// do
	// {
	// 	head3 = insert(head3, p);
	// 	printf("skdjdskjsdkjk1 ");
	// 	p = p->next;
	// }while(p != head2);
	
	return head3;
}


int main(void) {
	
	int ch;

	Node* head = NULL;
	Node* head2 = NULL;
	Node* head3 = NULL;

	do
	{
		printf("\n\n\n MENU - ");
		printf("\n 1. Create LL");
		printf("\n 2. Addition");
		printf("\n 3. Multiplication");
		printf("\n 4. Display");
		printf("\n 5. Exit");
		printf("\n Enter your choice - ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
					head = create_poly(head);
					break;
			case 2:
					printf("\n\n Please enter second polynomial - ");
					head2 = create_poly(head2);
					// display(head2);
					head3 = addition(head, head2, head3);
					display(head3);
					break;
			// case 3:
			// 		printf("\n\n Insertion at last - \n");
			// 		head = insert_last(head);
			// 		break;
			case 4:
					printf("\n\n Your List - \n\n");
					display(head);
					break;
			case 5:
					return 0;
			default:
					printf("\n Please enter a valid option");
		}
	}while(1);

	return 0;
}
