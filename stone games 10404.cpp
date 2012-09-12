#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>

#include<vector>
#include<queue>
#include<list>
#include<set>
#include<map>

#include<algorithm>
#include<iostream>
#include<sstream>
using namespace std;

#define VS vector<string>
#define VD vector<double>
#define VI vector<int>

#define MAX(aa_1,bb_1) (aa_1>bb_1?aa_1:bb_1)
#define MIN(aa_1,bb_1) (aa_1<bb_1?aa_1:bb_1)


#define PI (2*acos(0.0))

#define PB push_back
#define POB pop_back
#define INIT(V_1) memset(V_1,0,sizeof(V_1))
#define INITS(V_1) memset(V_1,'\0',sizeof(V_1)

#define INF 10009
#define ERR 1e-8

#define CSE 11

void PL()
{
	printf("\n");
}

int n,arr[CSE],mx;
int f[1000001];

int res()
{
	int i,j,k,d;
	for(i=0;i<=mx;i++)
	{
		f[i]=1;
	}
	f[0]=2;
	for(i=1;i<=mx;i++)
	{
		k=1;
		for(j=0;j<n;j++)
		{
			d=i-arr[j];
			if(d>=0)
			{
				if(f[d]==2)
				{
					k=2;
					break;
				}
				else if(f[d]==3)
				{
					k=3;
				}
			}
		}
		if(k==2)
		{
			f[i]=3;
		}
		else if(k==3)
		{
			f[i]=2;
		}
	}

	/*for(i=0;i<=mx;i++)
	{
		printf("%d ",f[i]);
	}
	PL();*/

	return f[mx];
}

int main()
{
	int i,rt;

	while( scanf("%d",&mx)==1 )
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		rt=res();
		if(rt==3)
		{
			printf("Stan wins\n");
		}
		else
		{
			printf("Ollie wins\n");
		}
	}

	return 0;
}