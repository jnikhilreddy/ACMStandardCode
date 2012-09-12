#include<math.h>
#include<stdio.h>
#include <string.h>

#define CSE 128

int G[CSE][CSE],edg[CSE];
bool seen[CSE];
long matchL[CSE], matchR[CSE], n, m;
double gop[CSE][2],hol[CSE][2];

void input(long d)
{
	long i,j;
	double dis,x,y;
	for(i=0;i<n;i++)
	{
		scanf("%lf %lf",&gop[i][0],&gop[i][1]);
	}
	for(i=0;i<m;i++)
	{
		scanf("%lf %lf",&hol[i][0],&hol[i][1]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			x=gop[i][0]-hol[j][0];
			y=gop[i][1]-hol[j][1];
			dis=sqrt(x*x+y*y);

			if(d>dis||(dis-d)<=1e-10)
			{
				G[j][edg[j]++]=i;			
			}
		}
	}	
}

bool bpm( long u )
{
	long i,v;
    for( i = 0; i < edg[u]; i++ ) 
	{
		v=G[u][i];
		if( seen[v] ) 
		{
			continue;
		}
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

int main()
{
	// Read input and populate G[][]
    // Set m, n;

	long e,i,s,d;
    
	while(4==scanf("%d %d %ld %ld",&n,&m,&s,&d))
	{
		
		e=(n>m)?n:m;
		memset( edg, 0, sizeof( long ) *e );
		input(s*d);
		
		memset( matchL, -1, sizeof( long ) *m );
		memset( matchR, -1, sizeof( long ) *n );
		long cnt = 0;
		for( i = 0; i < m; i++ )
		{
			memset( seen, 0, sizeof( seen ) );
			if( bpm( i ) ) 
			{
				cnt++;
			}
		}
		printf("%ld\n",n-cnt);
	}

    /*  cnt contains the number of happy pigeons
        matchL[i] contains the hole of pigeon i or -1 if pigeon i is unhappy
        matchR[j] contains the pigeon in hole j or -1 if hole j is empty
	*/

    return 0;
}

/*
Sample Input:
2 2 5 10
1.0 1.0
2.0 2.0
100.0 100.0
20.0 20.0

Sample output:
1

*/