#include<stdio.h>
#define max_amount 7500
#define coin_num 5
long coin[]={1,5,10,25,50};
long long ways[max_amount];
void generate()
{
    long i,j,temp;
	ways[0]=1;
	for(i=1;i<max_amount;i++)
	{
	   ways[i]=0;
	}
	for(i=0;i<coin_num;i++)
	{
	   temp=coin[i];
	   for(j=temp;j<max_amount;j++)
	   {
	        ways[j]+=ways[j-temp];
	   }
	}
} 
void main()
{
    generate();
	long n;
	while(scanf("%ld",&n)==1)
	{
		printf("%lld\n",ways[n]);
	}
}