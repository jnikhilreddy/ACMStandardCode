#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>

#include<algorithm>
using namespace std;

#define CSE 20

char a[CSE];



int To_decimal()
{
	int i,t,cnt,p,n;

	n=strlen(a);

	p=n-1;

	cnt=0;

	for(i=0;i<n;i++,p--)
	{
		t=pow(2,p)*(a[i]-'0');
		cnt+=t;
	}

	

	return cnt;
}

int main()
{
	long y;

	while(scanf(" %s",a)==1)
	{
		
		y=To_decimal();
		
		printf("res  %ld\n",y);
		
	}
	
	return 0;
}
