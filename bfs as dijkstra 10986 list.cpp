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
#define INIT(V_1) memset(V_1,0,sizeof(V_1))
#define INITS(V_1) memset(V_1,'\0',sizeof(V_1)

#define INF (1<<30)
#define ERR 1e-8

#define CSE 20009

void PL()
{
	printf("\n");
}

struct SS
{
	int nn,cc;
};

list<SS> ml[CSE];
list<SS>::iterator it;

int st,ed,d[CSE];
int nodes,edges;

struct pq
{
	int node,cost;
	bool operator < (const pq &data) const
	{
		return cost>data.cost;
	}
};

void init()
{
	int i;
	for(i=0;i<nodes;i++)
	{
		d[i]=INF;
	}
}

int bfs()
{
	priority_queue<pq> que;

	if(edges==0)
	{
		return -1;
	}
	d[st]=0;

	pq tmp,y;
	int new_node,new_cost;

	tmp.node=st;
	tmp.cost=0;
	que.push(tmp);

	while(!que.empty())
	{
		y=que.top();
		que.pop();
		if(y.node == ed)
		{
			return y.cost;
		}
		for(it=ml[y.node].begin() ;it!=ml[y.node].end(); it++)
		{
			new_node=it->nn;
			new_cost=y.cost+it->cc;
			if(new_cost<d[new_node])
			{
				d[new_node]=new_cost;
				tmp.node=new_node;
				tmp.cost=new_cost;
				que.push(tmp);
			}
		}
	}

	return -1;


}

int main()
{	
	//freopen("a.in","r",stdin);
	//freopen("aa.out","w",stdout);

	int y,t,i,u,v,w,cs=1;
	SS tmp;

	scanf("%d",&t);

	while(t--)
	{
		scanf("%d %d %d %d",&nodes,&edges,&st,&ed);
		for(i=0;i<edges;i++)
		{
			scanf("%d %d %d",&u,&v,&w);
			tmp.nn=v;tmp.cc=w;
			ml[u].PB(tmp);
			tmp.nn=u;tmp.cc=w;
			ml[v].PB(tmp);
		}
		init();
		y=bfs();
		if(y==-1)
		{
			printf("Case #%d: unreachable\n",cs++);
		}
		else
		{
			printf("Case #%d: %d\n",cs++,y);
		}
		for(i=0;i<nodes;i++)
		{
			ml[i].clear();
		}
	}

	return 0;
}