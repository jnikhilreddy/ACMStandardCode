#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>


int c[25][25],b[25][25];
char x[25],y[25];
int i,j,k,m,n;

/*recursive function for printing the LCS*/
void PrintLCS(int i,int j)
{
	if(i==0 || j==0)
		return;
	if(b[i][j]==100)
	{
		PrintLCS(i-1,j-1);
        printf("%c  ",x[i]);
	}
	else if(b[i][j]==101)
		PrintLCS(i-1,j);

	else
		PrintLCS(i,j-1);
}


/*finding the longest subsequence dynamically*/
void LCS_Length()
{

	/*strlen is 1 greater than the given string since
	 we have initialezed the array's 0th place*/
	m=strlen(x)-1;
	n=strlen(y)-1;

	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(x[i]==y[j])
			{
				c[i][j]=c[i-1][j-1]+1;
                b[i][j]=100;                   /*100==\*/
			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i-1][j];
                b[i][j]=101;                   /*101==^*/  
			}
			else
			{
				c[i][j]=c[i][j-1];
                b[i][j]=99;                    /*99==<*/
			}
		}
	}

}

void main()
{

	/*Initializing the 0th place of x[] & y[] char array*/
	x[0]='a';y[0]='z';

	/*scanning the first sequence in x[] (from 1st place)*/
	printf("give the first subsequence:\n");
	gets(&x[1]);
	
	/*scanning the second sequence in y[] (from 1st place)*/
	printf("give the second subsequnce:\n");
	gets(&y[1]);

	LCS_Length();
	printf("The length of the longest subsequence is %d\n",c[m][n]);
	
	printf("Here is the longest subsequences:\n");

	PrintLCS(m,n);
	printf("\n");

}