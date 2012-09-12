#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<queue>

#include<algorithm>
using namespace std;

#define PI (2*acos(0))
#define ERR 0.000001

#define CSE 10
long mat[CSE][CSE],node,edge,prnt[CSE];
char color[CSE];


void inp()
{
	long i,u,v;

	memset(mat,0,sizeof(mat));

	for(i=0;i<edge;i++)
	{
		scanf("%ld %ld",&u,&v);
		mat[u][v]=1;
		mat[v][u]=1;
	}
}

void dfs_visit(long u)
{
	long i;

	color[u]='g';


	for(i=1;i<=node;i++)
	{
		if(mat[u][i] && color[i]=='w')
		{
			prnt[i]=u;
			dfs_visit(i);
		}
	}
	color[u]='b';
}

void dfs()
{
	long i;

	memset(color,'w',sizeof(color));
	memset(prnt,0,sizeof(prnt));

	for(i=1;i<=node;i++)
	{
		if(color[i]=='w')
		{
			dfs_visit(i);
		}
	}

}

void Printpath(long end,long start)
{
	if(end==start)
	{
		printf("%ld ",start);
	}
	else if(prnt[end]==0)
	{
		printf("No Path\n");
	}
	else
	{
		Printpath(prnt[end],start);
		printf("-> %ld",end);
	}
}

int main()
{	
	//freopen("t.in","r",stdin);
	//freopen("ttt.out","w",stdout);

	long start,end;
	
	while( scanf("%ld %ld",&node,&edge)==2)
	{
		inp();

		dfs();

		while( scanf("%ld %ld",&start,&end)  && end)
		{
			printf("Path from %ld to %ld\n",start,end);
			Printpath(end,start);
			printf("\n");
		}
	}
	
	return 0;
}

/*
8 7
1 2 1 4
2 3 2 6
4 5 4 7
6 8
1


*/
