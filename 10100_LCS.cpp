#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>


#define SUST 1009
#define PN 25

char x[SUST][PN],y[SUST][PN];
char str1[SUST],str[SUST];

long c[SUST][SUST],word1,word2;

long max(long num1,long num2)
{
	if(num1>num2)
	{
		return num1;
	}

	return num2;
}

long LCS(long m,long n) 
{
	long i, j,M;

	M=max(m,n);

	for(i = 0; i <= M; i++)
	{
		for(j=0;j<=M;j++)
		{
			c[i][j]=0;
		}
	}
	for(i = 1; i <m; i++)
	{
		for(j = 1; j <n; j++)
		{
			if(strcmp(x[i],y[j])==0) 
			{
				c[i][j] = c[i-1][j-1] + 1;
			}
			else 
			{
				c[i][j] = max(c[i-1][j], c[i][j-1]);
			}
		}
	}

	return c[m-1][n-1];
}

long Make_word( char a[], char b[][PN], long len)
{
	long i=1, j=0, k, val;

	for(;j<len;)
	{
		for(k=0;j<len;j++)
		{
			val = a[j] - '0' ;

			if( ( val>=0 && val<10 ) || ( val>=17 && val<43 ) || ( val>=49 && val<75 ) )
				b[i][k++] = a[j] ;
			
			else if(k>0)
			{
				b[i][k] = '\0';
				k = 0;
				i++;
			}
		}
		if( k>0 ){	b[i][k] = '\0'; i++;	}
	}

	return i;
}

int main()
{
	long len1,len2,CS=1,RES;


	while(gets(str))
	{
		gets(str1);

		len1=strlen(str);
		len2=strlen(str1);
		if(len1==0  || len2==0)
		{
			printf("%2ld. Blank!\n",CS++);
			continue;
		}

		word1=Make_word(str,x,len1);
		word2=Make_word(str1,y,len2);
		
		RES=LCS(word1,word2);
	
			printf("%2ld. Length of longest match: %ld\n",CS++,RES);
		
	}
	return 0;
}