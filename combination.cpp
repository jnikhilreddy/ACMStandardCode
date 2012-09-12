#include<stdio.h>
main()               //rt
  {
  double res,t2,t3;
  long n,m,i,j;
  while(scanf("%ld%ld",&n,&m)==2&&(n!=0&&m!=0))
	 {
	  res=1;
	  t2=n-m;
	  t3=n-t2;
	  if(t2>t3)
		 {
		 for(i=m,j=n-m+1;i>=1&&j<=n;j++,i--)
		 res*=(double)j/i;
		 }
		 else
			{
			 for(i=n-m,j=m+1;i>=1&&j<=n;i--,j++)
			 res*=(double)j/i;
			}
	 printf("%ld things taken %ld at a time is %.0lf exactly.\n",n,m,res);
	 }
	 return 0;
  }