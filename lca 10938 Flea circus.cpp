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

#define MAX(aa_1,bb_1) (aa_1>bb_1?aa_1:bb_1)
#define MIN(aa_1,bb_1) (aa_1<bb_1?aa_1:bb_1)


#define PI (2*acos(0.0))

#define PB push_back
#define POB pop_back
#define INIT(V_1) memset(V_1,0,sizeof(V_1))
#define INITS(V_1) memset(V_1,'\0',sizeof(V_1)

#define INF 10009
#define ERR 1e-8

#define CSE 5009

void PL()
{
	printf("\n");
}

list<int> g[CSE];
int N;
bool color[CSE];
int Level[CSE],Mark[CSE],top;

int dfs(int st,int ed,int lvl)
{
	list<int>::iterator it;
	int v,rt;

	color[st]=0;
	Level[lvl]=st;
	Mark[top++]=st;
	if(st == ed)
	{
		return lvl;
	}

	for(it=g[st].begin() ;it != g[st].end(); it++)
	{
		v=*it;
		if(color[v])
		{
			rt=dfs(v,ed,lvl+1);
			if(rt)
			{
				return rt;
			}
		}
	}
	return 0;
}

void Init()
{
	int i;

	for(i=0;i<=N;i++)
	{
		g[i].clear();
	}
}

void Print()
{
	int i;
	printf("Mark:\n");
	for(i=1;i<top;i++)
	{
		printf("%d ",Mark[i]);
	}
	PL();
	printf("Level:\n");
	for(i=0;i<=N;i++)
	{
		printf("%d ",Level[i]);
	}
	PL();
}

int main()
{	
	//freopen("a.in","r",stdin);
	//freopen("aa.out","w",stdout);

	int i,u,v,t,tmp;
	int st,ed,rt;

	while( scanf("%d",&N)==1  && N )
	{
		for(i=0;i<N-1;i++)
		{
			scanf("%d %d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		scanf("%d",&t);
		while(t--)
		{
			scanf("%d %d",&st,&ed);
			memset(color,1,sizeof(color));

			top=0;
			rt=dfs(st,ed,0);
			//printf("RT  %d\n",rt);
			if(rt%2==0)
			{
				printf("The fleas meet at %d.\n",Level[rt/2]);
			}
			else
			{
				u = Level[rt/2];
				v = Level[rt/2+1];
				if(u>v) 
				{
					tmp = u;
					u = v;
					v = tmp;
				}
				printf("The fleas jump forever between %d and %d.\n",u,v);
			}
			//Print();
		}
		Init();
	}

	return 0;
}
/*
8
1 2
1 3
2 4
2 5
3 6 
3 7
5 8
5
5 1 
7 4
1 8
4 7
7 8

OUTPUT:
The fleas meet at 2.
The fleas meet at 1.
The fleas jump forever between 2 and 5.
The fleas meet at 1.
The fleas jump forever between 1 and 2.


*/