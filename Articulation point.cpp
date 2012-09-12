#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>

#include<algorithm>
using namespace std;

#define CSE 10

bool mat[CSE][CSE];
long edge,node,Articulation_point[CSE],ap_count,pp;

struct SSS
{
	char color;
	long discover,back,chk;
};

SSS all_node[CSE];

void input()
{
	long i,e,s;

	for(i=0;i<edge;i++)
	{
		scanf("%ld %ld",&s,&e);
		mat[s][e]=1;
		mat[e][s]=1;
	}
	return ;
}

void DFS_visit(long source)
{
	long i;

	pp++;

	all_node[source].back=pp;
	all_node[source].discover=pp;
	all_node[source].color='g';

	for(i=1;i<=node;i++)
	{
		if(mat[source][i])
		{
			if(all_node[i].color=='w')
			{
				DFS_visit(i);
				all_node[source].back=(all_node[source].back>all_node[i].back)?all_node[i].back:all_node[source].back;
				if(all_node[source].chk)
				{
					if(all_node[source].discover==1 && all_node[i].discover!=2)
					{
						Articulation_point[ap_count++] = source;
						all_node[source].chk = 0;
					}

					if(all_node[source].discover!=1 && all_node[i].back>=all_node[source].discover)
					{
						Articulation_point[ap_count++] = source;
						all_node[source].chk = 0;
					}
				}
			}
			else
			{
				all_node[source].back = (all_node[source].back>all_node[i].discover)?all_node[i].discover:all_node[source].back;				
			}
		}
	}

}

void DFS()
{
	long i;
	for(i=0;i<=node;i++)
	{
		all_node[i].chk=1;
		all_node[i].color='w';
		all_node[i].back=0;
		all_node[i].discover=0;
	}

	for(i=1;i<=node;i++)
	{
		if(all_node[i].color=='w')
		{
			pp=0;
			DFS_visit(i);
		}
	}
}

int main()
{	
	//freopen("t.in","r",stdin);
	//freopen("ttt.out","w",stdout);

	long i;
	while(scanf("%ld %ld",&node,&edge)==2)
	{
		memset(mat,0,sizeof(mat));
		input();

		ap_count=0;

		DFS();

		printf("no of Articulation Point %ld\n",ap_count);
		printf("The Articulation Point are:\n");
		for(i=0;i<ap_count;i++)
		{
			printf(" %ld",Articulation_point[i]);
		}
		printf("\n");
	}
	
	return 0;
}

/*
input:

6 7

1 2
1 3
2 3
3 4
4 5
4 6
5 6


*/
