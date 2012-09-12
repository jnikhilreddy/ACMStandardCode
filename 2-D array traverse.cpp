
/*
				DP 
****************************************
************ Abu Zahed Jony ************
********** jony_cse@yahoo.com **********
****************************************

A table composed of N x M cells,
each having a certain quantity of apples, is given.
You start from the upper-left corner.
At each step you can go down or right one cell.
Find the maximum number of apples you can collect. 

*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define CSE 109

int cost[CSE][CSE],r[CSE][CSE];

long Max(long aa,long bb)
{
	if(aa>bb)
	{
		return aa;
	}
	return bb;
}

int main()
{
	int i,j,row,col,up,down;

	while( scanf("%d %d",&row,&col)==2 )
	{
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				scanf("%d",&cost[i][j]);
			}
		}

		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				if(i>0)
				{
					up=r[i-1][j];
				}
				else
				{
					up=0;
				}
				if(j>0)
				{
					down=r[i][j-1];
				}
				else
				{
					down=0;
				}
				r[i][j]=cost[i][j]+Max(up,down);
			}
		}

		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				printf("%d ",r[i][j]);
			}
			printf("\n");
		}

		printf("Result  %d\n",r[row-1][col-1]);
		
	}

	return 0;
}
/*
3 3
1 2 5 
2 2 1
4 9 2

*/