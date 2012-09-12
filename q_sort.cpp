#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>

#include<algorithm>
using namespace std;

#define CSE 20

struct SSS 
{
	long number;
};

SSS inp[CSE];
/*
int qs(const void *a,const void *b)  {

  return (strcmp((char *)a,(char *)b));

}
*/

int SORT(void const *p,void const *q)
{
	SSS *x,*y;

	x=(SSS *)p;y=(SSS *)q;

	if(y->number > x->number)
	{
		return -1;
	}
	
	return 1;
}

int main()
{
	long i,n;

	while(scanf("%ld",&n)==1  && n)
	{
		for(i=0;i<n;i++)
		{
			scanf("%ld",&inp[i].number);
		}
		
		qsort(inp,n,sizeof(SSS),SORT);
		
		for(i=0;i<n;i++)
		{
			printf("%ld ",inp[i].number);
		}printf("\n");
	}

	return 0;
}
