#define SIZE 25

#include<stdio.h>
#include<string.h>

char string1[SIZE], string2[SIZE], s[SIZE][SIZE];
int  c[SIZE][SIZE];

int  input(char* string);
int  min(int a, int b);
char find_char(int del, int change, int insert, int min);
void print_command(int i, int j);

int main(void)
{
	int i, j, length1, length2;
	
	while(input(string1))
	{
		input(string2);

		length1 = strlen(string1);
		length2 = strlen(string2);

		//Boundary Condition.
		for(i = 1, c[0][0] = 0, s[0][0] = 'N'; i <= length2; i++)
		{
			c[0][i] = i;
			s[0][i] = 'I';
		}

		for(i = 1; i <= length1; i++)
		{
			c[i][0] = i;
			s[i][0] = 'D';
		}

		//Dynamic Programming Part.
		for(i = 1; i <= length1; i++)
		{
			for(j = 1; j <= length2; j++)
			{
				if (string1[i - 1] == string2[j - 1])
				{
					c[i][j] = c[i - 1][j - 1];
					s[i][j] = 'N';
				}		
				else
				{
					c[i][j] = min(c[i - 1][j], min(c[i - 1][j - 1], c[i][j - 1])) + 1;
					s[i][j] = find_char(c[i - 1][j], c[i - 1][j - 1], c[i][j - 1], c[i][j] - 1);
				}
			}
		}

		print_command(length1, length2);
		printf("E\n");
	}
	
	return(0);
}

int min(int a, int b)
{
	return((a < b) ? a : b);
}

char find_char(int del, int change, int insert, int min)
{
	if (min == del) return('D');
	if (min == change) return('C');
	if (min == insert) return('I');

	return(NULL);
}

void print_command(int i, int j)
{
	if (i < 0 || j < 0) return;

	if (s[i][j] == 'N')
	{
		print_command(i - 1, j - 1);
	}

	else if (s[i][j] == 'D')
	{
		printf("D%c%d%d", string1[i - 1], (i / 10) % 10, i % 10);
		print_command(i - 1, j);
	}

	else if (s[i][j] == 'C')
	{
		printf("C%c%d%d", string2[j - 1], (i / 10) % 10, i % 10);
		print_command(i - 1, j - 1);
	}

	else if (s[i][j] == 'I')
	{
		printf("I%c%d%d", string2[j - 1], ((i + 1) / 10) % 10, (i + 1) % 10);
		print_command(i, j - 1);
	}
	
	return;
}

int input(char* string)
{
	int i;
	
	scanf("%c", &string[0]);

	if (string[0] == '#') return(0);

	for(i = 0; string[i] != ' ' && string[i] != '\n'; i++) scanf("%c", &string[i + 1]);

	string[i] = NULL;
}