#include<string.h>
#include<stdio.h>
#include<math.h>

#define NODE_NUM 30

bool graph[NODE_NUM][NODE_NUM],finished;
int optimal;
long yy;

void backtrack(int n,int k,int a[],int max);
void construct_candidate(int n,int k,int a[],int c[],int *ncandidate,int max);

void main()
{
	int a[NODE_NUM];
	int v,e,i,s,t;
	while(scanf("%ld %ld",&v,&e)==2)
	{
		for(i=0;i<e;i++)
		{
			scanf("%ld %ld",&s,&t);
			graph[s][t]=true;
			graph[t][s]=true;
		}
		optimal=10000;
		backtrack(v,0,a,0);
		printf("Minimum color required %ld.\n",optimal);
		printf("Backtrack Call = %ld.\n",yy);
		memset(graph,0,sizeof(graph));
		yy=0;
	}
}

void backtrack(int n,int k,int a[],int max)
{
	yy++;
	if(n==k)
	{
		if(optimal>max)
			optimal=max;
	}
	else
	{
		k++;
		int c[NODE_NUM],ncandidate,i;
		construct_candidate(n,k,a,c,&ncandidate,max);
		for(i=1;i<ncandidate;i++)
		{
			a[k]=c[i];
			if(max<a[k])
				max=a[k];
			backtrack(n,k,a,max);
		}
	}
}

void construct_candidate(int n,int k,int a[],int c[],int *ncandidate,int max)
{
	bool valid_color[NODE_NUM];
	int i;
	memset(valid_color,0,sizeof(valid_color));
	for(i=1;i<k;i++)
		if(graph[k][i])
			valid_color[a[i]]=true;
	*ncandidate=1;
	for(i=1;i<=max;i++)
		if(valid_color[i]==false)
			c[(*ncandidate)++]=i;
	c[(*ncandidate)++]=max+1;
}