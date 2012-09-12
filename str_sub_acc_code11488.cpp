#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CSE 5009

char result[CSE];

void reverse(char x[])
{
	long len,i,j;

	char dummy;

	len=strlen(x);

	j=len-1;

	for(i=0;i<len/2;i++,j--)
	{
		dummy=x[i];
		x[i]=x[j];
		x[j]=dummy;
	}		
}

void substract(char x[],char y[])
{
	char tem[CSE],tem2[CSE];
	long len1,len2,len,rem;

	long i,j,k;

	strcpy(tem2,y);

	len2=strlen(tem2);

	reverse(tem2);

	len1=strlen(x);

	for(i=len2;i<len1;i++)
		tem2[i]='0';

	for(i=len1-1,j=0,k=0;i>=0;i--,j++)
	{
		rem=0;

		if(j>=0)
			rem=(tem2[j]-'0');

		if(rem>(x[i]-'0'))
		{
			tem[k++]=(10+(x[i]-'0')-rem)+'0';
			tem2[j+1]=tem2[j+1]+1;
		}

		else
			tem[k++]=((x[i]-'0')-rem)+'0';
	}

	tem[k]='\0';

	len=strlen(tem);

	for(i=len-1;tem[i]=='0';i--)
		tem[i]='\0';

	reverse(tem);
	if(strlen(tem)==0)
	{
		strcpy(tem,"0");
	}

	strcpy(result,tem);
}

long Test(char x[],char y[])
{
	long i,lx,ly;

	lx=strlen(x);
	ly=strlen(y);
	if(lx!=ly)
	{
		if(lx>ly)
		{
			return 1;
		}
		return -1;
	}
	
	if(lx==ly)
	{
		for(i=0;i<lx;i++)
		{
			if(x[i]>y[i])
			{
				return 1;
			}
			else if(x[i]<y[i])
			{
				return -1;
			}
		}
		if(i==lx)
		{
			return 0;
		}
	}

	return 0;
}

int main()
{
	char str1[CSE],str2[CSE],m1,m2,ts1[CSE],ts2[CSE],tt[CSE];
	long i,l,k,y,T;

	scanf("%ld",&T);
	while(T--)
	{
		scanf(" %s %s",str1,str2);
		m1=0;
		m2=0;
		k=0;
		i=0;
		l=strlen(str1);
		if(str1[0]=='-')
		{
			i++;
			m1=1;
		}
		for(;i<l;i++)
		{
			ts1[k++]=str1[i];
		}
		ts1[k]='\0';

		k=0;
		i=0;
		l=strlen(str2);
		if(str2[0]=='-')
		{
			i++;
			m2=1;
		}
		for(;i<l;i++)
		{
			ts2[k++]=str2[i];
		}
		ts2[k]='\0';

		y=Test(ts1,ts2);
		if(y<0)
		{
			strcpy(tt,ts1);
			strcpy(ts1,ts2);
			strcpy(ts2,tt);
		}

		substract(ts1,ts2);
		l=strlen(result);
		result[l]='\0';
		
		if(y<0)
		{
			printf("-");
			printf("%s\n",result);
		}
		else
		{
			printf("%s\n",result);
		}

	}

	return 0; 
}