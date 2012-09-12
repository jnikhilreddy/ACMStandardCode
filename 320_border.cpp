#define SIZE 32

#include<stdio.h>

int  x, y;
char bitmap[SIZE][SIZE];

void initial_bitmap(void);
void draw_bitmap(char direction);
void print_bitmap(void);

int main(void)
{
	int  i, test_case, case_num;
	char ch;

	case_num = 1;

	scanf(" %d", &test_case);

	for(i = 0; i < test_case; i++)
	{
		scanf(" %d %d", &x, &y);

      initial_bitmap();

		while(1)
		{
			scanf(" %c", &ch);

			if (ch == '.') break;

			draw_bitmap(ch);
		}

		printf("Bitmap #%d\n", case_num++);
		print_bitmap();

		printf("\n");
	}

	return(0);
}

void initial_bitmap(void)
{
	int i, j;

	for(i = 0; i < SIZE; i++)
	{
		for(j = 0; j < SIZE; j++)
		{
			bitmap[i][j] = '.';
		}
	}

	return;
}

void draw_bitmap(char direction)
{
	if (direction == 'E')
	{
		bitmap[(SIZE - 1) - (y - 1)][x] = 'X';
		++x;
	}

	else if (direction == 'W')
	{
		bitmap[(SIZE - 1) - y][x - 1] = 'X';
		--x;
	}

	else if (direction == 'N')
	{
		bitmap[(SIZE - 1) - y][x] = 'X';
		++y;
	}

	else if (direction == 'S')
	{
		bitmap[(SIZE - 1) - (y - 1)][x - 1] = 'X';
		--y;
	}

	return;
}

void print_bitmap(void)
{
	int i, j;

	for(i = 0; i < SIZE; i++)
	{
		for(j = 0; j < SIZE; j++)
		{
			printf("%c", bitmap[i][j]);
		}

		printf("\n");
	}

	return;
}