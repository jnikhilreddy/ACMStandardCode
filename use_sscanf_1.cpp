#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

char str[100],temp[100];
long num1,num2,num3,num4;

int main()
{
      scanf(" %[^\n]",str);

	  sscanf(str,"%ld:%ld %ld:%ld",&num1,&num2,&num3,&num4);

	  printf("result %ld %ld %ld %ld\n",num1,num2,num3,num4);

	  return 0;
}