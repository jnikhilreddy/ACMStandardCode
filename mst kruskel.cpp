#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define CSE  200009

struct Graph
{
	long u;
	long v;
	long w;
};

Graph Heap[CSE],Min,Node,temp;


long heapsize,vert,edge;
long Set[CSE],rank[CSE],tot;

long Left(long num)
{
	return num*2; 
}

long Right(long num)
{
	return (num*2+1);
}

long Parent(long num)
{
	return (num/2);
}

void Insert_to_heap(Graph tNode)
{
	heapsize++;
	int i = heapsize;
	while(i > 1 && Heap[Parent(i)].w > tNode.w)
	{
		Heap[i] = Heap[Parent(i)];
		i = Parent(i);
	}
   	Heap[i].u = tNode.u;
   	Heap[i].v = tNode.v;
	Heap[i].w = tNode.w;

	return ;
}

void Make_set(long x)
{
	Set[x] = x;
	rank[x] = 0;

	return;
}

long find_set(long x)
{
	if(x != Set[x])
	{
		Set[x] = find_set(Set[x]);
	}
	return Set[x];
}

void link(long x,long y)
{
	if(rank[x] > rank[y])
	{
		Set[y] = x;
	}
	else
	{
		Set[x] = y;
		if(rank[x] == rank[y])
		{
			rank[y]++;
		}
	}

	return;
}

void Union(long x,long y)
{
	link (find_set(x), find_set(y));
}

void Take_input(bool directed)
{
	tot=0;
	long i;
	heapsize=0;

	/*for(i=1;i<=vert;i++)
	{
		scanf("%lf %lf",&p[i].x,&p[i].y);
	}*/


	for(i=1;i<=edge;i++)
	{
		scanf("%d %d %d",&Node.u,&Node.v,&Node.w);
		Node.u++;
		Node.v++;
		tot+=Node.w;
		Insert_to_heap(Node);
	}

	/*for(i=1;i<=vert;i++)
	{
		for(j=i+1;j<=vert;j++)
		{
			w=sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x) + (p[i].y-p[j].y)*(p[i].y-p[j].y));
			edge++;
			Node.u=i;
			Node.v=j;
			Node.w=w;
			Insert_to_heap(Node);
		}
	}*/

	for(i=1;i<=vert;i++)
	{
		Make_set(i);
	}

	/*scanf("%ld ",&M);

	for(i=1;i<=M;i++)
	{
		scanf("%ld %ld",&u,&v);
		Union(u,v);
	}*/
	return;
}

void heapify(long i)
{
	long smallest;
	long l = Left(i);
	long r = Right(i);

	if(l<=heapsize && Heap[l].w < Heap[i].w)
	{
		smallest = l;
	}
	else
	{
		smallest = i;
	}
	if(r<=heapsize && Heap[r].w < Heap[smallest].w)
	{	
		smallest = r;
	}
	if(smallest != i)
	{
		temp = Heap[smallest];
		Heap[smallest] = Heap[i];
		Heap[i] = temp;
		heapify(smallest);
	}

	return;
}

Graph ExtractMin()
{
   	
	Min.u=Heap[1].u;
	Min.v=Heap[1].v;
	Min.w=Heap[1].w;
	
	Heap[1] = Heap[heapsize];
	heapsize--;
	heapify(1);
	
	return Min;
}

int main()
{
	long i;
	long res;
	Graph r;
	while(scanf("%ld %ld",&vert,&edge)==2)
	{
		if(vert==0 && edge==0)
		{
			break;
		}
		Take_input(false);

		res=0;

		for(i=1;i<edge;i++)
		{
			r=ExtractMin();

			if(find_set(r.u)!=find_set(r.v))
			{
				res+=r.w;
				Union(r.u,r.v);
			}
		}
		//printf("Tot   %ld\n",tot);
		//printf("Res   %ld\n",res);
		printf("Res   %ld\n",res);
	}

	return 0;
}