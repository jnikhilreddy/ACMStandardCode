#include <stdio.h>

struct solution
{
	long d, x, y ;
} ;

solution extended_euclid ( long a, long b )
{
	solution s, s1 ;

	if ( !b )
	{
		s.d = a ;
		s.x = 1 ;
		s.y = 0 ;
		return s ;
	}
	s1 = extended_euclid ( b, a % b ) ;

	s.d = s1.d ;
	s.x = s1.y ;
	s.y = s1.x - s1.y * ( a / b ) ;

	return s ;
}

int main ()
{
	solution s ;
	long a, b,tcase ,k,tx;

	while ( tcase-- )
	{
		scanf("%ld%ld",&tx,&k);
		s = extended_euclid ( a, b ) ;

		printf ( "%ld %ld %ld\n", s.x, s.y, s.d ) ;
	}
	return 0 ;
}