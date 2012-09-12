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


int n;
int v[1025][1025];

void Add(int idx, int idy, int S) 
{
	idx++;idy++;
	int y2 = idy;
	while (idx <= n) 
	{
		idy = y2;
		while ( idy <= n ) 
		{
			v[idx][idy] += S;
			idy +=(idy & -idy);
		}
		idx += (idx & -idx);
	}
}

int querry(int idx, int idy) 
{
	idx++;idy++;
	int y2 = idy;
	int ret = 0;
	while (idx > 0) 
	{
		idy = y2;
		while ( idy > 0 ) 
		{
			ret += v[idx][idy];
			idy -= (idy & -idy);
		}
		idx -= (idx & -idx);
	}
	return ret;
}
int main() 
{

	printf("Enter Dimention: ");
	scanf("%d",&n);
	printf("For update type 1 && sum type 2 && 3 for terminate:\n");

	while (1) 
	{
		int command;
		scanf("%d", &command);
		if ( command == 3 ) return 0;
		if ( command == 1 ) 
		{ 
			int x, y, a; scanf("%d %d %d", &x, &y, &a);
			Add(x, y, a);
		}
		if ( command == 2 ) 
		{
			int l, b, r, t; scanf("%d %d %d %d", &l, &b, &r, &t);
			int total = 0;
			total = querry(r, t) - querry(l-1, t) - querry(r, b-1) + querry(l-1 ,b-1);
			printf("Res  %d\n", total);
		}
	}
	return 0;
}
/*
5
1
2 3 1
2
1 1 2 2
2
1 1 2 3
2
2 3 2 3

*/