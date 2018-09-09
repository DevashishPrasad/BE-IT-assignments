/*
 ============================================================================
 Name        : sets.c
 Author      : Devashish (23364)
 Version     : 1.0
 Copyright   : GNU public
 Description : Set Operations without pointers
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void display(int a[100], int l1)
{
	int i;
	printf(" { ");
	for(i=0; i<l1; i++)
	{
		printf(" %d ", a[i]);
	}
	printf(" }\n");
}
void sunion(int a[100], int b[100], int c[200], int l1, int l2)
{
	int i,j,k;

	for(i=0;i<l1;i++)
	{
		c[i]=a[i];
	}

	k = 0;
	for(i=l1;i<l1+l2;i++)
	{
		for(j=0;j<l1;j++)
		{
			if(c[j] == b[k])
			 k++;
		}
		c[i] = b[k];
		if(k == l2)
		break;
		k++;
	}

	display(c, i);
}
void sinter(int a[100], int b[100], int c[200], int l1, int l2)
{
	int i,j,k;

	k = 0;
	for(i=0;i<l1;i++)
	{
		for(j=0; j<l2; j++)
		{
			if(a[i] == b[j])
			{
				c[k] = a[i];
				k++;
			}
		}
	}

	display(c, k);
}
void sdiff(int a[100], int b[100], int c[200] , int l1, int l2)
{
	int i,j,k,flg=0;

	k = 0;
	for(i=0;i<l1;i++)
	{
		flg = 0;
		for(j=0; j<l2; j++)
		{
			if(a[i] == b[j])
				flg = 1;
		}
		if(flg == 0)
		{
			c[k] = a[i];
			k++;
		}
	}

	display(c, k);
}
void fulldiff(int a[100], int b[100], int c[200], int l1, int l2)
{
	int i,j,k,flg=0;

	k = 0;
	for(i=0;i<l1;i++)
	{
		flg = 0;
		for(j=0; j<l2; j++)
		{
			if(a[i] == b[j])
				flg = 1;
		}
		if(flg == 0)
		{
			c[k] = a[i];
			k++;
		}
	}

	for(i=0;i<l2;i++)
	{
		flg = 0;
		for(j=0; j<l1; j++)
		{
			if(a[j] == b[i])
				flg = 1;
		}
		if(flg == 0)
		{
			c[k] = b[i];
			k++;
		}
	}

	display(c, k);
}

void getset(int a[100], int l)
{

	int i, j;
	for(i=0; i<l; i++)
	{
		printf("\nElement [%d] - ",i);
		scanf("%d",&a[i]);

		for(j = 0; j<i; j++)
			if(a[j] == a[i])
			{
				i--;
				printf("\nPlease Enter distinct values");
			}
 	}

	return;
}
int main(void) {

	int ch;
	int a[100], b[100], c[200];
	int l1,l2;

	do{
		printf("\n MENU - ");
		printf("\n 1. Display");
		printf("\n 2. Populate Sets");
		printf("\n 3. Union");
		printf("\n 4. Intersection");
		printf("\n 5. Difference");
		printf("\n 6. Symmetric Difference");
		printf("\n 7. exit");
		printf("\nEnter your choice - ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
					if(l1 == 0 || l2 == 0)
						printf("\nError! Sets are empty\n");
					else
					{
						printf("\nSet A = ");
						display(a, l1);
						printf("\nSet B = ");
						display(b, l2);
					}
					break;
			case 2:
					printf("\nEnter the number of elements in Set A - ");
					scanf("%d",&l1);

					printf("\nEnter the number of elements in Set B - ");
					scanf("%d",&l2);

					printf("\nEnter elements in Set A - ");
					getset(a, l1);

					printf("\nEnter elements in Matrix B - ");
					getset(b, l2);
					break;
			case 3:
					if(l1 == 0 || l2 == 0)
						printf("\nError! Sets are empty");

					else
					{
						printf("\nUnion of Set A and Set B - \n");
						sunion(a, b, c, l1, l2);
					}

					break;
			case 4:
					if(l1 == 0 || l2 == 0)
						printf("\nError! Sets are empty");
					else
					{
						printf("\nIntersection of Set A and Set B - \n");
						sinter(a, b, c, l1, l2);
					}

					break;
			case 5:
					if(l1 == 0 || l2 == 0)
						printf("\nError! Sets are empty");
					else
					{
						printf("\nDifference of Set A with Set B - \n");
						sdiff(a, b, c, l1, l2);
						printf("\nDifference of Set B with Set A - \n");
						sdiff(b, a, c, l2, l1);
					}

					break;
			case 6:
					if(l1 == 0 || l2 == 0)
						printf("\nError! Sets are empty");
					else
					{
						printf("\nSymmetric Difference of Set A and Set B - \n");
						fulldiff(a, b, c, l1, l2);
					}

					break;
			case 7:
				return 0;
			default:
				printf("\nPlease select a number form menu - ");
				break;
		}
	}while(1);
	return 0;
}
