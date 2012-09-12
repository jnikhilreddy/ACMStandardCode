#include <stdio.h>
#include <string.h>

#define MAXNODE 26

int n;
int maxChannel;
int X[MAXNODE+1];
int G[MAXNODE+1][MAXNODE+1];

void NextValue(int k)
{
	int j;
	while(1)
	{
		X[k] = (X[k]+1) % (n+1);
		if(X[k]==0) 
		{
			return;
		}
		for(j=1; j<=n; j++)
		{
			if(G[k][j] && (X[k]==X[j]))
			{
				break;
			}
		}

		if(j==n+1) return; /* new color found */
	}
}

void mColoring(int k)
{
	NextValue(k);
	
	if(X[k]==0) 
	{
		return;
	}

	if(X[k] > maxChannel)
	{
		maxChannel = X[k];
	}
	if(k==n)
	{
		return;
	}
	else
	{
		mColoring(k+1);
	}
}

void init(int N,int edge)
{
	int i,j,t1,t2;

	for(i=0; i<=N; i++)
	{
		for(j=0; j<=N; j++)
		{
			G[i][j] = 0;
		}
		X[i] = 0;
	}

	while(edge--)
	{
		scanf("%ld %ld",&t1,&t2);
		G[t1][t2]=1;
		G[t2][t1]=1;
	}

	return;
}

void main()
{
	int i, j,edge,t1,t2;

	while(1==scanf("%d", &n) && n)
	{
		
		
		scanf("%d",&edge);
		init(n,edge);

		maxChannel = 0;

		mColoring(1);

		if(maxChannel > 1)
		{
			printf("%d channels needed.\n", maxChannel);
		}
		else if(maxChannel==1)
		{
			printf("1 channel needed.\n");
		}
}
}