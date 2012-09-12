#include<stdio.h>

#define Size 1000000
#define prime1 999983
#define prime2 999979

typedef struct
{
	long long a;
	long i,flag;
}Hash;

Hash hash[Size];

long current,test;

bool hashing(long long p,long i)
{
	long h,h1,h2,j;
	h1=p%prime1;
	h2=1+p%prime2;
	for(j=0;;j=j+1)
	{
		h=(h1+j*h2)%prime1;
		if(hash[h].flag==test)
		{
			if(hash[h].a==p)
			{
				current=h;
				return 0;
			}
		}
		else
		{
			hash[h].flag=test;
			hash[h].a=p;
			hash[h].i=i;
			return 1;
		}
	}
	return 1;
}

int function(long long p,long long q)
{
	long i;
	p=p%q;
	i=0;
	while(hashing(p,i))
	{
		p=(((unsigned long long)p)<<1)%q;
		i++;
	}
	printf("Case #%ld: %ld,%ld\n",test,hash[current].i+1,i-hash[current].i);

	return 0 ;
}

int main()
{
	long long p,q;
	for(p=0;p<Size;p=p+1)
		hash[p].flag=0;
	while(2==scanf("%lld/%lld",&p,&q))
	{
		test++;
		function(p,q);
	}
	return 0;
}