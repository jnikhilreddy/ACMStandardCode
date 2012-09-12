#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define CSE 509
int prime[CSE],cc;
bool f[CSE];
void PP()
	{
		int i,j,r;
		cc=0;
		prime[cc++]=2;
		for(i=3;i<CSE;i+=2)
		{
			if(!f[i])
			{
				prime[cc++]=i;
				if(CSE/i >= i)
				{
					r=i*2;
					for(j=i*i;j<CSE;j+=r)
					{
						f[i]=1;
					}
				}
			}
		}	
	} 


class Underprimes {
public:
	Underprimes()
	{
		PP();
	}
	bool is_prime(int num)
	{
		int i,rt;
		rt=(int)sqrt(num);
		if(num<2)
		{
			return 0;
		}
		for(i=0;prime[i]<=rt;i++)
		{
			if(num%prime[i] == 0)
			{
				return 0;
			}
		}
		return 1;
	}
	
	int COUNT(int num)
	{
		int r=0,rt,i;
		rt=(int)sqrt(num);
		for(i=0;prime[i] <= rt;i++)
		{
			if(num % prime[i]==0)
			{
				while(num % prime[i]==0)
				{
					num=num/prime[i];
					r++;
				}
			}
		}
		if(num>1)
		{
			r++;
		}
		return r;
	}
	int howMany(int A, int B) {
		int rt,i;
		rt=0;
		for(i=A;i<=B;i++)
		{
			if(is_prime(COUNT(i)))
			{
				rt++;
			}
		}
		return rt;
	}

};