/*
use of link list;
consecuitive delete 2,3,5,7,11,13'th number of circular array;
*/
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



#define INF 10009
#define ERR 1e-8

#define CSE 35009
#define PN 5000 

void PL()
{
	printf("\n");
}

int prime[PN],c,n;
bool f[CSE];

struct node
{
	int info;
	node *next;
};

node *my_List,*st;

void SV()
{
	int i,j,r;
	c=0;
	prime[c++]=2;
	for(i=3;i<CSE;i+=2)
	{
		if(!f[i])
		{
			prime[c++]=i;
			if(CSE/i >= i)
			{
				r=i*2;
				for(j=i*i;j<CSE;j+=r)
				{
					f[j]=1;
				}
			}
		}
	}

	/*printf("No of prime %d\n",c);
	for(i=0;i<10;i++)
	{
		printf("%d ",prime[i]);
	}
	PL();
	printf("Max2 %d %d\n",prime[c-2],prime[c-1]);*/
}

void Free()
{
}

void make_myList()
{
	int i;
	for(i=n;i>0;i--)
	{
		node *ptr;
		ptr=(node *)malloc(sizeof(node));
		
		ptr->next=my_List;
		ptr->info=i;
		my_List=ptr;

		if(i==n)
		{
			st=ptr;
		}
	}
	
	st->next=my_List;
}

void Res()
{
	int ln;
	int k,cnt,i;
	i=0;
	cnt=0;
	
	node *x;
	x=my_List;
	
	while(1)
	{
		if(!i)
		{
			ln=0;
		}
		else
		{
			ln=prime[i];
		}
		for(k=1;k<ln;k++)
		{
			x=x->next;
		}
		node *p;
		p=x->next;
		x->next = p->next;
		i++;
		cnt++;
		if(cnt == (n-1))
		{
			printf("%d\n",x->info);
			break;
		}
	}
}

int main()
{	
	//freopen("a.in","r",stdin);
	//freopen("aa.out","w",stdout);
	SV();

	while( scanf("%d",&n)==1 && n)
	{
		if(n<=3)
		{
			printf("1\n");
			continue;
		}
		make_myList();
		Res();
	}

	return 0;
}
