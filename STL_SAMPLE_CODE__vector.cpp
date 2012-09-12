#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>

#include<vector>

#include<algorithm>
using namespace std;

vector<int> v;

int main()
{
	int l,data,i;

	while(scanf("%d",&data)==1  && data)
	{
		v.push_back(data);
	}

	l=v.size();
	for(i=0;i<l;i++)
	{
		printf("%d ",v[i]);
	}
	printf("\n");
	printf("Sort:\n");
	sort(v.begin(),v.end());
	for(i=0;i<l;i++)
	{
		printf("%d ",v[i]);
	}
	printf("\n");

	return 0;
}