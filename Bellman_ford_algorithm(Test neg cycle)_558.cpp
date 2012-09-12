//jony cse 2004 SUSt
//Bellman ford algorithm.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define Maxnode 1009
#define Maxedge 2009
#define INF 1000000000L

struct Graph
{
	long Start;
	long End;
	long Weight;
};

Graph a[Maxedge];

long Dist[Maxnode],Node,Edge;

bool Bellman(int Source)
{
	long i,j;

	for(i=0;i<=Node;i++)
	{
		Dist[i]=INF;
	}

	Dist[Source]=0;

	for(i=0;i<Node;i++)
	{
		for(j=0;j<Edge;j++)
		{
			if(Dist[a[j].End]>Dist[a[j].Start]+a[j].Weight)
			{
				Dist[a[j].End]=Dist[a[j].Start]+a[j].Weight;
			}
		}
	}

	//Check Negative cycle

	for(i=0;i<Edge;i++)
	{
		if(Dist[a[i].End]>Dist[a[i].Start]+a[i].Weight)
		{
			return 1;
		}
	}

	return 0;
}

int main()
{
	long Tcase,i;
	bool flag;

	scanf("%ld",&Tcase);

	while(Tcase--)
	{
		scanf("%ld %ld",&Node,&Edge);

		for(i=0;i<Edge;i++)
		{
			scanf("%ld %ld %ld",&a[i].Start,&a[i].End,&a[i].Weight);
		}

		flag=Bellman(0);

		if(flag)
		{
			printf("possible\n");
		}
		else
		{
			printf("not possible\n");
		}
	}
	return 0;
}