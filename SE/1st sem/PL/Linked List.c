/*
 ============================================================================
 Name        : linked.c
 Author      : Devashish (23364)
 Version     : 1.0
 Copyright   : GNU Public Licence
 Description : Create a singly linked list with following operations - 
	       1) Insert (at front, middle, end)
	       2) Delete (at font, middle, end)
	       3) Display in reverse
	       4) Revert the Linked list
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node* getNode()
{
	struct Node *temp;
	temp = (struct Node *) malloc(sizeof(temp));
	printf("\n Enter the data for the Node - ");
	scanf("%d", &temp->data);
	temp->next = NULL;
	return temp;
}

void display(struct Node *h)
{
	while(h != NULL)
	{
		printf(" %d -> ", h->data);
		h = h->next;
	}
	printf(" NULL ");
}

struct Node * insert_front(struct Node* head)
{
	struct Node *t;
	t = getNode();
	t->next = head;
	head = t;
	return head;
}

struct Node * insert_middle(struct Node* head, int pos)
{
	struct Node *t, *p;
	int i;

	t = getNode();
	p = head;
	for(i = 0; i < pos-2 && p->next != NULL ; i++)
		p = p->next;
	t->next = p->next;
	p->next = t;

	return head;
}

struct Node * insert_last(struct Node* head)
{
	struct Node *t, *p;
	t = getNode();
	p = head;
	while(p->next != NULL)
		p = p->next;
	p->next = t;

	return head;
}

struct Node * delete_front(struct Node* head)
{
	struct Node *t;
	t = head;
	head = head->next;
	free(t);
	return head;
}

struct Node * delete_middle(struct Node* head, int pos)
{
	struct Node *t, *p;
	int i;
	p = head;
	t = head;
	for(i = 0; i < pos-1 && p->next != NULL; i++)
	{
		t = p;
		p = p->next;
	}
	t->next = p->next;
	free(p);

	return head;
}

struct Node * delete_last(struct Node* head)
{
	struct Node *t, *p;
	p = head;
	t = head;
	while(p->next != NULL)
	{
		t = p;
		p = p->next;
	}
	t->next = p->next;
	free(p);
	return head;
}

struct Node * revert (struct Node * head)
{
	struct Node *c, *t, *r;
	t = NULL;
	c = head;
	r = NULL;

	if(head->next == NULL)
		return head;

	while(c != NULL)
	{
		t = c->next;
		c->next = r;
		r = c;
		c = t;
	}

	head = r;
	return head;
}

void reverse (struct Node * head)
{
	if(head != NULL)
	{
		reverse(head->next);
		printf(" %d ", head->data);
	}
}

int main(void) {

	int i, n, ch, pos;
	struct Node *p, *head=NULL;

	printf("\n Creating the Head -");

	head = getNode();

	printf("\n How many elements do you want to enter - ");
	scanf("%d", &n);

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
					break;
			case 9:
					printf("\n\n Your List - \n");
					display(head);
					break;
			case 10:
					return 0;
			default:
					printf("\n Please enter a valid option");
		}
	}while(1);

	return 0;
}
