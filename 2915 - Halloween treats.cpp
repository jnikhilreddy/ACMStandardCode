#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>

#include<algorithm>
using namespace std;

#define CSE 109
long inp[CSE],f[CSE];

void Init(long c)
{
	long i;

	for(i=0;i<c;i++)
	{
		f[i]=-1;
	}
	return;
}

int main()
{	
	//freopen("t.in","r",stdin);
	//freopen("ttt.out","w",stdout);
	long j,c,n,i,s,ts,pp;

	while(scanf("%ld %ld",&c,&n)==2)
	{
		if(c==0 && n==0)
		{
			break;
		}

		pp=1;

		Init(c);

		for(i=0;i<n;i++)
		{
			scanf("%ld",&inp[i]);
		}

		f[0]=0;
		s=0;
		
		for(i=0;i<n;i++)
		{
			s=(s+inp[i])%c;
			if(f[s]>=0)
			{
				ts=0;
				for(j=f[s];j<=i;j++)
				{
					pp=0;
					//ts=(ts+inp[j])%c;
					printf("%ld",j+1);
					if(j<i)
					{
						printf(" ");
					}
				}
				if(!pp)
				{
					break;
				}
			}
			f[s]=i+1;
		}
		if(pp)
		{
			printf("no sweets");
		}
		printf("\n");
	}
	
	return 0;
}
