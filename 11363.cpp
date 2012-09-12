#include <string.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>

#define CSE 10005



long graph[CSE][2];


bool seen[CSE];
long matchL[CSE], matchR[CSE];

bool bpm( long u )
{
    for( long v = 0; v < 2; v++ ) //if( graph[u][v] )
    {
		/*
			if( seen[v] ) continue;
			seen[v] = true;
		*/
        if( seen[graph[u][v]] ) continue;
        seen[graph[u][v]] = true;

		//if( matchR[v] < 0 || bpm( matchR[v] ) )
        if( matchR[graph[u][v]] < 0 || bpm(matchR[graph[u][v]] ) )
        {
            matchL[u]=graph[u][v];
			matchR[graph[u][v]]=u;
			//matchL[u] = v;
            //matchR[v] = u;
            return true;
        }
    }
    return false;
}

int main()
{
    // Read input and populate graph[][]
    // Set m, n
	long T,e,n,i,u,v;

	scanf("%ld",&T);

	while(T--)
	{
		scanf("%ld %ld",&e,&n);
		memset( graph, 0, sizeof( graph ) );
		for(i=0;i<e;i++)
		{
			scanf("%ld %ld",&u,&v);
			graph[i][0]=u;
			graph[i][1]=v;
		}

		memset( matchL, -1, sizeof( matchL ) );
		memset( matchR, -1, sizeof( matchR ) );
		long cnt = 0;
		for( long i = 0; i < e; i++ )
		{
			memset( seen, 0, sizeof( seen ) );
			if( bpm( i ) ) cnt++;
		}

		//printf("Res %ld\n",cnt);
		if(cnt==e)
		{
			printf("successful hashing\n");
		}
		else
		{
			printf("rehash necessary\n");
		}
	}

    // cnt contains the number of happy pigeons
    // matchL[i] contains the hole of pigeon i or -1  if pigeon i is unhappy
    // matchR[j] contains the pigeon in hole j or -1  if hole j is empty

    return 0;
}