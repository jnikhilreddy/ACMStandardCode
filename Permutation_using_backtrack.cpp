#include <stdio.h>

#define NMAX 10
#define MAXCANDIDATES 10

bool finished = false;               /* found all solutions yet? */

bool is_a_solution(int a[], int k, int n)
{
        return (k == n);
}

void process_solution(int a[], int k)
{
        int i;                          /* counter */

        for (i=1; i<=k; i++) printf(" %d",a[i]);

        printf("\n");

		return ;
}

void construct_candidates(int a[], int k, int n, int c[], int *ncandidates)
{
        int i;                          /* counter */
        bool in_perm[NMAX];             /* who is in the permutation? */

        for (i=1; i<NMAX; i++) in_perm[i] = false;
        for (i=1; i<k; i++) in_perm[ a[i] ] = true;

        *ncandidates = 0;
		   
        for (i=1; i<=n; i++)
		{
                if (in_perm[i] == false )
				{
                        c[ *ncandidates] = i;
                        *ncandidates = *ncandidates + 1;
                }
		}
		return ;
}

void backtrack ( int a[], int k, int input )
{
        int c[MAXCANDIDATES] ;        /* candidates for next position */
        int ncandidates ;             /* next position candidate count */
        int i ;                       /* counter */

        if ( is_a_solution ( a, k, input ) ) // is k == input
                
				process_solution(a,k);
        else
		{
                k = k+1;
                construct_candidates(a,k,input,c,&ncandidates);
                for (i=0; i<ncandidates; i++)
				{
                        a[k] = c[i];
                        backtrack(a,k,input);
                        if (finished) return;   /* terminate early */
                }
        }
		return ;
}

void generate_permutations ( int n )
{
        int a[NMAX] ;                    /* solution vector */

        backtrack ( a, 0, n ) ;

		return ;
}

void main ()
{
	int N ;

	while ( scanf ( "%d", &N ) == 1 )
	{
		generate_permutations ( N ) ;
	}
}
