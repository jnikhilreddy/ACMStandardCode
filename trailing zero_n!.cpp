#include<stdio.h>

long zero(long number,long factor)
{
	long total,deno;

	if(number==5)return 1;
	total=0;
	deno = factor;

	while(deno<number)
	{
		total += number/deno;
		deno*=factor;
	
	}
	return total;
}

void main()
{
	long N,c2,c1;

	while(scanf("%ld",&N)==1)
	{
		c1 = zero(N,2);
		c2 = zero(N,5);
		if(c1<c2)printf("%ld\n",c1);
		else printf("%ld\n",c2);
	
	}


}