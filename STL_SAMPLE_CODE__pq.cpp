#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>

#include<queue>

#include<algorithm>
using namespace std;

struct pq
{
	long name,cost;
	bool operator < (const pq &b) const
	{
		if(name==b.name)
		{
			return cost<b.cost;
		}
		else
		{
			return (name>b.name);
		}
	}
};


int main()
{	
	//freopen("t.in","r",stdin);
	//freopen("ttt.out","w",stdout);

	pq data,y;
	priority_queue<pq> que;
	long u,v;
	
	while( scanf("%ld %ld",&u,&v)==2)
	{
		data.name=u;
		data.cost=v;
		que.push(data);
		y=que.top();
		printf("A %ld B %ld\n",y.name,y.cost);
	
	}

	return 0;
}
/*

*/