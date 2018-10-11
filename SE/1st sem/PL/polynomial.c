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

struct Node* getNode(int exp, float coeff)
{
	struct Node *temp;
	temp = (struct Node *) malloc(sizeof(temp));
	temp->exp = exp;
	temp->coeff = coeff;
	temp->next = NULL;
	return temp;
}

void display(struct Node *h)
{
	while(h != NULL)
	{
		printf(" %d + ", h->data);
		h = h->next;
	}
}

Node * insert(Node * head, Node *p)
{
	if(head == NULL)
	{
		head = p;
		head->next = NULL;
		return head;
	}
	if(head->exp < p->exp)
	{
		p->next = head;
		p = head;
	}
}

Node * create_poly(Node * head)
{
	int n, ex;
	float co;
	printf("\n How many elements do you want to enter - ");
	scanf("%d", &n);

	printf("\n\n Enter the coefficient and exponent - ");
	scanf("%f %d", &co, &ex);

	Node * p = getNode(ex, co);
	head = insert(head, p);
}

int main(void) {

	int i, n, ch, pos;
	struct Node *p, *head=NULL;

	printf("\n Creating the Head -");

	head = getNode();

	p = head;

	for(i = 0; i < n; i++)
	{
		p->next = getNode();
		p = p->next;
	}

	do
	{
		printf("\n\n\n MENU - ");
		printf("\n 1. Insert at front");
		printf("\n 2. Insert in middle");
		printf("\n 3. Insert at last");
		printf("\n 4. Delete from front");
		printf("\n 5. Delete from middle");
		printf("\n 6. Delete from last");
		printf("\n 7. Revert the list");
		printf("\n 8. Reverse the list");
		printf("\n 9. Display the list");
		printf("\n 10. Exit");
		printf("\n Enter your choice - ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
					printf("\n\n Inserting at front - \n");
					head = insert_front(head);
					break;
			case 2:
					printf("\n\n Inserting in middle - Enter the position - ");
					scanf("%d", &pos);
					head = insert_middle(head, pos);
					break;
			case 3:
					printf("\n\n Insertion at last - \n");
					head = insert_last(head);
					break;
			case 4:
					printf("\n\n Deletion at first - \n");
					head = delete_front(head);
					printf("\n Deleted successfully");
					break;
			case 5:
					printf("\n\n Deletion at middle - Enter the position \n");
					scanf("%d", &pos);
					head = delete_middle(head, pos);
					printf("\n Deleted successfully");
					break;
			case 6:
					printf("\n\n Deletion at end - \n");
					head = delete_last(head);
					printf("\n Deleted successfully");
					break;
			case 7:
					printf("\n\n Reverting your list - ");
					head = revert(head);
					display(head);
					break;
			case 8:
					printf("\n\n Reversing your list - ");
					reverse(head);
					printf("\n\n Original list - ");
					display(head);
					printf(" NULL ");
					break;
			case 9:
					printf("\n\n Your List - \n");
					display(head);
					printf(" NULL ");
					break;
			case 10:
					return 0;
			default:
					printf("\n Please enter a valid option");
		}
	}while(1);

	return 0;
}
