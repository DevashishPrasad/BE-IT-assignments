#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char data;
    struct Node *next,*prev;
}Node;

void display(Node * head)
{
    Node * ptr = head;
    printf("NULL <- %c -> ", head->data);
    while(ptr = ptr->next)
        printf(" <- %c -> ", ptr->data);
    printf("NULL");
}

Node * getnode()
{
    Node * new = (Node *) malloc(sizeof(Node));
    
    new->next = NULL;
    new->prev = NULL;

    return new;
}

Node * infront(Node *head)
{
    Node *t;
    char c;
    
    printf("\n Enter the data - ");
    scanf("%c",&c);
    scanf("%c",&c);

    t = getnode();
    t->data = c;
    t->next = head;
    head->prev = t;
    head = t;
    return head;
}

Node * inmiddle(Node *head)
{
    Node *ptr = head, *t,*temp;
    int i,pos;
    char c;
    
    printf("\n Enter the data - ");
    scanf("%c",&c);
    scanf("%c",&c);
    printf("\n Enter the position - ");
    scanf("%d",&pos);

    for(i = 1; i < pos; i++)
        ptr = ptr->next;

    t = getnode();
    t->next = ptr->next; 
    temp = t -> next;
    ptr->next = t;
    t->prev = ptr;
    temp->prev = t;
    
    t-> data = c;

    return head;
}

Node * inlast(Node *head)
{
    Node *ptr = head, *t;
    
    char c;
    
    printf("\n Enter the data - ");
    scanf("%c",&c);
    scanf("%c",&c);

    while(ptr->next != NULL)
        ptr = ptr->next;
    
    t = getnode();
    ptr->next = t;
    t->prev = ptr;
    t->data = c;

    return head;
}

Node * delfront(Node *head)
{
    Node *ptr = head;
    head = ptr->next;
    ptr->next->prev = head;
    free(ptr);
    
    return head;
}

Node * delmiddle(Node *head)
{
    Node *temp = head, *temp1, * temp2;
    int flg = 0, pos, i;

    printf("\n Enter the position - ");
    scanf("%d",&pos);

    for(i = 1; i < pos; i++)
        temp = temp->next;

    temp1 = temp->prev;
    temp2 = temp->next; 
    temp1->next = temp2;
    temp2->prev = temp1;

    return head;
}

Node * dellast(Node *head)
{
    Node *ptr = head, *t;
    while(ptr->next != NULL)
    {
        t = ptr;
        ptr = ptr->next;
    }

    t->next = NULL;
    free(ptr);

    return head;
}

void revert(Node * head)
{
    Node *ptr = head;

    while(ptr->next != NULL)
        ptr = ptr->next;
    
    while(ptr != NULL)
    {
        printf(" %c ",ptr->data);
        ptr = ptr->prev;
    }
}
void main()
{
    int ch, l, i;
    char str[20];

    Node *head = getnode(), *t;
    
    printf("\n Enter your name - ");
    scanf("%s",&str);

    l = strlen(str);

    head->data = str[0];
    t = head;

    for(i = 1; i < l; i++)
    {
        t->next = getnode();
        t->next->prev = t;
        t = t->next;
        t->data = str[i];
    }

    while(1)
    {

        printf("\n\n\n -------- MENU ---------");
        printf("\n 1. Display ");
        printf("\n 2. Infront ");
        printf("\n 3. Inmiddle ");
        printf("\n 4. Inlast ");
        printf("\n 5. Delfront ");
        printf("\n 6. Delmiddle ");
        printf("\n 7. Dellast ");
        printf("\n 8. revert ");
        printf("\n -------------------------");
        printf("\n Enter your choice - ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                    display(head);      
                    break;
            case 2:
                    head = infront(head);
                    break;
            case 3:
                    head = inmiddle(head);
                    break;
            case 4: 
                    head = inlast(head);
            case 5:
                    head = delfront(head);
                    break;
            case 6:
                    head = delmiddle(head);
                    break;
            case 7: 
                    head = dellast(head);
                    break;
            case 8:
                    revert(head);
                    break;
            default:
                    printf("\n Please enter the valid choice number ");
        }
    }
}