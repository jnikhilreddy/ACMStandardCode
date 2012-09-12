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

#define MAXN 102
#define INF 999999999
#define CSE 10009

int Cost[MAXN];
int P[MAXN], N, E;
int V[MAXN][MAXN];

struct ss {
	int u, v;
};
ss edge[CSE];
int Path[MAXN], tp;

void Ini() 
{
	int i;
	for(i = 1; i<= N; i++) 
	{
		Cost[i] = INF;
	}
	P[0] = -1;
	Cost[1] = 0;
}

void BellMan() 
{
	int i,n, m = N, u, v;
	while(m--) 
	{
		for(i = 0; i<E; i++) 
		{
			u = edge[i].u;
			v = edge[i].v;
			n = Cost[u] + V[u][v];
			if(Cost[v]>n) 
			{
				Cost[v] = n;
				P[v] = u;
			}
			n = Cost[v] + V[v][u];
			if(Cost[u]>n) 
			{
				Cost[u] = n;
				P[u] = v;
			}
		}
	}
}


void Getpath(int n) 
{
	if(n == 1) 
	{
		Path[tp ++] = n;
		return;
	}
	Getpath(P[n]);
	Path[tp++] = n;
}

void ReSet() 
{
	int i,u,v;
	for(i = 0; i<tp-1; i++) 
	{
		u = Path[i];
		v = Path[i+1];
		V[u][v] = INF;
		V[v][u] = - V[v][u];
	}
}

void Cal() 
{
	int c1;
	tp = 0;
	BellMan();
	c1 = Cost[N];
	Getpath(N);
	ReSet();
	
	Ini();
	
	BellMan();
	c1 += Cost[N];
	
	if(c1 >= INF) 
		printf("Back to jail\n");
	else 
		printf("%d\n",c1);
}
int main() {
	int c;
	while(scanf("%d",&N) == 1) 
	{

		if(!N) break;
		
		scanf("%d",&E);

		Ini();
		
		for(int i = 0; i<E; i++) 
		{
			scanf("%d %d %d",&edge[i].u,&edge[i].v,&c);
			V[edge[i].u][edge[i].v] = c;
			V[edge[i].v][edge[i].u] = c;
		}
		Cal();
	}
	return 0;
}

