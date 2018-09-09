/*
 ============================================================================
 Name        : string.c
 Author      : Devashish (23364)
 Version     : 1.0
 Copyright   : GNU Public Licence
 Description : String Operations without pointers
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int strln(char *a)
{
	int len=0;

	while(*a)
    {
        len++;
        *a++;
    }

	return len;
}
int strcm(char *a, char *b)
{
	int i,flg=0;

    if(strln(a) != strln(b))
        return 0;

	while(*a)
    {
        if(*a != *b)
			flg=1
        *b++;
        *a++;
    }
		
	if(flg == 0)
		return 1;
	return 0;
}
void strrv(char *a, char *b)
{
	int i,j;

	int len = strln(a);
	for(i=(len-1),j=0; i >= 0; i--,j++)
		b[j] = a[i];
}
void palindrome(char *a, char *b)
{	
	strrv(a, b);	
	int cmp = strcm(a, b);
	if(cmp == 1)
		printf("\nThe String is a palindrome\n");
	else
		printf("\nThe String is not a palindrome\n");
}
void strcp(char *a, char *b)
{
	int i;
    
	while(*a)
    {
        *b = *a;
        *b++;
        *a++;
    }
}
void substr(char *a, char *b)
{
	int i, j, flg=0;

	for(i=0,j=0; i<strln(a); i++)
	{
		if(a[i]==b[j])
		j++;
		else
		j = 0;
		if(j == strln(b))
		{
			flg = 1;
			printf("\nSubstring found\n");
		}
	}

	if(flg == 0)
	printf("\nSubstring not found\n");
}
int main(void) {

	int ch;
	char *a, *b;
    a = NULL;
    b = NULL;
	do{
		printf("\n MENU - ");
		printf("\n 1. Enter the String");
		printf("\n 2. Display String");
		printf("\n 3. Length");
		printf("\n 4. Palindrome");
		printf("\n 5. Comparison");
		printf("\n 6. Copy");
		printf("\n 7. Reverse");
		printf("\n 8. Substring");
		printf("\n 9. Exit");
		printf("\n Enter your choice - ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
					printf("\nEnter the String - ");
                    a = malloc(sizeof(char) * 50);
                    b = malloc(sizeof(char) * 50);
					scanf("%s",a);
					break;
			case 2:
					if(a == NULL)
						printf("\nString is empty\n");
					else
					{
						printf("\nYour String - ");
						printf("%s",a);
					}
					break;
			case 3:
					if(a == NULL)
						printf("\nString is empty\n");
					else
						printf("\nLength of your string is - %d\n",strln(a));
					break;
			case 4:
					if(a == NULL)
						printf("\nString is empty\n");
					else
					{
						free(b);
						b = malloc(sizeof(char) * 50);
						palindrome(a, b);
					}
					break;
			case 5:
					if(a == NULL)
						printf("\nString is empty\n");
					else
					{
						free(b);
						b = malloc(sizeof(char) * 50);
						printf("\nEnter a string to compare - ");
						scanf("%s", b);
						int cmp = strcm(a, b); 
						if(cmp == 1)
							printf("\nStrings are same\n");
						else
							printf("\nStrings are not same\n");
					}
					break;
			case 6:
					if(a == NULL)
						printf("\nString is empty\n");
					else
					{
						free(b);
						b = malloc(sizeof(char) * 50);
						strcp(a, b);
						printf("\nString copied - ");
						printf("%s", b);
						printf("\n");
					}
					break;
			case 7:
					if(a == NULL)
						printf("\nString is empty\n");
					else
					{
						free(b);
						b = malloc(sizeof(char) * 50);
						strrv(a,b);
						printf("\nReverse String - ");
						puts(b);
						printf("\n");
					}
					break;
			case 8:
					if(a == NULL)
						printf("\nString is empty\n");
					else
					{
						free(b);
						b = malloc(sizeof(char) * 50);
						int s,t;
						printf("\nEnter the search string - ");
						scanf("%s", b);
						substr(a, b);
						printf("\n");
					}
					break;
			case 9:
				return 0;
			default:
				printf("\nPlease select a number form menu - ");
				break;
		}
	}while(1);
	return 0;
}
