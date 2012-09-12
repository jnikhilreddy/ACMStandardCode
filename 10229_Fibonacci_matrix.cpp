#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#define CSE 21

__int64 Fibs[CSE][2][2],Power[CSE],Limit[CSE],Ans[2][2],Tem[2][2];

void Mat_multi(__int64 mat1[][2],__int64 mat2[][2],__int64 res[][2])
{
	__int64 i,j,k,sum;
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			sum=0;
			for(k=0;k<2;k++)
			{
				sum+=(mat1[i][k]*mat2[k][j])%Power[19];
			}
			res[i][j]=sum;
		}
	}
	return ;
}

void Create()
{
	__int64 i;

	Power[0]=1;
	Limit[0]=1;
	
	for(i=1;i<CSE;i++)
	{
		Power[i]=Power[i-1]*2;
		Limit[i]=Power[i]+Power[i-1];
	}

	Fibs[1][0][0]=0;
	Fibs[1][1][0]=Fibs[1][1][1]=Fibs[1][0][1]=1;

	for(i=2;i<CSE;i++)
	{
		Mat_multi(Fibs[i-1],Fibs[i-1],Fibs[i]);
	}
}

int main()
{
	Create();
	
	__int64 F,M,i,j,k;

	while(scanf("%I64d%I64d",&F,&M)==2)
	{
		F=F%Limit[M];

		Ans[0][0]=Ans[1][1]=1;
		Ans[0][1]=Ans[1][0]=0;

		for(i=19;i>-1;i--)
		{
			if(Power[i]<=F)
			{
				Mat_multi(Ans,Fibs[i+1],Tem);
				F-=Power[i];

				for(j=0;j<2;j++)
				{
					for(k=0;k<2;k++)
					{
						Ans[j][k]=Tem[j][k];
					}
				}
			}
		}
		printf("%I64d\n",Ans[0][1]%Power[M]);
	}

	return 0;
}