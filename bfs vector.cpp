#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>

#include<vector>
#include<queue>
#include<list>
#include<set>
#include<map>

#include<algorithm>
#include<iostream>
#include<sstream>
using namespace std;

#define VS vector<string>
#define VD vector<double>
#define VI vector<int>

#define CSE 10
int node,edge,prnt[CSE];
char color[CSE];

VI mat[CSE];

queue<int> que;

void inp()
{
	int i,u,v;

	while(!que.empty())
	{
		que.pop();
	}

	for(i=0;i<edge;i++)
	{
		scanf("%d %d",&u,&v);
		//mat[u][v]=1;
		//mat[v][u]=1;
		mat[u].push_back(v);
		mat[v].push_back(u);
	}
}

void bfs(int start)
{
	int i,y;

	memset(color,'w',sizeof(color));
	memset(prnt,0,sizeof(prnt));

	que.push(start);
	color[start]='b';
	prnt[start]=0;

	while(!que.empty())
	{
		y=que.front();
		que.pop();
		
		for(i=0;i<mat[y].size();i++)
		{
			if(color[mat[y][i]]=='w')
			{
				color[mat[y][i]]='b';
				que.push(mat[y][i]);
				prnt[mat[y][i]]=y;
			}
		}
	}
}

void Printpath(int end,int start)
{
	if(end==start)
	{
		printf("%d ",start);
	}
	else if(prnt[end]==0)
	{
		printf("No Path\n");
	}
	else
	{
		Printpath(prnt[end],start);
		printf("-> %d",end);
	}
}

void Free()
{
	int i;

	for(i=0;i<=node;i++)
	{
		mat[i].clear();
	}
}

int main()
{	
	//freopen("t.in","r",stdin);
	//freopen("ttt.out","w",stdout);

	int start,end;
	
	while( scanf("%d %d",&node,&edge)==2)
	{
		inp();

		scanf("%d",&start);

		bfs(start);

		while( scanf("%d",&end)  && end)
		{
			printf("Path from %d to %d\n",start,end);
			Printpath(end,start);
			printf("\n");
		}

		Free();
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
