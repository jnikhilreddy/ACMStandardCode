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



#define Max(aa,bb) (aa>bb?aa:bb)
#define Min(aa,bb) (aa<bb?aa:bb)
#define RP(ii,nn) for(ii=0;ii<nn;ii++)

#define PI (2*acos(0.0))
#define PB push_back
#define INF 10009
#define ERR 1e-8
#define CSE 509

// the maximum number of vertices
#define NN 1024

// adjacency matrix (fill this up)
int cap[NN][NN];

// flow network
int fnet[NN][NN];

// BFS
int q[NN], qf, qb, prev[NN];

int fordFulkerson( int n, int s, int t )
{
	int u,v,bot,flow;
    // init the flow network
    memset( fnet, 0, sizeof( fnet ) );

    flow = 0;

    while( true )
    {
        // find an augmenting path
        memset( prev, -1, sizeof( prev ) );
        qf = qb = 0;
        prev[q[qb++] = s] = -2;
        while(qb>qf && prev[t]==-1 )
		{
            for(u=q[qf++],v=0;v< n;v++)
			{
                if(prev[v]== -1 && fnet[u][v] - fnet[v][u] < cap[u][v] )
				{
                    prev[q[qb++] = v] = u;
				}
			}
		}
        // see if we're done
        if( prev[t] == -1 ) break;

        // get the bottleneck capacity
        bot = 0x7FFFFFFF;
        for( v = t, u = prev[v]; u >= 0; v = u, u = prev[v] )
		{
            bot = (bot<(cap[u][v] - fnet[u][v] + fnet[v][u]))?bot:(cap[u][v] - fnet[u][v] + fnet[v][u]);
			//bot <?= cap[u][v] - fnet[u][v] + fnet[v][u];
		}
        // update the flow network
        for( v = t, u = prev[v]; u >= 0; v = u, u = prev[v] )
            fnet[u][v] += bot;

        flow += bot;
    }

    return flow;
}

int main()
{
	//source(s),Sink(t);
	//Indexing is startting from 0;
    
    int numVertices = 100;
	int node,edge,i,u,v,s,t,cost;

	while( cin>>node>>edge )
	{
    
		// ... fill up cap with existing edges.
		// if the edge u->v has capacity 6, set cap[u][v] = 6.        
		memset( cap,0,sizeof(cap));
		for(i=0;i<edge;i++)
		{
			cin>>u>>v>>cost;
			cap[u][v]=cost;
		}
		cin>>s>>t;
		cout<<"Max Flow : "<<fordFulkerson(node,s,t)<<endl;
	}  
    return 0;
}

/*
Book page : 658;
6 10
0 1 16
0 5 13
1 5 10
1 2 12
2 5 9
2 3 20
5 1 4
5 4 14
4 2 7
4 3 4
0 3


*/