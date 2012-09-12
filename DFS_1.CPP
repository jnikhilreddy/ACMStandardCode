/*DFS code by chormen*/
#include<stdio.h>
#include<math.h>

#define sz 10
#define NIL 0
#define INF 1000000

char color[sz];

long mat[sz][sz];
long par[sz],dist[sz],fin[sz];

long vert,edge,start,end,Unode,time=0;



/*printing path from one node to another node*/
void printPath(long V)
{
	
	if(start==V)
		printf(" %ld",start);
	
	else if(par[V]==NIL)
		printf("\nNO PATH EXISTS.\n");
	
	else
    {
		printPath(par[V]);
		printf(" --> %ld",V);
    }
}



void DFS_Visit(long U)
{
	long adj;
	
	color[U]='g';
	
	dist[U]=time=time+1;

	for(adj=1;adj<=vert;adj++)
	{
		if(mat[U][adj]==1)
		{
			if(color[adj]=='w')
			{
        		printf("%ld\t",adj);

				par[adj]=U;
				DFS_Visit(adj);
            }
		}
	}

	color[U]='b';
	fin[U]=time=time+1;
}

void DFS()
{
	long tree=0;
	
	for(Unode=1;Unode<=vert;Unode++)
	{
        color[Unode]='w';
		dist[Unode]=INF;
        par[Unode]=NIL;
	}

	for(Unode=1;Unode<=vert;Unode++)
	{

		if(color[Unode]=='w')
		{
       		printf("\nTree %ld : \n",++tree);
			printf("%ld\t",Unode);
			DFS_Visit(Unode);
			printf("\n");
		}

	}

}

void main(void)
{
	long i;

	printf("give the number of vertices and edges:\n");
	
	printf("vertices = ");
	scanf("%ld",&vert);
	
	printf("edges = ");
	scanf("%ld",&edge);

	printf("\nGive start point & end point of each edges:\n");

	for(i=1;i<=edge;i++)
	{
		printf("Edge %ld :",i);
		scanf("%ld%ld",&start,&end);
        
		mat[start][end]=1;
		mat[end][start]=1;
	}

	
	DFS();

	printf("\nChecking if two vertices are reachabele.");
	printf("\nEnter 0 for start or end to terminate:\n");
	
	do
	{
		printf("\nGive the starting and ending vertex:\n");
		printf("Starting vertex : ");
		scanf("%ld",&start);
		printf("Ending vertex : ");
		scanf("%ld",&end);

		if(start==0 || end==0) break;

		printPath(end);

	}while(1);

}

