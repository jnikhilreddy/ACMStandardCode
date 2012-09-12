#include<stdio.h>
#include<stdlib.h>

#define MAX	100

int A[MAX][MAX],B[MAX][MAX],C[MAX][MAX];

void main()
{
	int M,P,N,i,j,k;

	M = 5;	P = 3;	N = 4;

	for(i=0;i<M;i++)							//	A[M][P]
		for(j=0;j<P;j++)
			A[i][j] = rand() % 10;

	for(i=0;i<P;i++)							//	B[P][N]
		for(j=0;j<N;j++)
			B[i][j] = rand() % 10;

	for(i=0;i<M;i++)							//	C[M][N]
		for(j=0;j<N;j++)
		{
			C[i][j] = 0;
			for(k=0;k<P;k++)
				C[i][j] += A[i][k] * B[k][j];
		}

}



