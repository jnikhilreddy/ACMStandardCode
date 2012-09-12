#include<stdio.h>

int arr[109],x[109];
int n,tot;

void Rec(int i,int k)
{
	int j;
	for(j=0;j<k;j++)
	{
		printf("%d ",x[j]);
	}
	if(k)
	{
		tot++;
		printf("\n");
	}

	for(;i<n;i++)
	{
		x[k]=arr[i];
		Rec(i+1,k+1);
	}
}

int main()
{
	int i;
	while( scanf("%d",&n)==1 && n)
	{
		tot=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		Rec(0,0);
		printf("Total  %d\n",tot);
	}

	return 0;
}