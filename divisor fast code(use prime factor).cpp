#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#define SZ 10000020
bool flag [SZ];
long prime[664600],c=0;
long nfactor, ndiv;
__int64 factor[50], x[50], divisor[100000];

void sieve(void){
    long i,j,r,k=(long)sqrt(SZ);
   
    prime[c++]=2;
    prime[c++]=3;
    for(i=5;i<=SZ;i+=2){
        if(flag[i]==0&&i%3!=0){
            prime[c++]=i;
            if(i<=k){
                r=i<<1;
                for(j=i*i;j<=SZ;j+=r){
                    flag[j]=1;
                    if(j%3==i%3)
                        j+=r;
                }
            }
        }
    }
}

void Prime_factor (__int64 n) {
    __int64 sq, i;
    sq = (__int64) sqrt(n);
    for(i = 0; prime[i] <= sq; i++) {
        while(n % prime[i] == 0) {
            factor[nfactor++] = prime[i];
            n /= prime[i];
        }
    }
    if(n > 1)
        factor[nfactor++] = n;
}

void Combination(int i, int k) {
    __int64 Div = 1;
    for(int j = 0; j < k; j++)
        Div*=x[j];
    divisor[ndiv++] = Div;   
    for( ; i < nfactor; i++) {
        if(factor[i] == x[k])
            continue;
        x[k]=factor[i];
        x[k+1]=0;
        Combination(i+1,k+1);
    }
}

int main() {
    sieve();   
    __int64 n, i, res, ntemp;
//    printf("Total Prime = %ld\nLast Prime = %ld\n",c,prime[c-1]);
    while(scanf("%I64d",&n) == 1 && n) {
        for(i = 0; i < 50; i++) {
            x[i] = factor[i] = 0;
        }
        ndiv = nfactor = 0;
        Prime_factor(n);
        Combination(0, 0);
        res = 0;
        for(i = 1; i < ndiv; i++) {
            ntemp = n;
            while(ntemp % divisor[i] == 0) {
                res++;
                ntemp /= divisor[i];
            }
        }
        printf("%I64d %I64d\n",n,res);
       
    }
    return 0;
}
