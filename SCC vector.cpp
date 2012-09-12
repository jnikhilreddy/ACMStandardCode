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

#define VI vector<int>

#define POB pop_back
#define PB push_back

#define CSE 110109

struct SSS
{
	VI Ed;
};

struct SS
{
	int In,Out;
};
SS arr[CSE];

SSS r[CSE],tr[CSE];
int Order[CSE], v[CSE], top_place;
int Flag[CSE],freq[CSE],Connected[CSE];
int curr_Flag,vert,edge;

bool f[CSE];

void dfs(int a) 
{
	int i,N,l;
	N=vert;
	if (v[a]) 
	{
		return;
	}
	v[a] = 1;
	l=r[a].Ed.size();
	for (i= 0;i<l; i++)
	{
		dfs(r[a].Ed[i]);
	}
	top_place--;
	Order[top_place] = a;
}

void dfs_rev(int a) 
{
	int N,l;
	N=vert;
	if(v[a]) return;
	v[a] = 1;
	Flag[a] = curr_Flag;
	l=tr[a].Ed.size();
	for(int i=0; i<l; i++) 
	{
		dfs_rev(tr[a].Ed[i]);
	}
}
void top() 
{
	int i,N;
	N=vert;
	top_place = N;
	for(i=0; i<N; i++) 
	{
		v[i]=0;
	}
	for(i=0; i<N; i++) 
	{
		if(!v[i]) dfs(i);
	}
}
void scc() 
{
	int i,N;
	N=vert;
	top();
	for(i=0; i<N; i++) 
	{
		v[i]=0;
	}
	for(i=0; i<N; i++)
	{
		int j = Order[i];
		if (!v[j]) 
		{
			curr_Flag = j;
			dfs_rev(j);
		}
	}
}
void Init()
{
	long i,j,l;

	for(i=0;i<=vert;i++)
	{
		arr[i].In=arr[i].Out=0;
		l=r[i].Ed.size();
		for(j=0;j<l;j++)
		{
			r[i].Ed.POB();
		}
		l=tr[i].Ed.size();
		for(j=0;j<l;j++)
		{
			tr[i].Ed.POB();
		}
	}
}

void Print()
{
	int i;

	for(i=0;i<vert;i++)
	{
		cout<<Flag[i]<<"  ";
	}cout<<endl;
	for(i=0;i<vert;i++)
	{
		cout<<Order[i]<<"  ";
	}cout<<endl;
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("ttt.out","w",stdout);
	int pp,cc,res,tt,i,u,v,l,j,k;

	scanf("%d",&tt);

	while(tt--)
	{
		scanf("%d %d",&vert,&edge);
		Init();

		memset(Flag,-1,sizeof(Flag));
		memset(f,0,sizeof(f));
		memset(freq,0,sizeof(freq));
		memset(Connected,0,sizeof(Connected));
		for(i=0;i<edge;i++)
		{
			scanf("%d %d",&u,&v);
			u--;v--;
			//r[u][v]=1;
			//tr[v][u]=1;
			r[u].Ed.PB(v);
			tr[v].Ed.PB(u);
			Connected[u]=1;
			Connected[v]=1;
		}

		scc();
		//Print();

		for(i=0;i<vert;i++)
		{
			if(Flag[i]>=0)
			{
				f[Flag[i]]=1;
			}
		}

		for(i=0;i<vert;i++)
		{
			l=r[i].Ed.size();
			for(j=0;j<l;j++)
			{
				k=r[i].Ed[j];
				if(Flag[k]!=Flag[i])
				{
					arr[Flag[i]].Out++;
					arr[Flag[k]].In++;

				}
			}
		}

		/*for(i=0;i<vert;i++)
		{
			printf("%d In %d Out %d\n",i,arr[i].In,arr[i].Out);
		}*/
		res=0;
		for(i=0;i<vert;i++)
		{
			if(arr[i].In==0  && f[i]  && Connected[i])
			{
				res++;
			}
			if(!Connected[i])
			{
				res++;
			}
		}

		cout<<res<<endl;
	}
	return 0;
}

/*

2
8 14

1 2
2 3 2 5 2 6
3 4 3 7
4 3 4 8
5 1 5 6
6 7
7 6 7 8
8 8



*/
