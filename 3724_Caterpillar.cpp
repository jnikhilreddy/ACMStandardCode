#include<stdio.h>
#include<math.h>

#define CSE 109
#define NIL 0
#define INF 1000000

char color[CSE];

long mat[CSE][CSE];
long parent[CSE],dist[CSE],fin[CSE];

long pik,vert,edge,start,end,Unode,time=0,tree;

bool flag[CSE];

struct Graph
{
	long no_of_adj;
	long ADJ[CSE];
};

Graph a[CSE];

void init()
{
	long i,j;
	for(i=0;i<CSE-2;i++)
	{
		flag[i]=0;
		a[i].no_of_adj=0;

		for(j=0;j<CSE-2;j++)
		{
			mat[i][j]=NIL;
		}
	}


	return ;
}

void DFS_Visit(long U)
{
	long adj,cnt,pos;
	
	color[U]='g';
	
	dist[U]=time=time+1;

	cnt=0;

	for(adj=1;adj<=vert;adj++)
	{
		if(mat[U][adj]==1)
		{
			if(color[adj]=='w')
			{
        		//printf("%ld  ",adj);

				parent[adj]=U;
/*----------*/  DFS_Visit(adj);
            }
			else
			{
				cnt++;
				if(cnt==2)
				{
					pos=U;
				}
			}
		}
	}

	if(cnt==2)
	{
		pik=2;
		printf("\nThere is a cycle.  %ld \n",pos);
	}

	color[U]='b';
	fin[U]=time=time+1;
}

void DFS()
{
	 tree=0;
	
	for(Unode=1;Unode<=vert;Unode++)
	{
        color[Unode]='w';
		dist[Unode]=INF;
        parent[Unode]=NIL;
	}

	for(Unode=1;Unode<=vert;Unode++)
	{

		if(color[Unode]=='w')
		{
			tree++;
       		//printf("\nTree %ld : \n",++tree);
			//printf("%ld  ",Unode);
	/*-------*/	DFS_Visit(Unode);
			//printf("\n");
		}

	}

}

long Cheque(long Node)
{
	long i,j,cnt;
	
	cnt=0;

	for(i=1;i<=Node;i++)
	{
		cnt=0;
		for(j=0;j<a[i].no_of_adj;j++)
		{
			if(a[a[i].ADJ[j]].no_of_adj>1)
			{
				cnt++;
			}
		}
		if(cnt>2)
		{
			return 0;
		}
	}

	return 1;
}

int main()
{
	long i,y,CS=1;

	while(scanf("%ld",&vert)==1  && vert)
	{
		init();
		scanf("%ld",&edge);
		for(i=1;i<=edge;i++)
		{
			scanf("%ld%ld",&start,&end);
        
			mat[start][end]=1;
			mat[end][start]=1;

			a[start].ADJ[a[start].no_of_adj++]=end;
			a[end].ADJ[a[end].no_of_adj++]=start;
			
		}

		pik=1;

		DFS();

		y=Cheque(vert);

		//printf("Tree %ld pik  %ld  y = %ld\n",tree,pik,y);

		if(pik==1 && tree == 1  && y == 1)
		{
			printf("Graph %ld is a caterpillar.\n",CS++);
		}
		else
		{
			printf("Graph %ld is not a caterpillar.\n",CS++);
		}
	}

	return 0;
}

