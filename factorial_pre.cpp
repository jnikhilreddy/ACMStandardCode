#include<stdio.h>
#include<string.h>
#define swap(a,b) a^=b^=a^=b
#define sz 1200

typedef struct{

	char result[sz];

} factorial;
factorial factorials[505];




void multiply(char a[],char b[],char result[]);
void reverse(char x[]);
long toint(char x);
long tochar(long x);
void precalculation();


void main()
{
	//freopen("623.in","r",stdin);
	//freopen("623.out","w",stdout);

	long num;

	precalculation();

	while(scanf("%ld",&num)==1)
	{
		if(num<0)
		{
		    printf("%ld!\n",num);
			printf("1\n");
			//printf("0\n");
		}
		else
		printf("%ld!\n%s\n",num,factorials[num].result);

	}
}

void precalculation()
{


	char str2[sz],result[sz],str1[20];
	long i;

	
	strcpy(factorials[0].result,"1");
	strcpy(factorials[1].result,"1");


	str2[0]='1';
	str2[1]='\0';
	
	for(i=2;i<=501;i++)
	{
			sprintf(str1,"%ld",i);
			multiply(str2,str1,result);
			strcpy(str2,result);
			strcpy(factorials[i].result,result);
	}

}


void multiply(char a[],char b[],char result[])
{

	long i,j,k,index,carry,mul,len1,len2;

	if(strcmp(a,"0")==0 || strcmp(b,"0")==0)
	{
	  strcpy(result,"0");
	  return;
	}

	len1=strlen(a);
	len2=strlen(b);
	j = len1+len2;
	for(i=0;i<j;i++)
		result[i]='0';

	index=-1;

	for(i=len2-1;i>=0;i--)
	{
			index++;
			carry=0;
			for(j=len1-1,k=index;j>=0;j--,k++)
			{
					mul = toint(a[j])*toint(b[i]) + toint(result[k])+carry;
					carry = mul/10;
					result[k]=tochar(mul%10);

			}

			result[k]=tochar(carry%10);

	}

	if(carry!=0)
	  k++;
	result[k]='\0';
	reverse(result);

	return;

}


void reverse(char x[])
{

	long len,i,j;
	len = strlen(x);
	j=len-1;
	for(i=0;i<len/2;i++,j--)
		swap(x[i],x[j]);
}

long toint(char x)
{
  return (x-'0');
}


long tochar(long x)
{
  return (x+'0');
}




