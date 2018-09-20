/*
 ============================================================================
 Name        : sparse.c
 Author      : Devashish
 Version     :
 Copyright   : GNU Public Licence
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

#define MAX 101

typedef struct spa
{
	int col;
	int row;
	int val;
}sparse;

void display(sparse mat[MAX])
{
	int i;
	printf("\n row\tcol\tval");
	for(i=0; i<mat[0].val; i++)
	{
		printf("\n %d\t%d\t%d", mat[i].row, mat[i].col, mat[i].val);
	}
	return;
}

void getmat(sparse mat[MAX], int a[10][10], int r1, int c1)
{
	int i,j,k=1;
	for(i=0; i<r1; i++)
	{
		for(j=0; j<c1; j++)
		{
			printf("\nElement [%d][%d] - ",i,j);
			scanf("%d",&a[i][j]);
		}
 	}
	for(i=0; i<r1; i++)
	{
		for(j=0; j<c1; j++)
		{
			if(a[i][j] != 0)
			{
				mat[k].row = i;
				mat[k].col = j;
				mat[k].val = a[i][j];
				k++;
			}
		}
	}
	mat[0].row = r1;
	mat[0].col = c1;
	mat[0].val = k;
}

//void addition(int a[10][10], int b[10][10], int c[10][10], int r1, int c1, int r2, int c2)
//{
//	int i,j;
//
//	if(r1 != r2 && c1 != c2)
//	{
//		printf("\nError! cannot add matrices");
//		return;
//	}
//
//	for(i=0; i<r2; i++)
//	{
//		for(j=0; j<c2; j++)
//		{
//			c[i][j] = a[i][j] + b[i][j];
//		}
//	}
//
//	return;
//}
//
void transpose(sparse mat[MAX], sparse res[MAX])
{
	int n,i,j,curb;

	n = mat[0].val;
	res[0].row = mat[0].col;
	res[0].col = mat[0].row;

	if(n>0)
	{
		curb = 1;

		for(i=0; i < mat[0].col; i++)
		{
			for(j=0; j < n; j++)
			{
				if(mat[j].col == i)
				{
					res[curb].row = mat[j].col;
					res[curb].col = mat[j].row;/*

					res[curb].val = mat[j].val;
					printf("\nWorking");
					curb++;
				}
			}
		}
	}
	return;
}

//void saddle(int a[10][10], int r1, int c1)
//{
//	int i, j, ind=0, k, min=0, max=0, pos3=0, pos2=0, flg = 0;
//
//	for(i=0; i<r1; i++)
//	{row
//		min = a[i][0];
//		for(j=0; j<c1; j++)
//		{
//			if(min >= a[i][j])
//			{
//				min = a[i][j];
//				pos3 = i;
//				ind = j;
//			}
//		}
//
//		max = a[0][ind];
//		for(k=0; k < r1; k++)
//		{
//			if(max <= a[k][ind])
//			{
//				max = a[k][ind];
//				pos2 = k;
//			}
//		}
//
//		if(min == max && pos2 == pos3)
//		{
//			flg++;
//			if(flg > 1)
//				continue;
//			printf("\n %d \n",min);
//		}
//	}
//	if(flg == 0)
//	{
//		printf("\n Not found");
//	}
//}
int main(void) {

	int ch;
	int a[10][10];
	int r1=0, c1=0, r2=0, c2=0;
	sparse mat1[MAX], mat2[MAX], res[MAX];

	do{
		printf("\n MENU - ");
		printf("\n 1. Display");
		printf("\n 2. Populate Matrices");
		printf("\n 3. Addition");
		printf("\n 4. Transpose");
		printf("\n 5. Fast Transpose");
		printf("\n 6. exit");
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
					display(mat1);
					printf("\n Matrix B - ");
					display(mat2);
				}
				break;

			case 2:
				printf("\nEnter the number rows of Matrix A - ");
				scanf("%d",&r1);
				printf("\nEnter the number columns of Matrix A - ");
				scanf("%d",&c1);
				printf("\nEnter the number rows of Matrix B - ");
				scanf("%d",&r2);
				printf("\nEnter the number columns of Matrix B - ");
				scanf("%d",&c2);
				printf("\n Enter the Elements in matrix A - ");
				getmat(mat1, a, r1, c1);
				printf("\n Enter the Elements in matrix B - ");
				getmat(mat2, a, r2, c2);
				break;

//			case 3:
//				if(r1 == 0 || r2 == 0 || c1 == 0 || c2 == 0)
//					printf("\n\nError! Matrices are empty");
//				else
//				{
//					printf("\n\nAddition of your matrices - \n");
//					addition(a, b, c, r1, c1, r2, c2);
//					display(c, r1, c1);
//				}
//				break;
//
			case 4:
				if(r1 == 0 || r2 == 0 || c1 == 0 || c2 == 0)
					printf("\n\nError! Matrices are empty");
				else
				{
					printf("\n\nTranspose of matrix A - \n");
					transpose(mat1, res);
					display(res);
					printf("\n\nTranspose of matrix B - \n");
					transpose(mat2, res);
					display(res);
				}
				break;
//
//			case 5:
//				if(r1 == 0 || r2 == 0 || c1 == 0 || c2 == 0)
//					printf("\n\nError! Matrices are empty");
//				else
//				{
//					printf("\n\nMultiplication of your matrices (A * B)- \n");
//					multiplication(a, b, c, r1, c1, r2, c2);
//					display(c, r2, c1);
//					printf("\n\nMultiplication of your matrices (B * A)- \n");
//					multiplication(b, a, c, r1, c1, r2, c2);
//					display(c, r2, c1);
//				}
//				break;
//
//			case 6:
//				if(r1 == 0 || r2 == 0 || c1 == 0 || c2 == 0)
//					printf("\n\nError! Matrices are empty");
//				else
//				{
//					printf("\n Transpose of A - \n");
//					transpose(a, c, r1, c1, r2, c2);
//					display(c, r2, c1);
//					printf("\n Transpose of B - \n");
//					transpose(b, c, r1, c1, r2, c2);
//					display(c, r2, c1);
//				}
//				break;
//
//			case 7:
//				if(r1 == 0 || r2 == 0 || c1 == 0 || c2 == 0)
//					printf("\n\nError! Matrices are empty");
//				else
//				{
//					printf("\n Saddle of A - \n");
//					saddle(a, r1, c1);
//					printf("\n Saddle of B - \n");
//					saddle(b, r2, c2);
//				}
//				break;

			case 6:
				exit(0);

			default:
				printf("\nPlease select a number from menu - ");
		}
	}while(1);
}
