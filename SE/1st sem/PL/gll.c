#include <stdio.h>
#include <stdlib.h>
#define max 4

typedef struct Node
{
    struct Node* next;
    int flag;
    union
    {
        char data[max];
        struct Node *dlink;
    }u;
}Node;

Node * getNode()
{
    Node * new1 = (Node *) malloc(sizeof(Node));
    new1->next = NULL;
    new1->u.dlink = NULL;
    return new1;
}

Node* create_GLL(Node * head, char str[])
{
    int i,j;

    Node * temp;

    for(i = 0; str[i]!= '\0'; i++)
    {
        if(str[i] == '(' && i==0)
        {
            head = getNode();
            temp = head;
        }
        else
        {
            temp->next = getNode();
            temp = temp->next;
        }
        i++;
        j=0;
        while(str[i] != ',' && str[i] != '(' && str[i]!=')')
        {
            temp->u.data[j] = str[i];
            i++;
            j++;
        }

        temp->u.data[j] = '\0';
        temp-> flag = 0;

        if(str[i] == '(')
        {
            temp->next = getNode();
            temp  = temp->next;
            temp->flag = 1;
            temp->u.dlink = create_GLL(NULL, &str[i]);

            while(str[i] != ')')
                i++;
            i++;
        }
        if(str[i] == ')')
            return head;
    }
}

void display(Node * temp)
{
    static int depth;
    depth++;
    int i;

    if(temp == NULL)
    {
        if(depth == 1)
            printf(" List is empty ");
        else
            printf(" Sublist is empty ");
    }
    else
    {
        while(temp != NULL)
        {
            if(temp->flag == 0)
            {
                printf("\n");
                for(i = 1; i<=depth; i++)
                    printf(" ");
                printf("%s", temp->u.data);
            }
            else
            {
                display(temp->u.dlink);
            }
            temp = temp -> next;
        }
    }
    depth--;
}
int main()
{
    Node *head = NULL;
    char str[51], repeat = 'n';

    do
    {
        printf("\n  Enter the book index tring to be coverted to GLL");
        scanf("\n");
        gets(str);

        printf("The book index is - ");
        head = create_GLL(head, str);
        display(head);

        printf("\n Do you want to try again(y/n)");
        scanf("%c", &repeat);
    }while(repeat == 'y');

    return 0;
}