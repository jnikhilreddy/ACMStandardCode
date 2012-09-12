#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>

#include<queue>
#include<map>

#include<algorithm>
using namespace std;
#define INF (1<<30)

#define PI (2*acos(0))
#define ERR 0.000001

#define Min(num1,num2) (num1<num2?num1:num2)
#define Max(num1,num2) (num1>num2?num1:num2)

#define CSE 2009

char str[CSE],line[CSE];
long n,l,In[CSE],Dl[CSE],mat[CSE][CSE];
bool f[CSE][CSE];

long Recurs(long s,long e)
{
	long a,b,c,ttt;

	if(s>=e)
	{
		return 0;
	}
	if(f[s][e])
	{
		return mat[s][e];
	}

	if(str[s]==str[e])
	{
		c=Recurs(s+1,e-1);
	}
	else
	{
		ttt=0;
		a=Recurs(s+1,e)+Min(In[str[s]],Dl[str[s]]);
		ttt=1;
		b=Recurs(s,e-1)+Min(In[str[e]],Dl[str[e]]);
		c=Min(a,b);
		ttt=2;
	}
	mat[s][e]=c;
	f[s][e]=1;
	return c;
}

int main()
{	
	//freopen("t.in","r",stdin);
	//freopen("ttt.out","w",stdout);
	
	char ch;
	long i,u,v,y;

	while( scanf("%ld %ld",&n,&l)==2)
	{
		memset(Dl,0,sizeof(Dl));
		memset(In,0,sizeof(In));
		memset(mat,0,sizeof(mat));
		memset(f,0,sizeof(f));

		scanf(" %s",str);

		scanf("%c",&ch);

		for(i=0;i<n;i++)
		{
			gets(line);
			sscanf(line,"%c %ld %ld",&ch,&u,&v);
			//printf("Temp %c %ld %ld\n",ch,u,v);
	
			In[ch]=u;
			Dl[ch]=v;
		}

		y=Recurs(0,l-1);

		/*long j;

		for(i=0;i<l;i++)
		{
			for(j=0;j<l;j++)
			{
				printf("%ld ",mat[i][j]);
			}
			printf("\n");
		}*/

		printf("%ld\n",mat[0][l-1]);
	}

	return 0;
}

/*

4 4
abda
a 1000 1100
b 350 700
c 200 800
d 200 300


*/