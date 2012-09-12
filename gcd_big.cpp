#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define sz 100

char gg[sz];

int compare_number(char *dec1, char *dec2);
void reverse_string(char *string, int length);
void multiply_by_integer(char *num, int multiplier, char* result);
void character_subtraction(char *num1, char *num2, char *result);
int find_division_time(char *dividend, char *divisor);
void character_division(char *num1, char *num2, char *result, char *mod);
void gcd(char *a , char *b);

int main()
{
	char num1[sz] , num2[sz];
	while(scanf(" %s %s" , num1 , num2) == 2)
	{
		gcd(num1 , num2);

		printf("%s\n" , gg);
	}
	return 0;
}

void gcd(char *a , char *b) 
{ 
    char tmp[sz] , res[sz] , tmp1[sz]; 
    if(strcmp(a , "0") == 0)
	{
		strcpy(gg , b);
		return ;
	} 
    while(strcmp(a , "0") != 0) 
    {
	character_division(b , a , res , tmp);
        if(strcmp(tmp , "0") == 0) 
		{
			strcpy(gg , a);
			return ; 
		}
        else 
		{
			character_division(a , tmp , res , tmp1);
			strcpy(a , tmp1);
			strcpy(b , tmp);
		}
	}
	strcpy(gg , b);
	return ; 
}

void reverse_string(char *string, int length)
{
	int i;

	for(i = 0; i < length / 2; i++)
	{
		string[i] ^= string[length - i - 1] ^= string[i] ^= string[length - i - 1];
	}

	return;
}

int compare_number(char *dec1, char *dec2)
{
	int length1, length2, result;

	//If one of the number is negative, process them here.
	if (dec1[0] != '-' && dec2[0] == '-') return(1);
	if (dec1[0] == '-' && dec2[0] != '-') return(-1);

	//If the numbers are not having equal sign, they will not come here.
	length1 = strlen(dec1);
	length2 = strlen(dec2);

	if (length1 == length2) result = strcmp(dec1, dec2);
   else result = length1 - length2;

   //If both the number are negative.
   if (dec1[0] == '-') return(-result);
   else return(result);
}

void character_subtraction(char *num1, char *num2, char *result)
{
	int  i, j, k;
	
   //If 'num1' < 'num2', then swap them and put '-' at the first of the 'result'.
	if (compare_number(num1, num2) < 0)
	{
		swap(num1 , num2);
        sprintf(result, "-%s", num1);
	}

	else strcpy(result, num1);

	for(i = strlen(result) - 1, j = strlen(num2) - 1; j >= 0; i--, j--)
	{
      if (result[i] >= num2[j])
      {
         result[i] = result[i] - num2[j] + '0';
      	continue;
      }

		result[i] = (result[i] + 10) - num2[j] + '0';
		for(k = i - 1; k > 0 && result[k] == '0'; k--) result[k] = '9';
		result[k] -= 1;
	}

   //Ignoring all the leading zeros.
   for(i = (result[0] == '-') ? 1 : 0; result[i] == '0'; i++);

   //If the result is 0, then previous loop will end in 'NULL'.
   if (result[i] == NULL) --i;

   //Launch all the digits other than leading zeros.
   for(j = (result[0] == '-') ? 1 : 0;	result[i] != NULL; j++, i++) result[j] = result[i];

   result[j] = NULL;

	return;
}

void multiply_by_integer(char *num, int multiplier, char* result)
{
	int i, index, carry, mul;

	if (multiplier == 0)
	{
		sprintf(result, "0");
   	return;
	}

	for(i = strlen(num) - 1, carry  = index = 0; i >= 0; i--)
	{
		mul = (num[i] - '0') * multiplier + carry;
		carry = mul / 10;
		result[index++] = mul % 10 + '0';
	}

	while(carry != 0)
	{
		result[index++] = carry % 10 + '0';
		carry /= 10;
	}

	if (index == 0) result[index++] = '0';
	result[index] = NULL;

	reverse_string(result, index);

	return;
}

int find_division_time(char *dividend, char *divisor)
{
	int  num, length1, length2;
	char sub[100 + 1], mul[100 + 3];

	length1 = strlen(dividend);
	length2 = strlen(divisor);

	if (length1 < length2) return(0);

	//Launch the first 1 or 2 digits of the dividend.
	num = dividend[0] - '0';
	if (length1 > length2 && length1 > 1) num = num * 10 + (dividend[1] - '0');

	num = num / (divisor[0] - '0');
	multiply_by_integer(divisor, num, mul);

	while(compare_number(mul, dividend) > 0)
	{
		--num;
		multiply_by_integer(divisor, num, mul);
	}

	character_subtraction(dividend, mul, sub);
	strcpy(dividend, sub);

	return(num);
}

void character_division(char *num1, char *num2, char *result, char *mod)
{
	int i, index = 0;

	//Launch the very first 'length2' characters in 'mod'.
	for(i = 0; num1[i] != NULL && num2[i] != NULL; i++) mod[i] = num1[i];
	mod[i] = NULL;

	//If 'mod' >= 'num2'.
	if (compare_number(mod, num2) >= 0)
	{
		result[index++] = find_division_time(mod, num2) + '0';
	}

	//Launch the rest characters one by one.
	while(num1[i] != NULL)
	{
		strncat(mod, &num1[i++], 1);
		result[index++] = find_division_time(mod, num2) + '0';
	}

	if (index == 0) result[index++] = '0';
	result[index] = NULL;

    if (mod[0] == '0') mod[1] = NULL;

	return;
}