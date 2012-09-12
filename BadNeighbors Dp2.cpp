#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

#include <iostream>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <utility>

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cassert>
#include <complex>


using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;

class BadNeighbors 
{
	int max(int a,int b)
	{
		if(a>b)
		{
			return a;
		}
		
		return b;
	}
public:
	int BadNeighbors::maxDonations(vector <int> donations) 
	{
		int n,sz,dp[51],ma;
		sz=donations.size();
		dp[0]=donations[0];
		dp[1]=donations[0];

		for(n=2;n<sz-1;n++)
		{
			dp[n]=max(donations[n]+dp[n-2],dp[n-1]);
		}
		ma=dp[sz-2];

		dp[0]=0;
		dp[1]=donations[1];
		for(n=2;n<sz;n++)
		{
			dp[n]=max(donations[n]+dp[n-2],dp[n-1]);
		}
		return max(ma,dp[sz-1]);
	
		return 0;
	}
};

int main()
{
	BadNeighbors r;
	int t,n,i;
	VI a;

	scanf("%ld",&n);

	for(i=0;i<n;i++)
	{
		cin>>t;
		a.push_back(t);
	}

	t=r.maxDonations(a);
	printf("Result  %ld\n",t);
	
	return 0;
}

/*
6
10  3  2  5  7 8 
*/