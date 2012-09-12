#include<stdio.h>
#include<stdlib.h>

#define max 100

long par[max],temp[max],ind[max],n,data[max],l;

int comp(const void *a,const void *b)
{
	long *x=(long *)a;
	long *y=(long *)b;
	if(*x<*y&&(y-temp==0||*x>*(y-1))) //to find LDS just change the <,> signs
		return 0;
	if(*x>*y)
		return 1;
	if(*x<*y)
		return -1;
	return 0;
}

long lis()
{
	long i,*p,num,index;
	temp[0]=data[0];
	ind[0]=0;
	par[0]=-1;
	num=1;
	//k=-1;
	l=0;
	for(i=1;i<n;i++)
	{
		p=(long*)bsearch(&data[i],temp,num,sizeof(long),comp);
		if(p)
			index=p-temp;
		else
		{
			index=num;
			l=i;
			num++;
		}
		temp[index]=data[i];
		ind[index]=i;
		if(index==0)
			par[i]=-1;
		else
			par[i]=ind[index-1];
	}
	return num;
}

void print(long i)
{
	if(par[i]==-1)
	{
		printf("%ld\n",data[i]);
		return;
	}
	print(par[i]);
	printf("%ld\n",data[i]);
}

int  main()
{
	long i,t;
	scanf("%ld ",&t);
	while(t--)
	{
		scanf("%ld",&n);
		
		for(i=0;i<n;i++)
		{
			scanf("%ld",&data[i]);
		}
		
		i=lis();
		printf("LCS Seq. len %ld\n",i);
		print(l);
	}

	return 0;
}

