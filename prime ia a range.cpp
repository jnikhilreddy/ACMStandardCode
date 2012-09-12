#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>

#include<algorithm>
using namespace std;

#define PI (2*acos(0))
#define ERR 0.000001

#define CSE 109

long prime[CSE],c;

void sieve(int L , int U) 
{
	c=0;
	int i,j,d;

	d=U-L+1; /* from range L to U, we have d=U-L+1 numbers. */
	/* use flag[i] to mark whether (L+i) is a prime number or not. */
	bool *flag = new bool[d];
	for (i=0;i<d;i++) flag[i]=true; /* default: mark all to be true */
	for (i=(L%2!=0);i<d;i+=2) flag[i]=false; /* mark even numbers as false */

	/* sieve by prime factors staring from 3 till sqrt(U) */
	for (i=3;i<=sqrt(U);i+=2) 
	{
		if (i>L && !flag[i-L]) continue;
		/* choose the first number to be sieved -- >=L,
		divisible by i, and not i itself! */
		j=L/i*i;
		if (j<L) j+=i;
		if (j==i) j+=i; /* if j is a prime number, have to start form next one */

		/* now start sieving */
		j-=L; /* change j to the index representing j */
		for (;j<d;j+=i) flag[j]=false;
	}

	/* mark 1 as false, 2 as true */
	if (L<=1) flag[1-L]=false;
	if (L<=2) flag[2-L]=true;

	/* output the result */
	for (i=0;i<d;i++)
		if (flag[i])
			prime[c++] = (L+i);
}

int main()
{	

	//freopen("t.in","r",stdin);
	//freopen("ttt.out","w",stdout);
	long a,b,i;

	while(scanf("%ld %ld",&a,&b)==2)
	{
		sieve(a,b);
		for(i=0;i<c;i++)
		{
			printf("%ld ",prime[i]);
		}
		printf("\n");
	}
	return 0;
}
