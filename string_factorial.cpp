#include <stdio.h>
#include <string.h>

#define SZ 2600

char factorial[1005][SZ] ;

char M[5][SZ], sum[SZ] ;
char f[SZ], temp[SZ] ;

void str_rev ( char X[] )
{
    char temp ;
    int len, i ;

    len = strlen ( X ) ;
    
    for ( i = 0; i < len / 2; i++ )
    {
        temp = X[i] ;
        X[i] = X[len-1-i] ;
        X[len-1-i] = temp ;
    }
    return ;
}

void add ( char A[], char B[], char S[] )
{
    int sum, carry, la, lb, len, i ;

    str_rev ( A ) ;
    str_rev ( B ) ;

    for ( i = strlen (A) - 1; i > 0; i-- )
    {
        if ( A[i] == '0' )
            A[i] = NULL ;
        else            
            break ;
    }
    la = i + 1 ;

    for ( i = strlen (B) - 1; i > 0; i-- )
    {
        if ( B[i] == '0' )
            B[i] = NULL ;
        else            
            break ;    
    }
    lb = i + 1 ;

    if ( la > lb )

        for ( len = la, i = lb; i < len; i++ )

            B[i] = '0' ;
    else
        for ( len = lb, i = la; i < len; i++ )

            A[i] = '0' ;
    
    for ( i = 0, carry = 0; i < len; i++ )
    {
        sum = ( A[i] - '0' ) + ( B[i] - '0' ) + carry ;

        if ( sum >= 10 )
        {   
            sum %= 10 ;
            carry = 1 ;
        }
        else  carry = 0 ;

        S[i] = sum + '0' ;
    }
    if( carry )
    {
        S[i] = carry + '0' ;  S[i+1] = NULL ;
    }
    else  S[i] = NULL ;

    str_rev ( S ) ;

    return ;
}

void multiply ( char A[], char B[], char ML[] )
{
    int la, lb, i, j, mlp, carry, lm ;
    
    strcpy ( sum, "000" ) ;

    la = strlen ( A ) ;
    lb = strlen ( B ) ;

    str_rev ( A ) ;
    str_rev ( B ) ;
    
    for ( i = 0; i < la; i++ )
    {
        for ( j = 0, carry = 0; j < lb; j++ )
        {
            mlp = ( A[i] - '0' ) * ( B[j] - '0' ) + carry ;
            
            if ( mlp >= 10 )
            {
                carry = mlp / 10 ;
                mlp %= 10 ;
            }
            else carry = 0 ;

            M[i][j] = mlp + '0' ;
        }
        if( carry )
        {
            M[i][j] = carry + '0' ;  M[i][j+1] = NULL ;
        }
        else  M[i][j] = NULL ;
       
        lm = strlen ( M[i] ) ;

        str_rev ( M[i] ) ;
        
        for ( j = lm; j < lm + i; j++ )

            M[i][j] = '0' ;

        M[i][j] = NULL ;

        add ( M[i], sum, sum ) ;
    }
    strcpy ( ML, sum ) ;
}

void str_factorial ( int N, char fact[] )
{
    char str[10] ;

    if ( N < 2 )
    {
        strcpy ( fact, "1" ) ;
        strcpy ( factorial[1], fact ) ;

        return ;
    }
    if ( factorial[N][0] )

        strcpy ( fact, factorial[N] ) ;

    else
    {
        sprintf ( str, "%d", N ) ;

        str_factorial ( N - 1, temp ) ;

        strcpy ( factorial[N-1], temp ) ;

        multiply ( str, temp, fact ) ;
    }
}

void main ()
{
    int N ;

    while ( scanf ( "%d", &N ) == 1 )
    {
        str_factorial( N, f ) ;

        printf ( "%d!\n%s\n", N, f ) ;
    }
}
