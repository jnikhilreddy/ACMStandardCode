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

#define INF 10009
#define ERR 1e-8
#define CSE 109

void PL()
{
	printf("\n");
}

int main()
{	
	//freopen("a.in","r",stdin);
	//freopen("aa.out","w",stdout);
	
	string s,y;
	int i;

	s="jony CSE SUST";

	y=s.substr(0,4);
	cout<<"Y "<<y<<endl;
	y=s.substr(5,3);
	cout<<"Y1 "<<y<<endl;
	y=s.substr(9,4);
	cout<<"Y2 "<<y<<endl;
	i=s.find("CSE");
	cout<<"i  "<<i<<endl;
	i=s.find("CSE",5);
	cout<<"i  "<<i<<endl;
	i=s.find("CSE",6);
	cout<<"i  "<<i<<endl;
	
	return 0;
}