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
#define INF 10009
#define ERR 1e-8

#define CSE 65009


struct SSS
{
	VI Edge;
};
SSS arr[CSE];
int k[CSE],q[CSE],inp[CSE],temp[CSE],l;

void Init(int nn)
{
	int i,j;
	nn=nn*nn+2;
	RP(i,nn)
	{
		j=arr[i].Edge.size();
		while(j--)
		{
			arr[i].Edge.pop_back();
		}
	}
}

int comp(const void *a,const void *b)
{
	int *x=(int *)a;
	int *y=(int *)b;
	if(*x<*y&&(y-temp==0||*x>*(y-1)))
		return 0;
	if(*x>*y)
		return 1;
	if(*x<*y)
		return -1;
	return 0;
}

int lis(int n)
{
	int i,*p,num,Index;
	temp[0]=inp[0];
	num=1;
	//k=-1;
	l=0;
	for(i=1;i<n;i++)
	{
		p=(int*)bsearch(&inp[i],temp,num,sizeof(int),comp);
		if(p)
			Index=p-temp;
		else
		{
			Index=num;
			l=i;
			num++;
		}
		temp[Index]=inp[i];
	}
	return num;
}

int main()
{	
	//freopen("t.in","r",stdin);
	//freopen("ttt.out","w",stdout);

	
	int j,t,i,n,m,N,c,cs=1,kk;

	cin>>t;

	while(t--)
	{
		c=0;
		cin>>N>>n>>m;
		Init(N);
		n++;
		for(i=0;i<n;i++)
		{
			cin>>k[i];
		}
		m++;
		for(i=0;i<m;i++)
		{
			cin>>q[i];
			arr[q[i]].Edge.push_back(i+1);
		}



		/*for(i=0;i<N*N;i++)
		{
			cout<<"i "<<i<<" SizE  "<<arr[i].Edge.size()<<" ";
			j=0;
			for(j=0;j<arr[i].Edge.size();j++)
			{
				cout<<arr[i].Edge[j]<<" ";
			}
			cout<<endl;
		}*/

		c=0;
		for(i=0;i<n;i++)
		{
			for(j=arr[k[i]].Edge.size()-1;j>=0;j--)
			{
				inp[c++]=arr[k[i]].Edge[j];	
				kk=inp[c-1];
			}
		}

		/*cout<<" Temp "<<endl;
		for(i=0;i<c;i++)
		{
			cout<<inp[i]<<" ";
		}
		cout<<endl;*/
		

		//cout<<l<<endl;

		j=lis(c);
		printf("Case %d: %d\n",cs++,j);
	}
	
	return 0;
}
