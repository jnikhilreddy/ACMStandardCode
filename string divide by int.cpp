#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Div
{
	char quot[10000] ;
	long long rem ;
} ;

Div divide ( char *S, long F )
{
	Div D ;
	int c = 1, len , i, q ;
	long long N ;

	if ( !F ) 
	{	
		printf ( "Error : Divide by zreo\n" ) ;
		strcpy ( D.quot, "" ) ;
		D.rem = 0 ;
		return D ;
	}

	//omit leading zeros
	len = strlen ( S ) ;

	for ( i = 2, N = S[0] - '0'; F > N; i++ )
	{
		if ( len < i )
		{
			D.quot[0] = '0' ;
			D.quot[1] = '\0' ;
			D.rem = atol ( S ) ;
			return D ;
		}
		N = N * 10 + S[i-1] - '0' ;
		c = i ;
	}
	D.quot[0] = N / F + '0' ;
	D.rem = N % F  ;

	for ( i = c, q = 1; i < len; i++ )
	{
		N = D.rem * 10 + ( S[i] - '0' ) ;
		D.quot[q++] = N / F + '0' ;
		D.rem = N % F ;
	}
	D.quot[q] = '\0' ;

	return D ;
}

void main ()
{
	char A[100] ;
	Div D ;
    long B ;

	while ( scanf ( " %s %d", A, &B ) == 2 )
	{
		D = divide ( A, B ) ;

		printf ( "quotient = %s remainder = %ld\n", D.quot, D.rem ) ;

    }
}