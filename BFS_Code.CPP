#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>

#define CSE 10
#define NIL 0
#define INF 1000000

char color[CSE];

long mat[CSE][CSE];
long par[CSE],dist[CSE];

long que[CSE*CSE],head,tail;
long vert,edge,start,end;

void enqueue(long data)
{
	que[tail++]=data;

	return;
}

long dequeue()
{
	if(head==tail)
	{
        return -1;
	}
	head=head+1;
    return que[head-1];
}

void printPath(long Vnode)
{
	
	if(start==Vnode)
	{
		printf(" %ld",start);
	}
	else if(par[Vnode]==NIL)
	{
		printf("\nNO PATH EXISTS.\n");
	}
	else
    {
		printPath(par[Vnode]);
		printf(" --> %ld",Vnode);
    }
}


void bfs()
{
	head=tail=0;
	long adj,y;
	for(y=1;y<=vert;y++)
	{
        color[y]='w';
		dist[y]=INF;
        par[y]=NIL;
	}

	par[start]=NIL;
	dist[start]=0;
	
	color[start]='g';
	enqueue(start);

	while((y=dequeue())>=0)
	{
        for(adj=1;adj<=vert;adj++)
		{
			
			if(mat[y][adj]==1)
			{
				
				if(color[adj]=='w')
				{
					par[adj]=y;
					color[adj]='g';
					dist[adj]=dist[y]+1;
                    enqueue(adj);
				}
			}
		}
		color[y]='b';        	
	}
}

int main()
{
	long i;

	while(scanf("%ld %ld",&vert,&edge)==2)
	{
		for(i=1;i<=edge;i++)
		{
			scanf("%ld%ld",&start,&end);
			mat[start][end]=1;  
			//mat[end][start]=1;
		}
		scanf("%ld %ld",&start,&end);
		bfs();
		printPath(end);
		printf("\nThe distance from %ld to %ld is = %ld\n",start,end,dist[end]);
	}
	return 0;
}
