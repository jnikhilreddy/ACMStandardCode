#include <stdio.h>
#include <math.h>

#define NMAX 10
#define MAXCANDIDATES 10

int count ,a[NMAX],n;

bool is_a_solution (int k)
{
        return ( k == n  ) ;
}

void process_solution (int k )
{
        int i ;                          /* counter */

		printf ( "%2d     ", ++count ) ;

        for ( i = 1; i <= k; i++ ) 
		{
			printf ( " %d", a[i] ) ;
		}
        printf ( "\n" ) ;

		return ;
}

void construct_candidates ( int k,int c[], int *ncandidates )
{
        int i, j ;
		bool legal_move ;

		*ncandidates = 0 ;

		for ( i = 1; i <= n; i++ )
		{
			legal_move = true ;

			for ( j = 1; j < k; j++ )
			{
				if ( abs ( k -j ) == abs ( i - a[j] ) )
				{
					legal_move = false ;
				}
				if ( i == a[j] ) 
				{
					legal_move = false ;
				}
			}
			if ( legal_move )
			{
				c[ (*ncandidates)++ ] = i ;
			}
		}
		return ;
}

void backtrack ( int k)
{
        int c[MAXCANDIDATES] ;        /* candidates for next position */
        int ncandidates ;             /* next position candidate count */
        int i ;                       /* counter */

        if ( is_a_solution ( k) )

                process_solution (k ) ;
        else
		{
                k = k + 1 ;
                construct_candidates (k, c, &ncandidates ) ;
                for ( i = 0; i < ncandidates; i++ )
				{
                        a[k] = c[i] ;
                        backtrack ( k) ;

                }
        }
		return ;
}

void solve_n_queens_problem ()
{

        backtrack (0) ;

		return ;
}

void main ()
{

	int pik=1,tcase;

	scanf ( "%d", &tcase) ;

	while ( tcase-- )
	{	
		scanf("%d",&n);
		solve_n_queens_problem () ;		
	}
}
