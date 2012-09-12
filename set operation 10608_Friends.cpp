#include<stdio.h>

#define CSE 31000

long vertex[CSE],rank[CSE],len[CSE];
long vert,edge;

void init()
{
	long i;

	for(i=0;i<=vert;i++)
	{
		len[i]=0;
		rank[i]=0;
		vertex[i]=i;
	}

	return;
}

long Find_set(long num)
{
	if(num!=vertex[num])
	{
		vertex[num]=Find_set(vertex[num]);
	}

	return vertex[num];
}

void Link(long x,long y)
{
	if(rank[x]>rank[y])
	{
		vertex[x]=vertex[y];
	}
	else
	{
		vertex[y]=x;
		if(rank[x]==rank[y])
		{
			rank[y]++;
		}
	}
	return;
}

long Find_max()
{
	long r,i,max;

	for(i=1;i<=vert;i++)
	{
		r=Find_set(i);
		len[r]++;
	}

	max=0;

	for(i=1;i<=vert;i++)
	{
		if(max<len[i])
		{
			max=len[i];
		}
	}

	return max;
}

void UNION(long x,long y)
{
	Link(Find_set(x),Find_set(y));

	return;
}

int main()
{
	long tcase,i,x,y,r;

	scanf("%ld",&tcase);

	while(tcase--)
	{
		
		scanf("%ld%ld",&vert,&edge);

		init();
		
		for(i=1;i<=edge;i++)
		{
			scanf("%ld%ld",&x,&y);

			if(Find_set(x)!=Find_set(y))
			{
				UNION(x,y);
			}
		}

		r=Find_max();

		printf("%ld\n",r);
	}

	return 0;
}