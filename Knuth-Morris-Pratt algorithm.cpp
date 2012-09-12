/*
	Knuth-Morris-Pratt algorithm
	complexity O(n+m)
	return the position of match;
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define CSE 50

void preKmp(char *x, int m, int kmpNext[]) 
{
   int i, j;

   i = 0;
   j = kmpNext[0] = -1;
   
   while (i < m) 
   {
      while (j > -1 && x[i] != x[j])
	  {
         j = kmpNext[j];
	  }
      i++;
      j++;
      if (x[i] == x[j])
         kmpNext[i] = kmpNext[j];
      else
         kmpNext[i] = j;
   }
}


int KMP(char *x, int m, char *y, int n) 
{
   int i, j, kmpNext[CSE];

   /* Preprocessing */
   preKmp(x, m, kmpNext);

   /* Searching */
   i = j = 0;
   while (j < n) 
   {
      while (i > -1 && x[i] != y[j])
	  {
         i = kmpNext[i];
	  }
      i++;
      j++;
      if (i >= m) 
	  {
         return j-i;//OUTPUT(j - i);
         i = kmpNext[i];
      }
   }

   return 0;
}

int main()
{
	char x[CSE],m,n,y[CSE];
	int res;

	while(1)
	{
		gets(x);
		gets(y);
		
		m=strlen(x);
		n=strlen(y);

		res = KMP(x,m,y,n);

		if(res)
		{
			printf("RES : %d\n",res);
		}
		else
		{
			printf("Not match\n");
		}
	}

	return 0;
}

/*

nano
nanaonnonanona

*/