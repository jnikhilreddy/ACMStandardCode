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

#define MAX(aa,bb) (aa>bb?aa:bb)
#define MIN(aa,bb) (aa<bb?aa:bb)


#define PI (2*acos(0.0))

#define PB push_back
#define POB pop_back
#define INIT(V_1) memset(V_1,0,sizeof(V_1))
#define INITS(V_1) memset(V_1,'\0',sizeof(V_1)

#define INF 1e6
#define ERR 1e-8

#define CSE 1009

void PL()
{
	printf("\n");
}

char  s[CSE];
int dp[CSE][CSE];

int rec(int i,int j)
{
	if(i>=j)
	{
		return 0;
	}
	if(dp[i][j]>-1)
	{
		return dp[i][j];
	}
	int ret;
	if(s[i]==s[j])
	{
		dp[i][j]=rec(i+1,j-1);
	}
	else
	{
		ret=rec(i,j-1)+1;
		dp[i][j]=ret;
		ret=rec(i+1,j)+1;
		dp[i][j]=MIN(dp[i][j],ret);
		ret=rec(i+1,j-1)+1;
		dp[i][j]=MIN(dp[i][j],ret);
	}
	return dp[i][j]; 
}

int main()
{
	int t,cs=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf(" %s",s);
		memset(dp,-1,sizeof(dp));
		int y=rec(0,strlen(s)-1);
		printf("Case %d: %d\n",cs++,y);
	}

	return 0;
}