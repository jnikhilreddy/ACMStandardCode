#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#define CSE 10000

long a[CSE];

long len[CSE],par[CSE],Position;

char str[20],ch;

void init(long N)
{
	long i;

	for(i=0;i<=N;i++)
	{
		len[i]=1;
		par[i]=-1;
	}

	return;
}

long Find_max(long N)
{
	long i,m;

	m=0;
	Position=0;

	for(i=0;i<N;i++)
	{
		if(len[i]>m)
		{
			m=len[i];
			Position=i;
		}
	}
	return m;
}

long LIS(long n)
{
	long i,j,max;

		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(a[j]>a[i])
				{
					if(len[i]+1>len[j])
					{
						len[j]=len[i]+1;
						par[j]=i;
					}
				}	
			}
		}

		max=Find_max(n);

		return max;

}

void Print_path(long n)
{
	if(par[n]==-1)
	{
		printf("%ld\n",a[n]);
		return;
	}
	else
	{
		Print_path(par[n]);
		printf("%ld\n",a[n]);
	}
	return;
}

int main()
{
	//freopen("aaaa.out","w",stdout);
	long tcase,n,i,pik;
	
	scanf("%ld",&tcase);
	

	while(tcase--)
	{
		scanf("%ld",&n);
		init(n);
		i=0;
		
		while(i<n)
		{
			scanf("%ld",&a[i]);
			i++;
		}
		
		if(pik>1)
		{
			printf("\n");
		}
		pik=3;

		if(n==0)
		{
			printf("Max LIS: 0\n");
		}
		else
		{
			printf("Max LIS: %ld\n",LIS(n));
			Print_path(Position);
		}
	
	}
	return 0;
}