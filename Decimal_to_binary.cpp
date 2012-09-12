#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>

#include<algorithm>
using namespace std;

#define CSE 20

int a[CSE];

void Reverse(int n)
{
	int i,j,t;

	for(i=0,j=n-1;j>=i;i++,j--)
	{
		t=a[i];
		a[i]=a[j];
		a[j]=t;
	}
}

int To_binary(int n)
{
	int m,d,cnt;

	cnt=0;

	while(n>0)
	{
		m=n%2;
		d=n/2;
		n=d;
		a[cnt++]=m;
	}

	

	return cnt;
}

int main()
{
	long i,n,y;

	while(scanf("%ld",&n)==1 && n)
	{
		
		y=To_binary(n);
		Reverse(y);
		printf("The binary of %d is: ",n);
		for(i=0;i<y;i++)
		{
			printf("%d",a[i]);
		}
		printf("\n");
		
	}
	
	return 0;
}
