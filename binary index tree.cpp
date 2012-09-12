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
#define INIT(V_1) memset(V_1,0,sizeof(V_1))
#define INITS(V_1) memset(V_1,'\0',sizeof(V_1)

#define INF 10009
#define ERR 1e-8
#define CSE 109

void PL()
{
	printf("\n");
}

int tree[CSE],f[CSE],c[CSE];
int bn[CSE],n;
int b_len;
int  MaxVal;

int tobin(int num)
{
	int i,j,tmp,cc;
	b_len=0;
	while(num>0)
	{
		bn[b_len++]=num%2;
		num=num/2;
	}
	for(i=0,j=b_len-1;i<j;i++,j--)
	{
		tmp=bn[i];
		bn[i]=bn[j];
		bn[j]=tmp;
	}
	cc=0;
	for(i=b_len-1;i>=0;i--)
	{
		if(bn[i]==1)
		{
			break;
		}
		cc++;
	}

	return cc;
}


int Find_Nonzero(int n)
{
	int r = 0;

	while(n>0)
	{
		if(n%2)
		{
			return r;
		}
		n/=2;
		r++;
	}
}

void build_tree()
{
	int i,tmp,y;
	for(i=1;i<=n;i++)
	{
		y=Find_Nonzero(i);
		tmp=i+1-(int)pow(2,y);
		if(tmp==i)
		{
			tree[i]=f[i];
		}
		else
		{
			tree[i]=c[i]-c[tmp-1];
		}
	}

	/*printf("Tree :\n");
	for(i=1;i<=n;i++)
	{
		printf("%d ",tree[i]);
	}
	PL();*/
}

void update(int idx ,int val){
	while (idx <= MaxVal)
	{					
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

int c_sum(int idx)
{
	/*
	Find c sum from 1 to idx; 
	*/
	int sum = 0;
	while (idx > 0){
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}
void Print()
{
	int i;
	printf("Tree:\n");
	for(i=1;i<=n;i++)
	{
		printf("%d ",c[i]);
	}
	PL();
}

void Scale(int cc){
	for (int i = 1 ; i <= MaxVal ; i++)
		tree[i] = tree[i] * cc;
}


// if in tree exists more than one index with a same
// cumulative frequency, this procedure will return 
// some of them (we do not know which one)

// bitMask - initialy, it is the greatest bit of MaxVal
// bitMask store interval which should be searched;

//Find index with given cumulative frequency;

int find(int cumFre)
{
	int idx = 0,bitMask; // this var is result of function
	
	while ((bitMask != 0) && (idx < MaxVal)){ // nobody likes overflow :)
		int tIdx = idx + bitMask; // we make midpoint of interval
		if (cumFre == tree[tIdx]) // if it is equal, we just return idx
			return tIdx;
		else if (cumFre > tree[tIdx]){ 
		        // if tree frequency "can fit" into cumFre,
		        // then include it
			idx = tIdx; // update index 
			cumFre -= tree[tIdx]; // set frequency for next loop 
		}
		bitMask >>= 1; // half current interval
	}
	if (cumFre != 0) // maybe given cumulative frequency doesn't exist
		return -1;
	else
		return idx;
}
// if in tree exists more than one index with a same
// cumulative frequency, this procedure will return 
// the greatest one;

//Find index with given cumulative frequency;

int findG(int cumFre){
	int idx = 0,bitMask;
	
	while ((bitMask != 0) && (idx < MaxVal)){
		int tIdx = idx + bitMask;
		if (cumFre >= tree[tIdx]){ 
		        // if current cumulative frequency is equal to cumFre, 
		        // we are still looking for higher index (if exists)
			idx = tIdx;
			cumFre -= tree[tIdx];
		}
		bitMask >>= 1;
	}
	if (cumFre != 0)
		return -1;
	else
		return idx;
}


int main()
{	
	//freopen("a.in","r",stdin);
	//freopen("aa.out","w",stdout);
	int i,y;


	while(scanf("%d",&n)==1 && n)
	{
		MaxVal=n;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&f[i]);
		}
		c[0]=0;
		c[1]=f[1];
		for(i=2;i<=n;i++)
		{
			c[i]=f[i]+c[i-1];
		}
		build_tree();
		//Print();
		
		y=c_sum(5);
		printf("cumulative sum from 1 to 5 : %d\n",y);
		/*
			Now update f[2]+=5;
			then cumulative sum is;
		*/
		update(2,5);
		y=c_sum(5);
		printf("cumulative sum from 1 to 5 : %d\n",y);		
		Scale(2);
		y=c_sum(5);
		printf("cumulative sum from 1 to 5 : %d\n",y);		
		
	}

	return 0;
}
/*

16
1 0 2 1 1 3 0 4 2 5 2 2 3 1 0 2




*/