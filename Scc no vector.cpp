#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>

#include<vector>
#include<queue>
#include<map>

#include<algorithm>
#include<iostream>
#include<sstream>
using namespace std;

#define VS vector<string>
#define VD vector<double>
#define VI vector<int>



#define MAX(aa,bb) (aa>bb?aa:bb)
#define MIN(aa,bb) (aa<bb?aa:bb)
#define RP(ii,nn) for(ii=0;ii<nn;ii++)
#define CLR(aa,vv) memset((aa),(vv),sizeof(aa))

#define PI (2*acos(0.0))
#define PB push_back
#define INF 10009
#define ERR 1e-8
#define CSE 109

int r[CSE][CSE],tr[CSE][CSE]; // adjacency matrix
int order[CSE], v[CSE], top_place;
int comp[CSE]; // component id
int curr_comp,vert,edge;

void dfs(int a) 
{
	int N;
	N=vert;
	if (v[a]) return;
	v[a] = 1;
	for (int i = 0;i<N; i++)
	{
		if(r[a][i]) dfs(i);
	}
	top_place--;
	order[top_place] = a;
}

// dfs on the reversed graph
void dfs_rev(int a) 
{
	int N;
	N=vert;
	if(v[a]) return;
	v[a] = 1;
	comp[a] = curr_comp;
	for(int i=0; i<N; i++) 
	{
		if(tr[a][i]) 
		{
			dfs_rev(i); 
		}
	}
}
void top() 
{
	int i,N;
	N=vert;
	top_place = N;
	for(i=0; i<N; i++) v[i]=0;
	for(i=0; i<N; i++) 
	{
		if(!v[i]) dfs(i);
	}
}
void scc() 
{
	int i,N,k;
	N=vert;
	top();
	for(i=0; i<N; i++) v[i]=0;
	for(i=0; i<N; i++)
	{
		int j = order[i];
		if (!v[j]) 
		{
			curr_comp = j;
			dfs_rev(j);
			/*printf("j  %d",j);
			for(k=0;k<vert;k++)
			{
				printf(" %d",comp[k]);
			}
			printf("\n");*/
		}
	}
}
void Print()
{
	int i;
	
		printf("Order\n");
		for(i=0;i<vert;i++)
		{
			printf("%d ",order[i]);
		}
		printf("\nComp:\n");
		for(i=0;i<vert;i++)
		{
			printf("%d ",comp[i]);
		}
		printf("\n");
}

int main()
{
	int tt,i,u,v;

	scanf("%d",&tt);

	while(tt--)
	{
		scanf("%d %d",&vert,&edge);
		memset(r,0,sizeof(r));
		memset(tr,0,sizeof(tr));
		memset(comp,-1,sizeof(comp));
		for(i=0;i<edge;i++)
		{
			scanf("%d %d",&u,&v);
			u--;v--;
			r[u][v]=1;
			tr[v][u]=1;
		}
		scc();
		Print();
	}
	return 0;
}

/*

2
8 14

1 2
2 3 2 5 2 6
3 4 3 7
4 3 4 8
5 1 5 6
6 7
7 6 7 8
8 8



*/
