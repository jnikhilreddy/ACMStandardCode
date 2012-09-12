#include<stdio.h>
#include<math.h>

#define CSE 1122
#define pn 1200

bool flag[CSE];
long prime[CSE],cc,N;

void SV()
{

	long i,j,r;
	cc=0;
	prime[cc++]=2;

	for(i=3;i<CSE;i+=2)
	{
	     if(flag[i] == false)
		 {
			 prime[cc++]=i;
			 if(CSE/i>=i)
			 {
			      r=i*2;
				  for(j=i*i;j<CSE;j+=r)
				  {
				        flag[j]=true;
				  }
			 }
		 }
	}
	printf("Size %d\n",cc);
	printf("%d %d\n",prime[cc-2],prime[cc-1]);
	for(i=0;i<10;i++)
	{
		printf("%d ",prime[i]);
	}
	printf("\n");
	return ;
}

int main()
{
	seive();
	long i;

	while(scanf("%ld",&N) == 1)
	{
	     printf("No of prime : %ld\n",c);

	     for(i=0;i<N;i++)
	     {
	          printf("%ld ",prime[i]);
	     }
	     printf("\n");
	}
	return 0;
}