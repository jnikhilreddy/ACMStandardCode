#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define M 1009
#define N 1009

bool graph[M][N];
bool seen[N];
long matchL[M], matchR[N];
long n, m;

char str[109];

bool bpm( int u )
{
    for( int v = 0; v < n; v++ ) if( graph[u][v] )
    {
        if( seen[v] ) continue;
        seen[v] = true;

        if( matchR[v] < 0 || bpm( matchR[v] ) )
        {
            matchL[u] = v;
            matchR[v] = u;
            return true;
        }
    }
    return false;
}

void Inp()
{
	long i,j,u,v,Node,Edge;

	for(i=0;i<n;i++)
	{
		memset(str,'\0',sizeof(str));
		scanf(" %s",str);

		j=0;
		Node=0;
		while(str[j]>='0'  && str[j]<='9')
		{
			Node=Node*10+(str[j]-'0');
			j++;
		}
		
		memset(str,'\0',sizeof(str));
		scanf(" %s",str);
		j=1;
		Edge=0;
		while(str[j]>='0'  && str[j]<='9')
		{
			Edge=Edge*10+(str[j]-'0');
			j++;
		}

		u=Node;
		
		for(j=0;j<Edge;j++)
		{
			scanf("%ld",&v);
			graph[u][v]=graph[u][v]=1;
		}
		//printf("\n");
	}

	/*for(i=1;i<=node;i++)
	{
		printf("i %ld node %ld : ",i,a[i].n);
		for(j=0;j<a[i].n;j++)
		{
			printf("%ld ",a[i].f[j]);
		}
		printf("\n");
	}*/
}

int main()
{
    // Read input and populate graph[][]
    // Set m, n
	long cnt,i;

	while(scanf("%ld",&n)==1)
	{
		m=n;
		memset( matchL, -1, sizeof( matchL ) );
		memset( matchR, -1, sizeof( matchR ) );
		memset(graph,0,sizeof(graph));

		Inp();

		cnt = 0;
		for(i = 0; i < m; i++ )
		{
			memset( seen, 0, sizeof( seen ) );
			if( bpm( i ) ) cnt++;
		}
		
		printf("%ld\n",n-cnt/2);

		// cnt contains the number of happy pigeons
		// matchL[i] contains the hole of pigeon i or -1 if pigeon i is unhappy
		// matchR[j] contains the pigeon in hole j or -1 if hole j is empty
	}
    return 0;
}