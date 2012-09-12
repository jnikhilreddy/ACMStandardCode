#include<stdio.h>
#include<string.h>
#include<math.h>

#define CSE 109
#define INF 1000000
#define NULL 0
#define Left(i) (i*2)
#define Rigt(i) (i*2+1)
#define Parent(i) (i/2)

#define swap(a, b) a^=b^=a^=b

long flag[CSE];

struct Graph
{
	long Num_of_adj;
	long adj[CSE];
	long weight[CSE];
};

struct SSS
{
	long u,v;
	long w;
};

SSS save[CSE];

Graph tree[CSE],a[CSE];
long parent[CSE], index[CSE],CS;
long heapSize, heap[CSE],vert,edge,source,n;
long key[CSE],RES;

void Take_input(bool directed)
{
	long i,u,v;
	long w;

	RES=0;
	CS=5;

	for(i=1;i<=vert;i++)
	{
		a[i].Num_of_adj=1;
		flag[i]=0;
	}

	for(i=0;i<edge;i++)
	{
		scanf("%ld %ld %ld",&u,&v,&w);
		//u++;v++;
		a[u].adj[a[u].Num_of_adj]=v;
		a[u].weight[a[u].Num_of_adj++]=w;
		if(!directed)
		{
			a[v].adj[a[v].Num_of_adj]=u;
			a[v].weight[a[v].Num_of_adj++]=w;
		}
	}
}


void InitializeSingleSource()
{
	long ind;

	for(ind=1; ind<=vert; ind++)
	{
		key[ind]=INF;
		index[ind] = ind;
		parent[ind]=NULL;

        heap[ind] = ind;
	}
	heapSize = vert;

	return;
}

void MinHeapify(long ind, long node)
{
	long left, rigt, smallest;

	left = Left(ind);
	rigt = Rigt(ind);

	if(left <= heapSize && key[heap[ind]] > key[heap[left]])
	{
		smallest = left;
	}
	else
	{
		smallest = ind;
	}
	if(rigt <= heapSize && key[heap[smallest]] > key[heap[rigt]])
	{
		smallest = rigt;
	}
	if(smallest != ind)
	{
		swap(heap[smallest], heap[ind]);
		swap(index[heap[smallest]], index[heap[ind]]);

		MinHeapify(smallest, node);
	}
	else
	{
		index[node] = ind;
	}
}

long HeapExtractMin(void)
{
	long node;

	node = heap[1];

	heap[1] = heap[heapSize];
	index[heap[1]] = 1;
	heapSize-= 1;

	MinHeapify(1, heap[1]);
	return node;
}

void HeapDecreaseKey(long ind, long node, long cost)
{
	key[node] = cost;

	while(ind > 1 && key[heap[Parent(ind)]] > key[heap[ind]])
	{
		swap(heap[Parent(ind)], heap[ind]);
		swap(index[heap[Parent(ind)]], index[heap[ind]]);

		ind = Parent(ind);
	}
	index[node] = ind;
}


void Prims()
{
	InitializeSingleSource();

	long uNode, vNode,ind, knd = 0,pik=1;

	source = 1;
	key[source] = 0;
	index[source] = 1;
    parent[source] = NULL;

	while(heapSize > 0)
	{
		uNode = HeapExtractMin();
		index[uNode] = -1;
		if(pik>1)
		{
			RES+=key[uNode];
		}
		pik=5;
		
		save[knd].u=parent[uNode];
		save[knd].v=uNode;
		save[knd].w=key[uNode];
		knd+=1;
	
		for(ind = 1; ind <a[uNode].Num_of_adj; ind++)
		{
			vNode = a[uNode].adj[ind];

			if(index[vNode] > 0 && a[uNode].weight[ind] < key[vNode])
			{
				parent[vNode] = uNode;
				HeapDecreaseKey(index[vNode], vNode, a[uNode].weight[ind]);
			}
		}
	}
	return ;
}

int main()
{
	long i,pik=1;
	while(scanf("%ld %ld",&vert,&edge)==2)
	{
		Take_input(false);

		Prims();

		if(pik>1)
		{
			printf("\n");
		}
		pik=5;

		printf("Res   %ld\n",RES);
		for(i=1;i<vert;i++)
		{
			printf("%ld to %ld  cost %ld\n",save[i].u,save[i].v,save[i].w);
		}

	}

	return 0;
}



/*

9 14


1 2 4
1 8 8
2 3 8
2 8 11
8 9 7
8 7 1
9 7 6
9 3 2
7 6 2
3 4 7
3 6 4
4 5 9
4 6 14
5 6 10

output:
8 7 1
7 6 2
6 3 4
3 9 2
3 4 7
8 1 8
1 2 4
4 5 9


*/