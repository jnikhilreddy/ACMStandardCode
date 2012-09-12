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

queue<int> que;

void inp()
{
	long i,u,v;

	memset(mat,0,sizeof(mat));

	while(!que.empty())
	{
		que.pop();
	}

	for(i=0;i<edge;i++)
	{
		scanf("%ld %ld",&u,&v);
		mat[u][v]=1;
		mat[v][u]=1;
	}
}

void bfs(long start)
{
	long i,y;

	memset(color,'w',sizeof(color));
	memset(prnt,0,sizeof(prnt));

	que.push(start);
	color[start]='b';
	prnt[start]=0;

	while(!que.empty())
	{
		y=que.front();
		que.pop();
		
		for(i=1;i<=node;i++)
		{
			if(mat[y][i] && color[i]=='w')
			{
				color[i]='b';
				que.push(i);
				prnt[i]=y;
			}
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

		scanf("%ld",&start);

		bfs(start);

		while( scanf("%ld",&end)  && end)
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
