#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>

#include<queue>
#include<map>

#include<algorithm>
using namespace std;
#define INF (1<<30)

#define PI (2*acos(0))
#define ERR 0.000001

#define Min(num1,num2) (num1<num2?num1:num2)
#define Max(num1,num2) (num1>num2?num1:num2)

#define CSE 109
map<long,long> mp;


int main()
{	
	//freopen("t.in","r",stdin);
	//freopen("ttt.out","w",stdout);

	long n,T=3;


	while(T--)
	{

		while(scanf("%ld",&n)==1  && n)
		{
			if(mp[n]==1)
			{
				printf("%ld is occured before\n",n);
			}
			else
			{
				mp[n]=1;
				printf("%ld is Unique\n",n);
			}
		}
		mp.clear();
	}
	
	return 0;
}
