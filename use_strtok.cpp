/*
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] ="- This, a sample string.";
  char * pch;
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str," ,.-");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (NULL, " ,.-");
  }
  return 0;
}
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define CSE 100

char str1[CSE],str2[CSE],str3[CSE];

int main()
{
	long len,i,cs=1;

	char *ptr;

	while(i)
	{
	     gets(str1);
		 ptr = strtok (str1," ");

		 while(ptr!=NULL)
		 {
		       //printf("CASE  %ld : %s\n",cs++,ptr);
				strcpy(str2,ptr);
			   printf("CASE  %ld : %s\n",cs++,str2);
			   ptr = strtok (NULL, " ");
			   
			   memset(str2,'\0',sizeof(str2));
		 }
	}

	return 0;
}

