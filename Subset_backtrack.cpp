#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 30
#define MAXCANDIDATES 30

bool is_a_solution ( int k, int n )
{
        return ( k == n ) ;
}

void process_solution( int a[], int k, int arr[] )
{
        int i;                          /* counter */

        for ( i = 1; i <= k; i++ )
			
			if ( a[i] == 1 ) printf ( " %d", arr[i] ) ;

        printf("\n");

		return ;
}

void construct_candidates ( int arr[], int a[], int k, int n, int c[], int *ncandidates )
{
		*ncandidates = 0 ;

		c[ (*ncandidates)++ ] = 1 ;
		c[ (*ncandidates)++ ] = 0 ;

		return ;
}

void backtrack ( int a[], int k, int n, int arr[] )
{
        int c[MAXCANDIDATES] ;        /* candidates for next position */
        int ncandidates ;             /* next position candidate count */
        int i ;                       /* counter */

        if ( is_a_solution ( k, n ) ) // is k == n

                process_solution ( a, k, arr ) ;
        else
		{
                k = k + 1 ;

                construct_candidates ( arr, a, k, n, c, &ncandidates ) ;// leaf level

                for ( i = 0; i < ncandidates; i++ )
				{
                        a[k] = c[i] ;

                        backtrack ( a, k, n, arr );
                }
        }
		return ;
}

void generate_subsets ( int arr[], int n )
{
        int a[NMAX] ;                    /* solution vector */

        backtrack ( a, 0, n, arr ) ;

		return ;
}

void main ()
{
		int arr[20], i, N ;

		//freopen ( "out.txt", "w", stdout ) ;

		scanf ( "%d", &N ) ;

		for ( i = 1; i <= N; i++ ) scanf ( "%d", &arr[i] ) ;

		generate_subsets ( arr, N ) ;
}
