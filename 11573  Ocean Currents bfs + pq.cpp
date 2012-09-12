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

#define PB push_back
#define POB pop_back

#define CSE 1009
#define INF 100009

int dx[9]={0,-1,-1,-1,0,1,1,1,0};
int dy[9]={0,-1,0,1,1,1,0,-1,-1};

int ax[9]={-1,7,0,1,2,3,4,5,6};

struct SSS
{
	int x,y;
};

char str[CSE];
bool color[CSE][CSE];
SSS que0[CSE*CSE],que1[CSE*CSE];
int head,tail;
int Head2,Tail2;
int r,c,mat[CSE][CSE],dist[CSE][CSE];
SSS par[CSE][CSE];

SSS st,ed;

void Enq0(SSS data)
{
	que0[tail++]=data;
	return ;
}

bool valid(int x,int y)
{
	if(x<1 || y<1)
	{
		return 0;
	}
	if(x>r || y>c)
	{
		return 0;
	}
	return 1;
}

SSS Deq0()
{
	SSS xx;
	xx.x=0;
	xx.y=0;
	if(head==tail)
	{
		return xx;
	}
	xx=que0[head];
	head++;
	return xx;
}
void Enq1(SSS data)
{
	que1[Tail2++]=data;
	return ;
}

SSS Deq1()
{
	SSS xx;
	xx.x=0;
	xx.y=0;
	if(Head2==Tail2)
	{
		return xx;
	}
	xx=que1[Head2];
	Head2++;
	return xx;
}

int find_loc(int data)
{
	int i;
	for(i=1;i<=8;i++)
	{
		if(ax[i]==data)
		{
			return i;
		}
	}
	return 0;
}

int bfs()
{
	memset(dist,63,sizeof(dist));
	par[st.x][st.y].x=par[st.x][st.y].y=0;

	if(st.x==ed.x  && st.y==ed.y)
	{
		return 0;
	}
	//color[st.x][st.y]=1;
	dist[st.x][st.y]=0;
	Enq0(st);

	int i,loc;
	SSS yy,u;

	while(1)
	{
		yy=Deq0();
		if(yy.x==0)
		{
			yy=Deq1();
		}
		if(yy.x==0)
		{
			break;
		}	

		loc=find_loc(mat[yy.x][yy.y]);

		for(i=1;i<=8;i++)
		{
				u.x=dx[i];
				u.y=dy[i];
				u.x+=yy.x;
				u.y+=yy.y;

				if(valid(u.x,u.y) && color[u.x][u.y]==0)
				{
					if(i==loc)
					{
						if (dist[u.x][u.y] > dist[yy.x][yy.y])
						{
							dist[u.x][u.y] = dist[yy.x][yy.y];
							Enq0(u);
						}
					}
					else
					{
						if (dist[u.x][u.y] > dist[yy.x][yy.y]+1){
							dist[u.x][u.y] = dist[yy.x][yy.y]+1;
							Enq1(u);
						}
					}
				}
			
		}

	}

	return dist[ed.x][ed.y];
	
}

void PP(SSS v)
{
	if(st.x==v.x  && st.y==v.y)
	{
		printf("%d %d",st.x,st.y);
	}
	else
	{
		PP(par[v.x][v.y]);
		printf("-> %d %d",v.x,v.y);
	}
}

int main()
{	
	//freopen("a.in","r",stdin);
	//freopen("aa.out","w",stdout);
	int i,j;
	int t;
	while(  scanf("%d %d",&r,&c)==2 )
	{
	
		for(i=0;i<r;i++)
		{
			scanf(" %s",str);
			for(j=0;j<c;j++)
			{
				mat[i+1][j+1]=str[j]-'0';
			}
		}
		scanf("%d",&t);
		while(t--)
		{
			head=tail=0;
			Head2=Tail2=0;
			scanf("%d %d %d %d",&st.x,&st.y,&ed.x,&ed.y);
			memset(color,0,sizeof(color));
			memset(dist,0,sizeof(dist));
			i=bfs();

			printf("%d\n",i);
		}
	}

	return 0;
}

/*
10 10
6051134354
2321601626
4333237711
7100435246
1073373445
7444061776
7570714166
2261637531
6527302645
2035001421
55
2 5 8 5
*/