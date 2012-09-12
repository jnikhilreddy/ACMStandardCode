#include<stdio.h>
#include<string.h>

#define sz 200

char result[20000],a[sz];

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
	char tem[sz],tem2[sz];
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

	strcpy(result,tem);
}

void add(char x[],char y[])
{
	long i,j,k,t1,t2,carry,len1,len2;
	char tem[sz];

	len1=strlen(x);

	len2=strlen(y);

	carry=k=0;

	for(i=len1-1,j=len2-1;i>=0||j>=0;i--,j--)
	{
   		t1=t2=0;

		if(i>=0)
      		t1=(x[i]-'0');

		if(j>=0)
      		t2=(y[j]-'0');

		tem[k++]=((t1+t2+carry)%10)+'0';

		carry=(t1+t2+carry)/10;
	}

	while(carry!=0)
	{
		tem[k++]=(carry%10)+'0';
		carry/=10;
	}

	tem[k]='\0';

	reverse(tem);

	strcpy(result,tem);
}

void multiply(char a[], char b[])
{
	long i,j,k,index,carry,mul,len1,len2;

	if (strcmp(a,"0")==0||strcmp(b,"0")==0)
	{
		strcpy(result,"0");

		return;
	}

	len1=strlen(a);

	len2=strlen(b);
	
	j=len1+len2;

	for(i=0;i<j;i++)
		result[i]='0';

	index = -1;

	for(i=len2-1;i>-1;i--)
	{
		index++;

		carry=0;

		for(j=len1-1,k=index;j>-1;j--,k++)
		{
			mul=(a[j]-'0')*(b[i]-'0')+(result[k]-'0')+ carry;

			carry=mul/10;

			result[k]=(mul%10)+'0';
		}
		result[k]=(carry%10)+'0';
	}

	if(carry!=0)
		k++;  

	result[k]='\0';

	reverse(result);
	
	return;
}

void main()
{	
	while(1==scanf(" %[^\n]s",a))
	{	
		if(strcmp(a,"0")==0)
			printf("1\n");

		else
		{	
		multiply(a,a);

		add(result,"2");

		substract(result,a);
		
		printf("%s\n",result);
		}
		
		memset(result,'\0',sizeof(result));
		memset(a,'\0',sizeof(a));	
	}		
}