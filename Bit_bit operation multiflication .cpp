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
#define CSE 109

void PL()
{
	printf("\n");
}

void Free()
{
}

int product(int a,int b) 
{
	if(a<0 && b<0)
	{
		a=a*(-1);
		b=b*(-1);
	}
	int c;
	if(a>b)
	{
		c=a;
		a=b;
		b=c;
	}

	c= 0;
	while (b > 0)
	{
		if (b & 1)
		{
			c = c + a;
		}
		a<<=1;
		b>>=1;
	}
	return c;
}


int main()
{	
	//freopen("a.in","r",stdin);
	//freopen("aa.out","w",stdout);
	int y;

	y=product(2,3);
	cout<<"Product 2,3 is "<<y<<endl;

	y=product(5,3);
	cout<<"Product 5,3 is "<<y<<endl;

	y=product(-5,3);
	cout<<"Product -5,3 is "<<y<<endl;

	y=product(12,-6);
	cout<<"Product 12,-6 is "<<y<<endl;

	y=product(-5,-3);
	cout<<"Product -5,-3 is "<<y<<endl;

	y=product(12,0);
	cout<<"Product 12,0 is "<<y<<endl;
	y=product(0,0);
	cout<<"Product 0,0 is "<<y<<endl;
	y=product(5,5);
	cout<<"Product 5,5 is "<<y<<endl;

	int n,tn;
	n=3;
	//n=11;
	tn=n<<2;
	cout<<"N1 "<<tn<<endl;
	//tn=1100;

	tn=n<<3;
	cout<<"N2 "<<tn<<endl;
	//tn=11000;
	
	tn=n<<4;
	cout<<"N1 "<<tn<<endl;
	//tn=110000;

	n=17;
	//n=10001;
	tn=n>>2;
	cout<<"n1 "<<tn<<endl;
	//tn=1000
	
	tn=n>>3;
	cout<<"n2 "<<tn<<endl;
	//tn=1;

	tn=n>>4;
	cout<<"n3 "<<tn<<endl;
	//tn=0;


	return 0;
}