#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>

#include<algorithm>
using namespace std;

long a[10][10];

int main()
{	
	//freopen("t.in","r",stdin);
	//freopen("ttt.out","w",stdout);

	long i,j,k=16;

	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			a[i][j]=k--;
		}
	}

	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%ld ",a[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");

	for(i=0;i<4;i++)
	{
		sort(&a[i][0],&a[i][4]);
	}

	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%ld ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
