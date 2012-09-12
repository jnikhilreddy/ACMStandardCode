#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

#include <iostream>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <utility>

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cassert>
#include <complex>


using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;

#define CSE 30

struct SSS
{
	char color;
	long Partition;
};

SSS node[CSE];
long adj[CSE][CSE],total;


void Init()
{
	long i,j;

	for(i=0;i<=total;i++)
	{
		node[i].color='w';
		node[i].Partition=0;
		for(j=0;j<=total;j++)
		{
			adj[i][j]=0;
		}
	}
}

bool Bfs_Visit(long root)
{
	long u,v;
	queue<long> Q;
	

	node[root].color = 'g';
	node[root].Partition = 1;
	Q.push(root);


	while(!Q.empty())
	{
		u=Q.front();
		Q.pop();

		for(v=1;v<=total;v++)
		{
			if(adj[u][v])
			{
				if(node[u].Partition==node[v].Partition)
				{
					return 0;//not bipartite
				}
				else if(node[v].color=='w')
				{
					node[v].color = 'g';
					node[v].Partition = 3 - node[u].Partition;					
					Q.push(v);
				}
			}
		}
		
	}

	return 1; //bipartite
}

int main()
{
	long u,v,y;
	while(scanf("%ld",&total)==1)
	{
		if(total==0)
		{
			break;
		}
		Init();

		while(scanf("%d %d",&u,&v)==2)
		{
			if(u==0 && v==0)
			{
				break;
			}
			adj[u][v]=1;
			adj[v][u]=1;
		}
		y=Bfs_Visit(1);
		if(y)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}

    return 0;
}

/*

6
1 2 1 4
5 4 5 2
3 4 3 6
0 0

*/