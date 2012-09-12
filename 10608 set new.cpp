#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#define CSE 30009

struct SSS
{
	int cnt;
	int parent;
	int rank;
};

SSS arr[CSE];
int node,edge,rtt;

int MAX(int aa,int bb)
{
	if(aa>bb)
	{
		return aa;
	}
	return bb;
}

void init()
{
	for(int i=0;i<=node;i++)
	{
		arr[i].cnt=1;
		arr[i].parent=i;
		arr[i].rank=0;
	}
}

int Find(int num)
{
	if(arr[num].parent!=num)
	{
		arr[num].parent=Find(arr[num].parent);
	}
	return arr[num].parent;
}

void Union(int x,int y)
{
	if(arr[x].rank > arr[y].rank)
	{
		arr[y].parent=x;
		arr[x].cnt+=arr[y].cnt;
		rtt=MAX(rtt,arr[x].cnt);
	}
	else
	{
		arr[x].parent=y;
		arr[y].cnt+=arr[x].cnt;
		rtt=MAX(rtt,arr[y].cnt);
		if(arr[x].rank ==  arr[y].rank)
		{
			arr[y].rank++;
		}
	}
}

int main()
{
	int t,i,x,y;
	int p,q;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&node,&edge);
		init();
		rtt=0;
		
		for(i=0;i<edge;i++)
		{
			scanf("%d %d",&x,&y);
			p=Find(x);
			q=Find(y);
			if(p != q)
			{
				Union(p,q);
			}
		}
		printf("%d\n",rtt);
	}

	return 0;
}