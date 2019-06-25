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
	for(i=0; i<=mat[0].val; i++)
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
	mat[0].val = k-1;
}

void addition(sparse mat1[MAX], sparse mat2[MAX], sparse res[MAX])
{
	int i = 1, j = 1, k = 1;

	while(i <= mat1[0].val && j <= mat2[0].val)
	{
		//printf("\nINFO: %d %d %d",i, j, k);
		if(mat1[i].row == mat2[j].row && mat1[i].col == mat2[j].col)
		{
			res[k].row = mat1[i].row;
			res[k].col = mat1[i].col;
			res[k].val = mat1[i].val + mat2[j].val;
			i++; j++; k++;
		}
		if(mat1[i].row == mat2[j].row && mat1[i].col < mat2[j].col)
		{
			res[k].row = mat1[i].row;
			res[k].col = mat1[i].col;
			res[k].val = mat1[i].val;
			i++; k++;
		}
		if(mat1[i].row == mat2[j].row && mat1[i].col > mat2[j].col)
		{
			res[k].row = mat2[j].row;
			res[k].col = mat2[j].col;
			res[k].val = mat2[j].val;
			j++; k++;
		}
		if(mat1[i].row < mat2[j].row)
		{
			res[k].row = mat1[i].row;
			res[k].col = mat1[i].col;
			res[k].val = mat1[i].val;
			i++; k++;
		}
		if(mat1[i].row > mat2[j].row)
		{
			res[k].row = mat2[j].row;
			res[k].col = mat2[j].col;
			res[k].val = mat2[j].val;
			j++; k++;
		}
	}

	while(i <= mat1[0].val)
	{
		res[k].row = mat1[i].row;
		res[k].col = mat1[i].col;
		res[k].val = mat1[i].val;
		i++; k++;
	}

	while(j <= mat2[0].val)
	{
		res[k].row = mat2[i].row;
		res[k].col = mat2[i].col;
		res[k].val = mat2[i].val;
		j++; k++;
	}

	res[0].row = mat1[0].row;
	res[0].col = mat1[0].col;
	res[0].val = k-2;
	return;
}

void transpose(sparse mat[MAX], sparse res[MAX])
{
	int n,i,j,curb;

	n = mat[0].val;
	res[0].row = mat[0].col;
	res[0].col = mat[0].row;
	res[0].val = mat[0].val;

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
					res[curb].col = mat[j].row;
					res[curb].val = mat[j].val;
					curb++;
				}
			}
		}
	}
	return;
}

void fasttranspose(sparse mat[MAX], sparse res[MAX])
{
	int row_terms[MAX], start[MAX];
	int i, j, num_cols = mat[0].col, num_terms = mat[0].val;

	res[0].row = num_cols;
	res[0].col = mat[0].row;
	res[0].val = num_terms;

	if(num_terms > 0)
	{
		for(i = 0; i < num_cols; i++)
			row_terms[i] = 0;
		for(i = 1; i < num_terms; i++)
			row_terms[mat[i].col]++;

		start[0] = 1;

		for(i = 1; i<num_cols; i++)
			start[i] = start[i-1] + row_terms[i-1];

		for(i = 1; i < num_terms; i++)
		{
			j = start[mat[i].col]++;
			res[j].row = mat[i].col;
			res[j].col = mat[i].row;
			res[j].val = mat[i].val;
		}
	}
}

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

			case 3:
				if(r1 == 0 || r2 == 0 || c1 == 0 || c2 == 0)
					printf("\n\nError! Matrices are empty");
				else
				{
					printf("\n\nAddition of your sparse matrices - \n");
					addition(mat1, mat2, res);
					display(res);
				}
				break;

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

			case 5:
				if(r1 == 0 || r2 == 0 || c1 == 0 || c2 == 0)
					printf("\n\nError! Matrices are empty");
				else
				{
					printf("\n\nFast Transpose of your matrix A - \n");
					fasttranspose(mat1, res);
					display(res);
					printf("\n\nFast Transpose of your matrices B - \n");
					fasttranspose(mat2, res);
					display(res);
				}
				break;
			case 6:
				exit(0);

			default:
				printf("\nPlease select a number from menu - ");
		}
	}while(1);
}
