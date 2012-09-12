#include<stdio.h>
#include<string.h>
#define sz 27

int ara[sz][sz];

void main()
{
    //freopen("a.in","r",stdin);

	int tcase, i, j, k, l,  max, sum, len ;
	
	char c1, c2, c[30];

	scanf("%d%c%c",&tcase, &c1,&c2);

	while(tcase--)
	{
		scanf("%[^\n]%c",c,&c1);

		len = strlen(c);

		for(i=1;i<=len;i++)
		{
			for(j=1;j<=len;j++)
			{
				ara[i][j] = c[j-1] -'0';

				ara[i][j] = ara[i][j-1] + ara[i][j];
			}
			
			if(i<len) scanf("%[^\n]%c",c,&c1);
		}

		scanf("%c",&c1);
		
		for(i=1;i<=len;i++)
			for(j=1;j<=len;j++)
				ara[i][j] = ara[i][j] + ara[i-1][j];

		max = 0;

		for(i=1;i<=len;i++)
			for(j=1;j<=len;j++)
				for(k=1;k<=len;k++)
					for(l=1;l<=len;l++)
					{
						sum = ara[k][l] - ara[i-1][l] - ara[k][j-1] + ara[i-1][j-1];

						if(sum>max && sum == (k+1 -i)*(l+1-j))	max = sum;
					}

					printf("%d\n\n",max);
	}
}
