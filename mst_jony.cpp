#include<stdio.h>
#include<string.h>

#define INF 50000
#define Node 100

typedef struct 
{
	long a;
	long b;
	long len;
}Graph;

Graph temp,min,arr[Node+1];

long mat[Node+1][Node+1],tree[Node+1],pos[Node+1],inp[Node+1][Node+1];
long len,vert,edges,top,k;

void push(Graph data)
{
	arr[top]=data;
	top++;

	return;
}

void init()
{
	long i,j;

	for(i=1;i<=vert;i++)
	{
		for(j=1;j<=vert;j++)
		{
			mat[i][j]=INF;
		}
	}

	for(i=0;i<=vert;i++)
	{
		mat[i][0]=0;
		mat[0][i]=0;
	}

	len=0;
	min.len=INF;

	memset(pos,0,sizeof(pos));

	return;
}

Graph Find_min(long p)
{
	long j;
	Graph m;
	m.a=p;
	m.len=INF;

	for(j=1;j<=vert && mat[p][0];j++)
	{
		if(mat[p][j]<INF)
		{
			if(pos[j]==0)
			{
				if(m.len>mat[p][j])
				{
					m.len=mat[p][j];
					m.b=j;
				}
			}
		}
	}

	return m;

}

void PRIM()
{
	long i;

	push(min);
	
	len=min.len;
	
	mat[min.a][0]--;
	mat[min.b][0]--;
	mat[min.a][min.b]=mat[min.b][min.a]=INF;

	tree[0]=min.a;
	tree[1]=min.b;
	k=2;

	pos[min.a]=1;
	pos[min.b]=2;

	while(1)
	{
		if(k==vert)
		{
			break;
		}
		min.len=INF;

		for(i=0;i<k;i++)
		{
			temp=Find_min(tree[i]);
			
			if(min.len>temp.len)
			{
				min=temp;
			}
		}
		
		push(min);
		
		mat[min.a][0]--;
		mat[min.b][0]--;
		mat[min.a][min.b]=mat[min.b][min.a]=INF;

		tree[k]=min.b;
		pos[min.b]=++k;

		len+=min.len;

	}



}

int main()
{
	long i;
    Graph g;

	while(scanf("%ld%ld",&vert,&edges)==2)
	{
		init();
		top=0;

		for(i=1;i<=edges;i++)
		{
			scanf("%ld%ld%ld",&g.a,&g.b,&g.len);
			
			mat[g.a][g.b]=g.len;
			mat[g.b][g.a]=g.len;
			mat[g.a][0]++;
			mat[g.b][0]++;
			
			if(min.len>g.len)
			{
				min.len=g.len;
				min.a=g.a;
				min.b=g.b;
			}
		}

		PRIM();

		printf("\nOUTPUT : \n\n");

		for(i=0;i<top;i++)
		{
			printf("%ld -> %ld   %ld\n",arr[i].a,arr[i].b,arr[i].len);
		}
	}

	return 0;
}