#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define CSE 109

long mat[CSE][CSE],res[CSE];
long edge,vert,max,color_num,cnt;

void Init()
{
	long i,j;

	for(i=0;i<=vert;i++)
	{
		for(j=0;j<=vert;j++)
		{
			mat[i][j]=0;
		}
	}

	return ;
}

void Take_input()
{
	long i,u,v;

	for(i=1;i<=edge;i++)
	{
		scanf("%ld%ld",&u,&v);
		mat[u][v]=1;
		mat[v][u]=1;
	}

	return;
}
void Construct_can(long k,long a[],long c[],long *Ncan)
{
	bool flag[CSE];
	long i;

	for(i=1;i<=color_num;i++)
	{
		flag[i]=true;
	}

	for(i=1;i<k;i++)
	{
		if(mat[k][i])
		{
			if(a[i]==1)
			{
				flag[1]=false;
			}
		}
	}

	*Ncan=0;

	for(i=1;i<=color_num;i++)
	{
		if(flag[i])
		{
			c[(*Ncan)++]=i;
		}
	}

	return;
}
void Backtrack(long k,long a[])
{
	long c[CSE],Ncan,i;
	if(k==vert)
	{
		cnt=0;
		for(i=1;i<=k;i++)
		{
			if(a[i]==1)
			{
				cnt++;
			}
		}
		if(max<cnt)
		{
			max=cnt;
			cnt=0;
			for(i=1;i<=k;i++)
			{
				if(a[i]==1)
				{
					res[cnt++]=i;
				}
			}
		}

		return;
	}
	k++;
	Construct_can(k,a,c,&Ncan);
	for(i=0;i<Ncan;i++)
	{
		a[k]=c[i];
		Backtrack(k,a);
	}
}

void Graph_coloring()
{
	long a[CSE];

	color_num=2;
	max=0;
	a[0]=0;

	Backtrack(0,a);

	return;
}

int main()
{
	long tcase,i;

	scanf("%ld",&tcase);

	while(tcase--)
	{
		max=0;
		scanf("%ld%ld",&vert,&edge);

		Init();
		Take_input();

		Graph_coloring();

		printf("%ld\n",max);

		for(i=0;i<max;i++)
		{
			printf("%ld",res[i]);
			if(i!=max-1)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	
	return 0;
}