/*
 ============================================================================
 Name        : matrix.c
 Author      : Devashish (23364)
 Version     : 1.4
 Copyright   : GNU public
 Description : Matrix operations with pointers
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void display(int *a, int r1, int c1)
{
	int i,j;
	printf("\n");
	for(i=0; i<r1; i++)
	{
		for(j=0; j<c1; j++)
		{
			printf(" %d ", *(a + i * c1 + j));
		}
		printf("\n");
	}
	return;
}

void getmat(int *a, int r1, int c1)
{
	int i,j;
	for(i=0; i<r1; i++)
	{
		for(j=0; j<c1; j++)
		{
			printf("\nElement [%d][%d] - ",i,j);
			scanf("%d", (a + i * c1 + j));
		}
 	}
	return;
}

void addition(int *a, int *b, int *c, int r1, int c1, int r2, int c2)
{
	int i,j;

	if(r1 != r2 && c1 != c2)
	{
		printf("\nError! cannot add matrices\n");
		return;
	}

	for(i=0; i<r2; i++)
	{
		for(j=0; j<c2; j++)
		{
			*(c + i * c1 + j) = *(a + i * c1 + j) + *(b + i * c1 + j);
		}
	}

	return;
}

void subtraction(int *a, int *b, int *c, int r1, int c1, int r2, int c2)
{
	int i,j;

	if(r1 != r2 && c1 != c2)
	{
		printf("\nError! cannot subtract matrices");
		return;
	}

	for(i=0; i<r2; i++)
	{
		for(j=0; j<c2; j++)
		{
			*(c + i * c1 + j) = *(a + i * c1 + j) - *(b + i * c1 + j);
		}
	}
}

void multiplication(int *a, int *b, int *c, int r1, int c1, int r2, int c2)
{
	int i,j,k;

	if(c1 != r2)
	{
		printf("\nError! cannot multiply matrices\n");
		return;
	}

	for(i=0; i<r2; i++)
		{
			for(j=0; j<c2; j++)
			{
				*(c + i * c1 + j) = 0;
			}
		}

	for(i=0; i<r2; i++)
	{
		for(j=0; j<c2; j++)
		{
			for(k=0; k<c2; k++)
			{
				*(c + i * c1 + j) = *(c + i * c1 + j) + *(a + i * c1 + k) * *(b + k * c1 + j);
			}
		}
	}
}
void transpose(int *a, int *c, int r1, int c1, int r2, int c2)
{
	int i,j;

	for(i=0; i<r1; i++)
	{
		for(j=0; j<c1; j++)
		{
			*(c + i * c1 + j) = *(a + j * c1 + i);
		}
	}
	return;
}

void saddle(int *a, int r1, int c1)
{
//	int i, j, ind=0, k, min, max, pos1, pos2;
//
//	for(i=0; i<r1; i++)
//	{
//		min = *(a + i * c1 + 0);
//		for(j=0; j<c1; j++)
//		{
//			if(min > *(a + i * c1 + j))
//			{
//				min = *(a + i * c1 + j);
//				ind = j;
//				pos1 = i;
//			}
//		}
//	}
//
//	max = *(a + 0 * c1 + ind);
//	for(k=0; k < r1; k++)
//	{
//		if(max < *(a + k * c1 + ind))
//		{
//			max = *(a + k * c1 + ind);
//			pos2 = k;
//		}
//	}
//
//	if(min == max)
//	{
//		if(pos1 == pos2)
//			printf("\n %d \n",min);
//	}
//	else
//		printf("\n Not found");

	int i, j, ind=0, k, min=0, max=0, pos3=0, pos2=0, flg = 0;

	for(i=0; i<r1; i++)
	{
		min = *(a + i * c1 + 0);
		for(j=0; j<c1; j++)
		{
			if(min >= *(a + i * c1 + j))
			{
				min = *(a + i * c1 + j);
				pos3 = i;
				ind = j;
			}
		}
		max = *(a + 0 * c1 + ind);
		for(k=0; k < r1; k++)
		{
			if(max <= *(a + k * c1 + ind))
			{
				max = *(a + k * c1 + ind);
				pos2 = k;
			}
		}
		if(min == max && pos2 == pos3)
		{
			flg++;
			if(flg > 1)
				continue;
			printf("\n %d \n",min);
		}
	}
	if(flg == 0)
	{
		printf("\n Not found");
	}
}
int main(void) {

	int ch;
	int *a, *b, *c;
	int r1=0,c1=0,r2=0,c2=0;


	do{
		printf("\n MENU - ");
		printf("\n 1. Display");
		printf("\n 2. Populate Matrices");
		printf("\n 3. Addition");
		printf("\n 4. Subtraction");
		printf("\n 5. Multiplication");
		printf("\n 6. Transpose");
		printf("\n 7. Saddle point");
		printf("\n 8. exit");
		printf("\nEnter your choice - ");

		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				if(r1 == 0 || r2 == 0 || c1 == 0 || c2 == 0)
					printf("\n\nError! Matrices are empty");
				else
				{
					printf("\n Matrix A - ");
					display(a, r1, c1);
					printf("\n Matrix B - ");
					display(b, r2, c2);
				}
				break;

			case 2:
				printf("\nEnter the number rows of Matrix A - ");
				scanf("%d",&r1);
				printf("\nEnter the number columns of Matrix A - ");
				scanf("%d",&c1);
				a = (int*) malloc((r1*c1)*sizeof(int));
				printf("\nEnter the number rows of Matrix B - ");
				scanf("%d",&r2);
				printf("\nEnter the number columns of Matrix B - ");
				scanf("%d",&c2);
				b = (int*) malloc((r2*c2)*sizeof(int));
				printf("\n Enter the Elements in matrix A - ");
				getmat(a, r1, c1);
				printf("\n Enter the Elements in matrix B - ");
				getmat(b, r2, c2);
				break;

			case 3:
				if(r1 == 0 || r2 == 0 || c1 == 0 || c2 == 0)
					printf("\n\nError! Matrices are empty");
				else
				{
					printf("\n\nMatrix 1 - \n");
					display(a, r1, c1);
					printf("\n\nMatrix 1 - \n");
					display(b, r2, c2);
					printf("\n\nAddition of your matrices - \n");
					c = (int*) malloc((r1*c1)*sizeof(int));
					addition(a, b, c, r1, c1, r2, c2);
					display(c, r1, c1);
					free(c);
				}
				break;

			case 4:
				if(r1 == 0 || r2 == 0 || c1 == 0 || c2 == 0)
					printf("\n\nError! Matrices are empty");
				else
				{
					printf("\n\nSubtraction of your matrices (A - B)- \n");
					c = (int*) malloc((r1*c1)*sizeof(int));
					subtraction(a, b, c, r1, c1, r2, c2);
					display(c, r1, c1);
					printf("\n\nSubtraction of your matrices (B - A)- \n");
					subtraction(b, a, c, r1, c1, r2, c2);
					display(c, r1, c1);
					free(c);
				}
				break;

			case 5:
				if(r1 == 0 || r2 == 0 || c1 == 0 || c2 == 0)
					printf("\n\nError! Matrices are empty");
				else
				{
					printf("\n\nMultiplication of your matrices (A * B)- \n");
					c = (int*) malloc((r1*c1)*sizeof(int));
					multiplication(a, b, c, r1, c1, r2, c2);
					display(c, r2, c1);
					printf("\n\nMultiplication of your matrices (B * A)- \n");
					multiplication(b, a, c, r1, c1, r2, c2);
					display(c, r2, c1);
					free(c);
				}
				break;

			case 6:
				if(r1 == 0 || r2 == 0 || c1 == 0 || c2 == 0)
					printf("\n\nError! Matrices are empty");
				else
				{
					printf("\n Transpose of A - \n");
					c = (int*) malloc((r1*c1)*sizeof(int));
					transpose(a, c, r1, c1, r2, c2);
					display(c, r2, c1);
					printf("\n Transpose of B - \n");
					transpose(b, c, r1, c1, r2, c2);
					display(c, r2, c1);
					free(c);
				}
				break;

			case 7:
				if(r1 == 0 || r2 == 0 || c1 == 0 || c2 == 0)
					printf("\n\nError! Matrices are empty");
				else
				{
					c = (int*) malloc((r1*c1)*sizeof(int));
					printf("\n Saddle of A - \n");
					saddle(a, r1, c1);
					printf("\n Saddle of B - \n");
					saddle(b, r2, c2);
					free(c);
				}
				break;

			case 8:
				exit(0);

			default:
				printf("\nPlease select a number from menu - ");
		}
	}while(1);
}
