#include <stdio.h>

int main()
{
    long n,m,i,t; 
    while(scanf("%ld %ld",&n,&m)==2)
    {
        double total=1.0;
        if((n==0)&&(m==0))
		{
            break;
		}
        else if((n==0)||(m==0))
            printf("1\n");
        else
        {
            if(n>m)
            {
                t=n;
                n=m;
                m=t;
            }
            for(i=1;i<=n;i++)
			{
                total*=double(i+m)/i;
			}
             printf("%0.0f\n",total);
        }
    }
    return 0;
}