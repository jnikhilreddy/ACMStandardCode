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

int ml[CSE],n,m;
bool g[CSE][CSE],seen[CSE];//g[m][n];

int bmp(int u)
{
	int v;
	for(v=0;v<m;v++)
	{
		if(!g[u][v]  || seen[v])
		{
			continue;
		}
		seen[v]=1;
		if(ml[v]==-1 || bmp(ml[v]))
		{
			ml[v]=u;
			return 1;
		}
	}
	return 0;
}

int main()
{	
	//freopen("t.in","r",stdin);
	//freopen("ttt.out","w",stdout);
	
	int i,u,v,edge,cnt;

	while(cin>>n)
	{
		// n<m;

		if(!n)
		{
			break;
		}
		cin>>m>>edge;
		// Take Graph input;
		for(i=0;i<edge;i++)
		{
			cin>>u>>v;
			g[u][v]=1;
		}
		cnt=0;
		memset(ml,-1,sizeof(ml));
		for(i=0;i<n;i++)
		{
			memset(seen,0,sizeof(seen));
			if(bmp(i))
			{
				cnt++;
			}
		}
		cout<<"Max match  "<<cnt<<endl;
	}

	return 0;
}
