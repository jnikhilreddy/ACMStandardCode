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

struct SSS
{
	int x,y,val,hints;
};

char  s[CSE],A[CSE],B[CSE];
SSS dp[CSE][CSE];
int len,head,tail;

int rec(int i,int j)
{
	if(i>=j)
	{
		return 0;
	}
	if(dp[i][j].val>-1)
	{
		return dp[i][j].val;
	}
	int ret;
	if(s[i]==s[j])
	{
		dp[i][j].val=rec(i+1,j-1);
		dp[i][j].hints=1;
		dp[i][j].x=i+1;
		dp[i][j].y=j-1;
	}
	else
	{
		ret=rec(i,j-1)+1;

		dp[i][j].val=ret;
		dp[i][j].hints=2;
		dp[i][j].x=i;
		dp[i][j].y=j-1;
		
		ret=rec(i+1,j)+1;
		if(dp[i][j].val>ret)
		{
			dp[i][j].val=ret;
			dp[i][j].hints=3;
			dp[i][j].x=i+1;
			dp[i][j].y=j;	
		}
	}
	return dp[i][j].val; 
}

void init()
{
	int i,j;
	for(i=0;i<=len;i++)
	{
		for(j=0;j<=len;j++)
		{
			dp[i][j].val=-1;
		}
	}
	return;
}

int Find_res(int r, int c) 
{
	if(r == c) 
	{
		A[head++] = s[r];
		return 1;
	}
	if(dp[r][c].hints == 2) 
	{
		A[head++] = s[c];
		B[tail++] = s[c];
	}
	else if(dp[r][c].hints == 3) 
	{
		A[head++] = s[r];
		B[tail++] = s[r];
	}
	else if(dp[r][c].hints == 1 ) 
	{
		A[head++] = s[r];
		B[tail++] = s[r];
		if(c == r+1) 
		{
			return 1;
		}
	}
	if(Find_res(dp[r][c].x,dp[r][c].y)) 
	{
		return 1;
	}

	return 0;
}

void print_res()
{
	int i;
	for(i=0;i<head;i++)
	{
		printf("%c",A[i]);
	}
	for(i=tail-1;i>=0;i--)
	{
		printf("%c",B[i]);
	}
	printf("\n");
}

int main()
{
	int rt;
	while(scanf(" %s",s)==1)
	{
		head=tail=0;
		len=strlen(s);
		init();
		int y=rec(0,len-1);
		rt=Find_res(0,len-1);
		
		printf("%d ",y);
		print_res();
	}

	return 0;
}