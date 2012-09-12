#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define CSE 1005

long N,MW,C[CSE][CSE],Vi[CSE],Wi[CSE];

long max(long num1 ,long num2)
{
	if(num1>num2)
	{
		return num1;
	}

	return num2;
}

long Knapsack()
{
	long i,w;

	for (i=0;i<=N ;i++) 
	{
		C[i][0] = 0;
	}
	for (w=0;w<=MW;w++) 
	{
		C[0][w] = 0;
	}
	for (i=1;i<=N;i++)
	{
		for (w=0;w<=MW;w++) 
		{
			if (Wi[i] > w)
			{
				C[i][w] = C[i-1][w];
			}
			else
			{
				C[i][w] = max(C[i-1][w] , C[i-1][w-Wi[i]]+Vi[i]);
			}
		}
	}
	return C[N][MW];
}
int main()
{
	long sum,MW_num,i,y,tcase;

	scanf("%ld",&tcase);

	while(tcase--)
	{
		scanf("%ld",&N);
		for(i=1;i<=N;i++)
		{
			scanf("%ld%ld",&Vi[i],&Wi[i]);	
		}
		sum=0;
		scanf("%ld",&MW_num);
		while(MW_num--)
		{
			scanf("%ld",&MW);
			y=Knapsack();
			sum+=y;
		}
		printf("%ld\n",sum);
	}

	return 0;
}