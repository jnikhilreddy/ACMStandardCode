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

#define MAX(aa,bb) (aa>bb?aa:bb)
#define MIN(aa,bb) (aa<bb?aa:bb)


#define PI (2*acos(0.0))

#define PB push_back
#define POB pop_back

#define INF 10009
#define ERR 1e-8
#define CSE 109

void PL()
{
	printf("\n");
}



struct pq
{
	long Name,cost;
	bool operator < (const pq &b) const
	{
		return (Name>b.Name);
		
		/*if(name==b.name)
		{
			return cost<b.cost;
		}
		else
		{
			return (name>b.name);
		}*/
	}
};

int node,edge,d[CSE],res[CSE],top;

VI mat[CSE];
priority_queue<pq> q;
pq dd;

void Free()
{
	int i,j;
	for(i=0;i<node;i++)
	{
		for(j=0;j<mat[i].size();j++)
		{
			mat[i].pop_back();
		}
	}
}


void bfs()
{
	int i;
	pq y;
	while(!q.empty())
	{
		q.pop();
	}

	for(i=0;i<node;i++)
	{
		if(!d[i])
		{
			dd.Name=i;
			q.push(dd);
		}
	}

	while(!q.empty())
	{
		y=q.top();
		res[top++]=y.Name;
		q.pop();
		for(i=0;i<mat[y.Name].size();i++)
		{
			d[ mat[y.Name][i] ]--;
			if(d[ mat[y.Name][i] ]==0)
			{
				dd.Name=mat[y.Name][i];
				q.push(dd);
			}
		}
	}
}

int main()
{	
	//freopen("a.in","r",stdin);
	//freopen("aa.out","w",stdout);
	
	int i,t;
	int u,v;
	
	scanf("%d",&t);
	while( t-- )
	{
		scanf("%d %d",&node,&edge);
		top=0;
		memset(d,0,sizeof(d));
		
		for(i=0;i<edge;i++)
		{
			scanf(" %d %d",&u,&v);
			u--;
			v--;
			mat[u].push_back(v);
			d[v]++;
		}
		
		bfs();
		if(top!=node)
		{
			printf("0\n");
		}
		else
		{
			printf("1\n");
		}
		
		//printf("Size %d \n",top);
		//printf("Case #%d: Dilbert should drink beverages in this order:",cs++);
		/*for(i=0;i<top;i++)
		{
			
			printf(" %d",res[i]);
		}
		printf("\n");*/

		Free();
	}

	return 0;
}