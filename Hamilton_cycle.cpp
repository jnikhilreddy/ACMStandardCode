#include<stdio.h>
#include<string.h>

#define NODE_NUM 20

bool graph[NODE_NUM][NODE_NUM],finished;

bool flag[NODE_NUM];

void construct_candidate(int n,int k,int a[],int c[],int *ncandidate)
{
	int i;

	*ncandidate=0;
	
	for(i=2;i<=n;i++)
	{
		if(graph[a[k-1]][i] && flag[i]==false)
		{
			c[(*ncandidate)++]=i;
		}
	}
}

void backtrack(int n,int k,int a[])
{
	int c[NODE_NUM],ncandidate,i;

	if(k==n)
	{
		/*printf("UP:\n");
		for(i=0;i<k;i++)
			{
				printf("%d ",a[i]);
			}
		printf("\nEnd\n");*/
		if(graph[a[k-1]][a[0]])
		{	
			finished=true;
			//printf("RES :                ");
			for(i=0;i<k;i++)
			{
				printf("%d ",a[i]);
			}
			printf("%d\n",a[0]);
		}
	
	}
	else
	{
		construct_candidate(n,k,a,c,&ncandidate);
		for(i=0;i<ncandidate;i++)
		{
			a[k]=c[i];
			flag[a[k]]=true;
/*------------*/backtrack(n,k+1,a);
			flag[a[k]]=false;
			
		}
	}
}

void main()
{
	int a[NODE_NUM],s,t,v,e,i,k;
	while(scanf("%d %d",&v,&e)==2)
	{
		for(i=0;i<e;i++)
		{
			scanf("%ld %ld",&s,&t);
			graph[s][t]=true;
			graph[t][s]=true;
		}
		k=0;
		a[k]=1;
		finished=false;
		backtrack(v,k+1,a);
		if(finished==false)
			printf("No path.\n");
		memset(graph,0,sizeof(graph));
		memset(flag,0,sizeof(flag));
	}
}
