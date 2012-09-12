#include<stdio.h>

#define SIZE 100
#define INFINITY 2147483647

long m[SIZE][SIZE],s[SIZE][SIZE],p[SIZE];

void MCM(long n)
{
	long i,j,k,l,q,ptr=0;
	for(i=1;i<=n;i++)
		m[i][i]=0;
	for(l=2;l<=n;l++)
	{
		for(i=1;i<=n-l+1;i++)
		{
			j=i+l-1;
			m[i][j]=INFINITY;
			for(k=i;k<j;k++)
			{
				if(m[i][k]!=INFINITY&&m[k+1][j]!=INFINITY)
				{
					ptr=1;
					q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				}
				else
				{
					ptr=2;
					q=INFINITY;
				}
				if(q<m[i][j])
				{
					ptr=3;
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
}

void print_path(long i,long j)
{
	if(i==j)
		printf("A%ld",i);
	else
	{
		printf("(");
		print_path(i,s[i][j]);
		print_path(s[i][j]+1,j);
		printf(")");
	}
}

void main()
{
	//freopen("input.txt","r",stdin);
	long n,i,r,c;

	while(1==scanf("%ld",&n)&&n)
	{
		scanf("%ld %ld",&r,&c);
		p[0]=r;
		p[1]=c;
		for(i=2;i<=n;i++)
		{
			scanf("%ld %ld",&r,&c);
			p[i]=c;
		}
		MCM(n);
		print_path(1,n);
		printf("\n");
	}
}