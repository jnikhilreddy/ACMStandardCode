#include<stdio.h>
#include<math.h>

#define INF 10000
#define NIL 0 

#define CSE 30

long PATH[CSE][CSE],d[CSE][CSE],Start,End,pik;

void init(long n)
{
	long i,j;

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			PATH[i][j]=NIL;
			d[i][j]=INF;
			/*if(i==j)
			{
				d[i][j]=NIL;
			}*/
		}
	}

	return ;
}

void FW(long n)
{
	long i,j,k;
	
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(d[i][j]>(d[i][k]+d[k][j]))
				{
					d[i][j]=d[i][k]+d[k][j];
					PATH[i][j]=PATH[k][j];
				}
			}
		}
	}

	return ;
}

void print_mat_PATH(long n)
{
	long i,j;

	printf("\ndistance matrix:\n");

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%ld ",d[i][j]);
		}
		printf("\n");
	}
	printf("PATH matrix :\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%ld ",PATH[i][j]);
		}
		printf("\n");
	}
}

void Print_path(long s,long e)
{
	if(PATH[s][e]==s)
	{
		printf("%ld",PATH[s][e]);
		return;
	}
	else if(PATH[s][e]==0)
	{
		printf("No path");
		pik=5;
	}
	else
	{
		Print_path(s,PATH[s][e]);
		printf(" %ld",PATH[s][e]);
	}
	return;
}

int main()
{
	long i,j,Node,Edge;
	long t1,t2,w;

	while(scanf("%ld%ld",&Node,&Edge)==2)
	{
		init(Node);

		w=1;

		for(i=1;i<=Edge;i++)
		{
			scanf("%ld%ld",&t1,&t2);
			d[t1][t2]=w;
		}
		for(i=1;i<=Node;i++)
		{
			for(j=1;j<=Node;j++)
			{
				if(d[i][j]!=INF  && i!=j)
				{
					PATH[i][j]=i;
				}
			}
		}
		FW(Node);
		print_mat_PATH(Node);
		while(1)
		{
			pik=1;
			scanf("%ld%ld",&Start,&End);
			Print_path(Start,End);
			if(pik==1)
			{
				printf(" %ld\n",End);
				printf("Cost : %ld\n",d[Start][End]);
			}
			printf("\n");
		}
	}
	
	return 0;
}

/*
INPUT  :
8 8

1 2
2 3
2 4
5 1
5 6
7 5
4 8
8 7
						  1.
					   /     \
					 .2       .5
					 / \      /  \
				   .3  .4    .7   .6 
					     \  /
						 .8
*/