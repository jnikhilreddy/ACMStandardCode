#include <stdio.h>
#include <string.h>

#define SZ 10005

char A[SZ], B[SZ], S[SZ], temp1[SZ], temp2[SZ] ;

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

    strcpy ( temp1, A ) ;
    strcpy ( temp2, B ) ;

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
    strcpy ( A, temp1 ) ;
    strcpy ( B, temp2 ) ;

    return ;
}

void main ()
{
    while ( 1 )
    {
        scanf ( " %s %s", A, B ) ;

        add ( A, B, S ) ;

        printf ( "%s\n", S ) ;
    }
}