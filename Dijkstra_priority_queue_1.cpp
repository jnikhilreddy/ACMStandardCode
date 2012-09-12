#include <stdio.h>
#include <queue>
#include <stdlib.h>

using namespace std ;

#define INF (1<<30)
#define SZ 1010

int nodes ;
int g[SZ][SZ], d[SZ] ;

struct pq
{
	int node, cost ;
	bool operator < (const pq &b) const
	{
		return cost > b.cost ;
	}
} ;
 
void dijkstra( int mat[][SZ], int dist[], int s )
{
	priority_queue<pq> Q ;
	pq U, V ;

    for( int v = 1; v <= nodes; v++ ) //initialize single source
    {
        dist[v] = INF ;
    }
    dist[s] = 0 ;

	V.node = s ;  V.cost = 0 ;
	Q.push( V ) ;

    while( !Q.empty() )
    {
        U = Q.top() ;
		Q.pop() ;

		for( V.node = 1; V.node <= nodes; V.node++ )
		{
			if( mat[U.node][V.node] )
			{
				if( dist[U.node] + mat[U.node][V.node] < dist[V.node] )
				{
					dist[V.node] = dist[U.node] + mat[U.node][V.node] ;
					V.cost = dist[V.node] ;
					Q.push( V ) ;
				}
			}
		}
    }	
}

int main()
{

	int edges,source,u,v,w,i;

	while( scanf( "%d", &nodes) == 1 && nodes)
	{
		scanf("%d",&edges) ;

		memset( g, 0, sizeof(g)) ;

		while( edges-- )
		{
			scanf( "%d %d %d", &u, &v, &w ) ;
			g[u][v] = g[v][u] = w ;
			//indexing from 1;
		}

		scanf("%d",&source) ;

		dijkstra( g, d, source ) ;
		for(i=1;i<=nodes;i++)
		{
			printf("Cost from %d to %d is: %d\n",source,i,d[i]);
		}
		
	}

	return 0 ;
}