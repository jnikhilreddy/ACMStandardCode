#include<stdio.h>
#include<math.h>
#include<stdlib.h>

/*
Find LOGb(X)
b=base;
x=value;
LOGb(X)=LN(x)/LN(b);
*/

double LOG(double b,double x)
{
	double rt;
	rt=log(x)/log(b);
	return rt;
}

int main()
{
	double rt,b,x;

	while( scanf("%lf %lf",&b,&x)==2 )
	{
		rt=LOG(b,x);
		printf("Log of X in Base B: %lf\n",rt);
	}

	return 0;
}