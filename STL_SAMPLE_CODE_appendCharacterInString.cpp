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
#include<string>

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


int main()
{	
	//freopen("a.in","r",stdin);
	//freopen("aa.out","w",stdout);
	string s="";
	for(int i=0;i<10;i++){
		s.append(1,'a'+i);
	}
	cout<<s<<endl;


	return 0;
}