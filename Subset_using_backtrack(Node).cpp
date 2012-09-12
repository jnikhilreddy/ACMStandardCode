#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 20
#define MAXCANDIDATES 20

bool base_condition ( int a[], int k, int n )
{
	return ( a[k] == n )  ;
}

void process_solution( int a[], int k, int arr[] )
{
        int i;                          /* counter */

        for ( i = 1; i <= k; i++ )
		{
			printf ( " %d", arr[ a[i] ] ) ;
		}
        printf("\n");

		return ;
}

void construct_candidates ( int arr[], int a[], int k, int n, int c[], int *ncandidates )
{
		int i ;
		*ncandidates = 0 ;

		for ( i = a[k-1]+1; i <= n; i++ )
		{
			if ( arr[i-1] != arr[i] )
			{
				c[ (*ncandidates)++ ] = i ;
			}
		}

		return ;
}

void backtrack ( int a[], int k, int n, int arr[] )
{
        int c[MAXCANDIDATES] ;        /* candidates for next position */
        int ncandidates ;             /* next position candidate count */
        int i ;                       /* counter */

        if ( k > 0 ) 
		{
			process_solution ( a, k, arr ) ;
		}
		if ( base_condition ( a, k, n ) ) 
		{
			return ;
		}
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
        int a[NMAX] ;   /* solution vector */

		a[0] = 0 ;

        backtrack ( a, 0, n, arr ) ;

		return ;
}

void main ()
{
		int arr[30], i, N ;

		scanf ( "%d", &N ) ;

		for ( i = 1; i <= N; i++ ) scanf ( "%d", &arr[i] ) ;

		/* Here input data must be sorted, if not sort them */

		generate_subsets ( arr, N ) ;
}
