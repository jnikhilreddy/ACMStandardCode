#include<stdio.h>
#include<string.h>
long aEnMODb(long a,long b,long n);//Find b^p%m.
void main()
  {
  long a,b,n,y;
  while(scanf("%ld%ld%ld",&a,&n,&b)==3){
  y=aEnMODb(a,b,n);
  printf("%ld\n",y);
  }
  }
long aEnMODb(long a,long b,long n)
{
long mod=1,multi=a%b;
while (n>0)
 {
 if (n%2==1)
	 {
  mod=(mod*multi)%b;
	}
  multi=(multi*multi)%b;
  n/=2;
  }
 return(mod);
}