//-----------Heapsort(data stracture)-----------------

#include<stdio.h>

#define CSE 15

long a[CSE],Item;

long Parent_of_ptr(long val)
{
	return val/2;
}

void Insert(long N,long item)
{
	long ptr,p;

	N=N+1;
	ptr=N;
	
	while(ptr>1)
	{
		p=Parent_of_ptr(ptr);
		//for min heap chane(<=,>=)
		if(item<=a[p])
		{
			a[ptr]=item;
			return;
		}
		a[ptr]=a[p];
		ptr=p;
	}

	a[ptr]=item;

	return;
}

void Del_heap(long N)
{
	long Last,ptr,Right,Left;
	
	Item=a[1];
	Last=a[N];
	ptr=1;
	Left=2;
	Right=3;

	while(Right<=N)
	{
		if(Last>=a[Left]  && Last>=a[Right])
		{
			a[ptr]=Last;
			return;
		}
		if(a[Right] <= a[Left])
		{
			a[ptr]=a[Left];
			ptr=Left;
		}
		else
		{
			a[ptr]=a[Right];
			ptr=Right;
		}
		Left=2*ptr;
		Right=Left+1;
	}

	if(Left == N  && Last<a[Left])
	{
		ptr=Left;
	}
	a[ptr]=Last;

	return;
}

int main()
{
	long N,item,i;

	while(scanf("%ld",&N)==1  && N)
	{
		for(i=1;i<=N;i++)
		{
			scanf("%ld",&item);
			Insert(i-1,item);
		}
		printf("The MAX :heap is:\n");

		for(i=1;i<=N;i++)
		{
			printf("%ld ",a[i]);
		}
		printf("\nSort the data using Heap sort:\n");
		i=N;
		while(N>=1)
		{
			Del_heap(N);
			//if we get descending order then b[cnt++]=item;
			a[N+1]=Item;
			N--;
		}
		N=i;
		for(i=2;i<=N+1;i++)
		{
			printf("%ld ",a[i]);
		}
		printf("\n");
	}

	return 0;
}


/*
INPUT:
8
44 30 50 22 60 55 77 55

6
6 5 4 3 2 1

OUTPUT:

77 55 60 50 30 44 55 22(heap1)
6 5 4 3 2 1(heap2)
sorted list.
*/
