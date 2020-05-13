#include<stdio.h>

int a[10][10],visited[10],n,cost=0,src;

void getInput()
{
	int i,j;
	printf("Enter number of cities-->");
	scanf("%d",&n);
	printf("\nEnter Cost Matrix\n");
	for(i=0;i<n;i++)
	{
		printf("\nEnter Elements of Row-->%d\n",i+1);
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
		visited[i]=0;
	}
	printf("Cost Matrix is-->\n");
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
			printf("\t%d",a[i][j]);
	}
}

void mincost(int city,int src)
{
	int i,ncity;
	visited[city]=1;	
	printf("%d -->",city+1);
	ncity=least(city);
	if(ncity==999)
	{
		ncity=src;
		printf("%d",ncity+1);
		//printf("\nCity=%d\tncity=%d",city,ncity);
		cost+=a[city][ncity];
		return;
	}
	mincost(ncity,src);
}

int least(int c)
{
	int i,nc=999;
	int min=999,kmin;
	for(i=0;i<n;i++)
	{
		if((a[c][i]!=0)&&(visited[i]==0))
		{
			if(a[i][c]+a[c][i] < min)
			{
				min=a[i][c]+a[c][i];
				kmin=a[c][i];
				nc=i;
			}
		}
	}
	if(min!=999)
		cost+=kmin;
	return nc;
}

void put()
{
	printf("\nMinimum cost-->");
	printf("%d",cost);
	printf("\n\n");
}

int main()
{
	getInput();
	printf("\nEnter source vertex-->");
	scanf("%d",&src);
	printf("\nThe Path is-->\n\n");
	mincost(src,src); 
	put();
	return 0;
}
