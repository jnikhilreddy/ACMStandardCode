#include<stdio.h>

#define INF 1000000

#define CSE 30

struct Graph
{
	long Num_of_adj;
	long adj[CSE];
	long weight[CSE];
};

Graph a[CSE];

long cost[CSE],par[CSE],heap[CSE];
long heapsize; 

void Take_input(long vert,long edge,bool directed)
{
	long i,u,v,w;

	for(i=1;i<=vert;i++)
	{
		a[i].Num_of_adj=0;
	}

	while(edge--)
	{
		scanf("%ld%ld%ld",&u,&v,&w);
		a[u].adj[a[u].Num_of_adj]=v;
		a[u].weight[a[u].Num_of_adj++]=w;
		if(!directed)
		{
			a[v].adj[a[v].Num_of_adj]=u;
			a[v].weight[a[v].Num_of_adj++]=w;
		}
	}
}

long parent_of_ptr(long val)
{
	return val/2;
}



void Del_heap(long N)
{
	long left,right,last,ptr;

	ptr=1;
	left=2;
	right=3;

	last=heap[N];

	while(right<=N)
	{
		if(last>=heap[left]  && last>=heap[right])
		{
			heap[ptr]=last;
			return;
		}
		if(heap[right]<=heap[left])
		{
			heap[ptr]=heap[left];
			ptr=left;
		}
		if(heap[left]<=heap[right])
		{
			heap[ptr]=heap[right];
			ptr=right;
		}
		left=ptr*2;
		right=left+1;
	}

	if(left==N  && last<heap[left])
	{
		ptr=left;
	}

	heap[ptr]=last;

	return;
}

long ExtractMin()
{
	long min;

	min=heap[1];

	Del_heap(heapsize);
	heapsize--;

	return min;
}

void Insert_heap(long N,long item)
{
	long ptr,parent;

	N++;
	ptr=N;

	while(ptr>1)
	{
		parent=parent_of_ptr(ptr);
		if(item>=heap[parent])
		{
			heap[ptr]=item;
			return;
		}
		heap[ptr]=heap[parent];
		ptr=parent;
	}
	heap[ptr]=item;

	return;
}

void Init(long start,long vert)
{
	long i;

	for(i=0;i<=vert;i++)
	{
		cost[i]=INF;
		par[i]=-1;
	}
	cost[start]=0;
	heapsize=1;
	heap[heapsize++]=start;

	return;
}

void DJ(long start,long vert)
{
	long i,u;
	Init(start,vert);

	while(heapsize>0)
	{
		u=ExtractMin();

		for(i=0;i<a[u].Num_of_adj;i++)
		{
			if(cost[u]+a[u].weight[i]<cost[a[u].adj[i]])
			{
				par[a[u].adj[i]]=u;
				cost[a[u].adj[i]]=cost[u]+a[u].weight[i];
				Insert_heap(heapsize++,a[u].adj[i]);
			}
		}
	}
}

void PrintPath(long v)
{
	if(par[v]==-1)
	{
		printf("%ld",v);
		return;
	}
	else
	{
		PrintPath(par[v]);
		printf(" %ld",v);
	}
}

int main()
{
	long vert,edge,start,i;

	while(scanf("%ld%ld",&vert,&edge)==2)
	{
		Take_input(vert,edge,true);
		
		scanf("%ld",&start);

		DJ(start,vert);

		for(i=1;i<=vert;i++)
		{
			printf("path from %ld to %ld :\n",start,i);
			PrintPath(i);
			printf("\ncost : %ld \n\n",cost[i]);
		}

	}

	return 0;
}