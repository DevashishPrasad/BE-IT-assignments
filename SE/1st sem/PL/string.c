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

int strlen(char a[100])
{
	int i,len=0;
	for(i=0; a[i]!='\0'; i++)
		len++;

	return len;
}
int strcmp(char a[100], char b[100])
{
	int i,flg=0;

	for(i=0; a[i]!='\0'; i++)
		if(a[i] != b[i])
			flg=1;

	if(flg == 0)
		return 1;
	else
		return 0;
}
void strrev(char a[100], char b[100])
{
	int i,j;

	int len = strlen(a);
	for(i=(len-1),j=0; i >= 0; i--,j++)
		b[j] = a[i];
}
void palindrome(char a[100], char b[100])
{	
	strrev(a, b);	
	int cmp = strcmp(a, b);
	if(cmp == 1)
		printf("\nThe String is a palindrome\n");
	else
		printf("\nThe String is not a palindrome\n");
}
void strcpy(char a[100], char b[100])
{
	int i;

	for(i=0; a[i]!='\0'; i++)
		b[i] = a[i];
}
void substr(char a[100], char b[100])
{
	int i, j, flg=0;

	for(i=0,j=0; i<strlen(a); i++)
	{
		if(a[i]==b[j])
		j++;
		else
		j = 0;
		if(j == strlen(b))
		{
			flg = 1;
			printf("\nSubstring found at locaion %d\n", i);
		}
	}

	if(flg == 0)
	printf("\nSubstring not found\n");
}
int main(void) {

	int ch;
	char a[100] = {'\0'}, b[100] = {'\0'};

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
					scanf("%s", a);
					break;
			case 2:
					if(a[0] == '\0')
						printf("\nString is empty\n");
					else
					{
						printf("\nYour String - ");
						puts(a);
					}
					
					break;
			case 3:
					if(a[0] == '\0')
						printf("\nString is empty\n");
					else
						printf("\nLength of your string is - %d\n",strlen(a));
					break;
			case 4:
					if(a[0] == '\0')
						printf("\nString is empty\n");
					else
						palindrome(a, b);
					break;
			case 5:
					if(a[0] == '\0')
						printf("\nString is empty\n");
					printf("\nEnter a string to compare - ");
					scanf("%s", b);
					int cmp = strcmp(a, b); 
					if(cmp == 1)
						printf("\nStrings are same\n");
					else
						printf("\nStrings are not same\n");
					break;
			case 6:
					if(a[0] == '\0')
						printf("\nString is empty\n");
					else
					{
						strcpy(a,b);
						printf("\nString copied - ");
						puts(b);
						printf("\n");
					}
					break;
			case 7:
					if(a[0] == '\0')
						printf("\nString is empty\n");
					else
					{
						strrev(a,b);
						printf("\nReverse String - ");
						puts(b);
						printf("\n");
					}
					break;
			case 8:
					if(a[0] == '\0')
						printf("\nString is empty\n");
					else
					{
						int s,t;
						printf("\nEnter the search string - ");
						scanf("%s", &b);
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
