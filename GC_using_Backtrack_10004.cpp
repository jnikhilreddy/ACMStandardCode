#include<stdio.h>
#include<string.h>

#define NMAX 202
#define MAXCAN 202

bool Finish=false;
bool Graph[NMAX][NMAX];

bool flag[NMAX];
int Node,Edge,Res;

void Construct(int k,int n,int *Ncan,int c[],int a[])
{
	int i;
	*Ncan=0;
	bool in_perm[NMAX];

	memset(in_perm,0,sizeof(in_perm));

	for(i=1;i<k;i++)
	{
		if(Graph[k][i])
		{
			in_perm[a[i]]=true;
		}
	}

	for(i=1;i<=4;i++)
	{
		if(in_perm[i]==false)
		{
			c[*Ncan]=i;
			*Ncan=*Ncan+1;
		}
	}
}

int Diff_a(int a[],int k)
{
	int cnt,i;
	cnt=0;
	memset(flag,0,sizeof(flag));
	for(i=1;i<=k;i++)
	{
		flag[a[i]]=true;
	}

	for(i=1;i<=4;i++)
	{
		if(flag[i])
		{
			cnt++;
		}
	}

    return cnt;
}

void Backtrack(int n,int k,int a[])
{
	int i,c[NMAX],Ncan,y;

	if(n==k)
	{
		y=Diff_a(a,k);

		if(y<Res)
		{
			Res=y;
		}
	}
	else
	{
		k++;
		Construct(k,n,&Ncan,c,a);

		for(i=0;i<Ncan;i++)
		{
			a[k]=c[i];
			Backtrack(n,k,a);
		}
		if(Finish)
		{
			return;
		}
	}
}
 
void Permut(int n)
{
	int a[NMAX];

	Backtrack(n,0,a);
}

int main()
{
	int t1,t2,i;

	while(scanf("%ld",&Node)==1  && Node)
	{
		scanf("%d",&Edge);
		memset(Graph,0,sizeof(Graph));
		Res=10000;
		for(i=1;i<=Edge;i++)
		{
			scanf("%d %d",&t1,&t2);

			Graph[t1 + 1][t2 + 1]=1;
			Graph[t2 + 1][t1 + 1]=1;
		}
		for(i=1;i<=Node;i++)
		{
			Graph[0][i]=1;
		}
		Permut(Node);
		if(Res>2)
		{
			printf("NOT BICOLORABLE.\n");
		}
		else
		{
			printf("BICOLORABLE.\n");
		}
	}
	return 0;
}