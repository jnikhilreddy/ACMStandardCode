#include<stdio.h>
#include<math.h>
#define sz 30000100

bool flag[sz];
long prime[1857870];

void seive()
{
	long i, j, r, c=0;

	for(i=2;i<sz;i+=2) flag[i]=true;

	prime[c++] = 2;

	for(i=3;i<sz;i+=2)
	{
		if(flag[i]==false)
		{
			prime[c++] = i;

			if(sz/i>=i)
			{
				r = i<<1;

				for(j=i*i;j<sz;j+=r)
					flag[j]=true;
			}
		}
	}
}

int main(void)
{
	seive();

	long long n, temp, count, i, root ;

	while(scanf("%lld",&n)==1)
	{
		if(n==0||n==1)
		{
			printf("1\n");
			continue;
		}

		else if(n<=30000000 && flag[n]==false)
		{
			printf("2\n");
			continue;
		}
		
		count = 1 ;

		root = sqrt(n);

		for(i=0;prime[i]<=root;i++)
		{
			temp = 1;
			
			for(;n%prime[i]==0;)
			{
				n/=prime[i];
				temp++;
			}
			
			if(temp>1 && prime[i]>2 ) count*=temp;
			root = sqrt(n);
		}
		if(n>1 && n!=2) count*=2;

		printf("%lld\n",count);
	}
	return 0;
}


