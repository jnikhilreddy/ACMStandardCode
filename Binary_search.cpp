#include<stdio.h>

#define CSE 19

int a[CSE];

int B_search(int data,int n)
{
	int Beg,Mid,End;

	Beg=1;
	End=n;
	Mid=(Beg+End)/2;

	while(Beg<=End  && a[Mid]!=data)
	{
		if(a[Mid]>data)
		{
			End=Mid-1;
		}
		else
		{
			Beg=Mid+1;
		}
		Mid=(Beg+End)/2;
	}

	if(a[Mid]==data)
	{
		return Mid;
	}

	return 0;
}

int main()
{
	int i,y,data,n;

	while(scanf("%d",&n)==1  && n)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}

		while(scanf("%d",&data)==1   && data)
		{
			y=B_search(data,n);
			if(y)
			{
				printf("Loc of data  is %d\n",y);
			}
			else
			{
				printf("Not found\n");
			}
		}
	}

	return 0;
}

/*

11
3 5 9 10 12 15 63 98 99 456 756


*/