#include<stdio.h>
#include<string.h>

char str[100],x[100];
int pos[100];
long n,r;

void permutation(int k);

void main()
{
	while(scanf("%s %ld",str,&r)==2)
	{
		n=strlen(str);
		memset(pos,0,sizeof(int)*n);
		memset(x,0,sizeof(char)*n);
		permutation(0);
	}
}

void permutation(int k)
{
	if(k==r)
	{
		printf("%s\n",x);
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(pos[i])
			continue;
		if(x[k]==str[i])			
			continue;
		x[k]=str[i];
		x[k+1]=0;
		pos[i]=1;
		permutation(k+1);
		pos[i]=0;
	}
}