#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>

#include<queue>

#include<algorithm>
using namespace std;

#define PI (2*acos(0))
#define ERR 0.000001

#define Max(num1,num2) (num1>num2?num1:num2)
#define Min(num1,num2) (num1<num2?num1:num2)

#define CSE 1009
long dp[CSE],coin[CSE];

int main()
{	
	//freopen("t.in","r",stdin);
	//freopen("ttt.out","w",stdout);
	long tot,n,i,j;

	while( scanf("%ld %ld",&tot,&n)==2)
	{
		for(i=0;i<n;i++)
		{
			scanf("%ld",&coin[i]);
		}
		sort(&coin[0],&coin[n]);

		memset(dp,200000,sizeof(dp));
		

		dp[0]=0;

		for(i=1;i<=tot;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i>=coin[j])
				{
					dp[i]=Min(dp[i],dp[i-coin[j]]+1);
				}
				else
				{
					break;
				}
			}
		}

		printf("%ld\n",dp[tot]);
	}
	
	return 0;
}