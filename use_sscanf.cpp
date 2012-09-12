#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

char str[100],temp[100];
long num1,num2;

int main()
{
      scanf(" %[^\n]",str);

	  sscanf(str,"%ld%ld",&num1,&num2);

	  printf("result %ld %ld\n",num1,num2);

	  return 0;
}