#include <stdio.h>
#include <string.h>

#define CSE 100

char num1[CSE],num2[CSE],res[CSE];

long top;

void Push(char d)
{
	res[top]=d;
	top++;

	return ;
}

void Reverse()
{
	long i,j;
	char rr;

	for(i=top-1,j=0;j<i;j++,i--)
	{
		rr=res[i];
		res[i]=res[j];
		res[j]=rr;
	}
	return;
}

void Test(char x[],char y[])
{
	long len,len1,c,len2,i,j,t;
	long t1,t2;

	top=0;

	len1=strlen(x);
	len2=strlen(y);

	t=0;

	if(len1>len2)
	{
		len=len1;
	}
	else
	{
		len=len2;
	}
	c=0;
	for(i=len1-1,j=len2-1;i>=0  || j>=0;i--,j--)
	{	
		if(i<0)
		{
			i=0;
			t1=0;
		}
		else
		{
			t1=x[i]-'0';
		}
		if(j<0)
		{
			j=0;
			t2=0;
		}
		else
		{
			t2=y[j]-'0';
		}

		t=t1+t2+c;
		c=t/10;
		Push((t%10)+'0');
	}
	if(c)
	{
		Push(c+'0');
	}
	Reverse();
}

int main()
{
	while(1)
	{
		scanf(" %s %s",num1,num2);
		Test(num1,num2);
		printf("RES  : %s\n",res);
		memset(res,'\0',sizeof(res));
		memset(num1,'\0',sizeof(num1));
		memset(num2,'\0',sizeof(num2));
	}

	return 0;
}