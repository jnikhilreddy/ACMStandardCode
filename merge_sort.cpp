#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define CSE 200

long Temp[CSE],arr[CSE];
long cnt;

void Merging_array(long Beg1,long End1,long Beg2,long End2)
{
	long k,i,j;
	
	k=0;

	for(i=Beg1,j=Beg2;i<=End1 && j<=End2;)
	{
		if(arr[i]<=arr[j])
		{
			Temp[k++]=arr[i];
			i++;
		}
		else
		{
			cnt+=(End1 + 1-i);
			Temp[k++]=arr[j];
			j++;
		}
	}
	while(i<=End1)
	{
		Temp[k++]=arr[i++];
	}
	while(j<=End2)
	{
		Temp[k++]=arr[j++];
	}
	for(i=0,j=Beg1;i<k;i++,j++)
	{
		arr[j]=Temp[i];
	}
	return;
}

void Merge_sort(long Beg,long End)
{
	long Mid;
	if(Beg == End)
	{
		return;
	}
	Mid=(long)(Beg+End)/2;
	Merge_sort(Beg,Mid);
	Merge_sort(Mid+1,End);
	Merging_array(Beg,Mid,Mid+1,End);

	return;
}


void Merge_sort1(int Beg, int End)
{
	int Middle;
	
	if (Beg == End) return;

	Middle = (Beg + End) / 2;
	Merge_sort1(Beg, Middle);
	Merge_sort1(Middle + 1, End);
	Merging_array(Beg, Middle, Middle + 1, End);
	
	return;
}

int main()
{
	long N,i;

	while(scanf("%ld",&N)==1 && N)
	{
		cnt=0;

		for(i=0;i<N;i++)
		{
			scanf("%ld",&arr[i]);
		}
		Merge_sort(0,N-1);
		printf("%ld\n",cnt);
	}

	return 0;
}