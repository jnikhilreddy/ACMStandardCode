#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>

#include<queue>

#include<algorithm>
using namespace std;

queue<int> q;

int main()
{
	while(!q.empty())
	{
		q.pop();
	}
	int v,y;

	while(scanf("%d",&v)==1  && v)
	{
		q.push(v);
	}
	printf("After queueing:\n");
	while(!q.empty())
	{
		y=q.front();

		printf("%d ",y);

		q.pop();
	}
	printf("\n");

	return 0;
}