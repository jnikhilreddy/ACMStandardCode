#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#define CSE 100

char a[CSE],b[CSE],R[CSE];

void add(char a[],char b[],char res[])
{
	char temp[CSE];
	long i,j,k,t1,t2,carry,val,lena,lenb;
	lena=strlen(a);
	lenb=strlen(b);
	carry=k=0;
	for(i=lena-1,j=lenb-1;i>-1||j>-1;i--,j--)
	{
		if(i>-1)
		{
			t1=a[i]-'0';
		}
		else
		{
			t1=0;
		}
		if(j>-1)
		{
			t2=b[j]-'0';
		}
		else
		{
			t2=0;
		}

		val=t1+t2+carry;
		temp[k++]=(val%10)+'0';
		carry=val/10;
	}
	while(carry)
	{
		temp[k++]=(carry%10)+'0';
		carry/=10;
	}
	for(i=k-1,j=0;i>-1;i--,j++)
	{
		res[j]=temp[i];
	}
	res[j]='\0';
}

int main()
{
	while(scanf(" %s %s",a,b) == 2)
	{
	      add(a,b,R);
		  printf("Result  : %s\n",R);
	}
     
	return 0;
}