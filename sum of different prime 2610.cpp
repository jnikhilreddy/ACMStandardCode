#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>

#include<vector>
#include <stack>
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
#define VI vector<__int64>

#define MAX(aa_1,bb_1) (aa_1>bb_1?aa_1:bb_1)
#define MIN(aa_1,bb_1) (aa_1<bb_1?aa_1:bb_1)


#define PI (2*acos(0.0))

#define PB push_back
#define POB pop_back
#define INIT(V_1) memset(V_1,0,sizeof(V_1))
#define INITS(V_1) memset(V_1,'\0',sizeof(V_1)

#define INF 10009
#define ERR 1e-8

void PL()
{
	printf("\n");
}

#define CSE 1122
#define pn 1200

bool flag[CSE];
long prime[CSE],cc,N;

int dp[200][CSE][15];

void SV()
{

	long i,j,r,k;
	cc=0;
	prime[cc++]=2;

	for(i=3;i<CSE;i+=2)
	{
	     if(flag[i] == false)
		 {
			 prime[cc++]=i;
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
	/*printf("Size %d\n",cc);
	printf("%d %d\n",prime[cc-2],prime[cc-1]);
	for(i=0;i<10;i++)
	{
		printf("%d ",prime[i]);
	}
	PL();*/


	memset(dp,0,sizeof(dp));
	for(i=0;i<cc;i++)
	{
		dp[i][prime[i]][1]=1;
	}
	for(i=1;i<cc;i++)
	{
		for(j=0;j<CSE;j++)
		{
			for(k=1;k<=14;k++)
			{
				dp[i][j][k]+=dp[i-1][j][k];
				if((j-prime[i])>=0)
				{
					dp[i][j][k]+=dp[i-1][j-prime[i]][k-1];
				}
			}
		}
	}
	
}

int main()
{
	SV();
	//freopen("a.in","r",stdin);
	//freopen("aa.out","w",stdout);
	int k,n;
	
	
	while( scanf("%d %d",&n,&k)==2 )
	{
		if(n==0  && k==0)
		{
			break;
		}
		printf("%d\n",dp[cc-1][n][k]);
	}

	return 0;
}