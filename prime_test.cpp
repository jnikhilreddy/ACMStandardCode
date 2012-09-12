#include<stdio.h>
#include<math.h>

#define CSE 1000
#define pn 200

bool flag[CSE];
long prime[CSE],c,N;

void seive()
{

	long i,j,r;
	c=0;
	prime[c++]=2;

	for(i=3;i<=CSE;i+=2)
	{
	     if(flag[i] == false)
		 {
			 prime[c++]=i;
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

	
	return ;
}

long Test_prime(long num)
{
     long root,i;

	 root=sqrt(num);

	 for(i=0;prime[i]<=root;i++)
	 {
	      if(num%prime[i] == 0)
		  {
		       return 0;
		  }
	 }

	 return 1;
}

int main()
{
	seive();
	long y;

	while(scanf("%ld",&N) == 1)
	{
	     y=Test_prime(N);
		 
		 if(y)
		 {
		      printf("%ld is a prime number.",N);
		 }
		 else
		 {
		      printf("Not prime.");
		 }

	     printf("\n");
	}
	return 0;
}