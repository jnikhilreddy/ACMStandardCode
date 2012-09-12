#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>

#include<vector>
#include<queue>
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
#define RP(ii,nn) for(ii=0;ii<nn;ii++)
#define CLR(aa,vv) memset((aa),(vv),sizeof(aa))

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

typedef pair<int,int> pr;
map<pr,int> mp;

int main()
{ 
 //freopen("t.in","r",stdin);
 //freopen("ttt.out","w",stdout);

 int u,v;
 pr r;
 mp.clear();
 while(scanf("%d %d",&u,&v)==2)
 {
  r=make_pair(u,v);
  if(mp[r]==0)
  {
  mp[r]=1;
  }
  else
  {
  printf("Repeate\n");
  }
 }
 
 return 0;
}