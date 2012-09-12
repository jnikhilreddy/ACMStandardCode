#include<stdio.h>
#include<math.h>

#define CSE 100000
#define pn 2000
#define SN 1000

bool flag[CSE];
long prime[CSE],c,N;

struct jony
{
     long fact;
	 long freq;
};

jony a[SN];

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

long prime_factor(long num)
{
	long t_cnt,cnt=0,i,root;

	root=sqrt(num);

	for(i=0;prime[i]<=root;i++)
	{
	     if(num%prime[i] == 0)
		 {
		       t_cnt=0;
			   while(num%prime[i] == 0)
			   {
			        t_cnt++;
					num/=prime[i];
			   }
			   a[cnt].fact=prime[i];
			   a[cnt++].freq=t_cnt;
		 }
	}
	if(num>1)
	{
		a[cnt].fact=num;
		a[cnt++].freq=1;
	}

	return cnt;

}

int main()
{
	seive();
	long i,y;

	while(scanf("%ld",&N) == 1)
	{
	    y=prime_factor(N);

		for(i=0;i<y;i++)
		{
		      printf("%ld^%ld ",a[i].fact,a[i].freq);
		}
		printf("\n");
	}
	return 0;
}