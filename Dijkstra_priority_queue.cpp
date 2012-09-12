#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>

#include<queue>

#include<algorithm>
using namespace std;
#define INF (1<<30)

#define PI (2*acos(0))
#define ERR 0.000001

#define Min(num1,num2) (num1<num2?num1:num2)
#define Max(num1,num2) (num1>num2?num1:num2)

#define CSE 1009

long nodes,edge,g[CSE][CSE],d[CSE],par[CSE];

struct pq
{
	long node,cost;
	bool operator < (const pq &b) const
	{
		return cost>b.cost;
	}
};


void DJ(long mat[][CSE],long dist[],long s)
{
	pq u,data;
	priority_queue<pq> que;
	long i;

	memset(par,-1,sizeof(par));

	for(i=1;i<=nodes;i++)
	{
		dist[i]=INF;
	}

	dist[s]=0;

	data.node=s;
	data.cost=0;

	que.push(data);

	while(!que.empty())
	{
		u=que.top();
		que.pop();
		for(data.node=1;data.node<=nodes;data.node++)
		{
			if(mat[u.node][data.node])
			{
				if( (dist[u.node] + mat[u.node][data.node])<dist[data.node])
				{
					dist[data.node]=dist[u.node] + mat[u.node][data.node];
					data.cost=dist[data.node];
					que.push(data);
					par[data.node]=u.node;
				}
			}
		}
	}
}


void Printpath(long v)
{
	if(par[v]==-1)
	{
		printf("%d",v);
		return;
	}
	else
	{
		Printpath(par[v]);
		printf(" -> %ld",v);
	}
}

int main()
{	
	//freopen("t.in","r",stdin);
	//freopen("ttt.out","w",stdout);

	long u,v,w,source,i;

	while( scanf("%ld %ld %ld",&nodes,&edge,&source)==3 )
	{
		memset(g,0,sizeof(g));

		for(i=0;i<edge;i++)
		{
			scanf("%ld %ld %ld",&u,&v,&w);
			g[u][v]=w;
		}

		DJ(g,d,source);

		for(i=1;i<=nodes;i++)
		{
			if(i != source)
			{
				printf("path from %ld to %ld:\n",source,i);
				Printpath(i);
				printf("\n");
			}
		}

		
	}
	
	return 0;
}

/*

Node Edge source
5 10 1

1 2 10
1 5 5
2 3 1
2 5 2
3 4 6
4 3 4
4 1 7
5 2 3
5 3 9
5 4 2


*/