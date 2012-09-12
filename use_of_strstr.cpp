#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define CSE 100

char str1[CSE],str2[CSE];

int main()
{
	char *y;

	while(1)
	{
		scanf(" %s",str1);
		scanf(" %s",str2);

		y=strstr(str1,str2);

		printf("y = %d\n",y);

		if(y!=0)
		{
			printf("Yes the word is found.\n");
		}
		else
		{
		     printf("No the word didn't found.\n");
		}

		memset(str1,'\0',sizeof(str1));
		memset(str2,'\0',sizeof(str2));
	}

	return 0;
}

/*
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] ="This is a simple string";
  char * pch;
  pch = strstr (str,"simple");
  strncpy (pch,"sample",5);
  puts (str);
  return 0;
}*/