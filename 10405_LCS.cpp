#include <stdio.h>
#include <string.h>

#define SIZE 1001

int max(int a, int b) { return a > b? a: b; }

int c[SIZE][SIZE];
int LCSLength(char x[], char y[]) {
	int i, j, m, n;
	
	m = strlen(x);
	n = strlen(y);

	for(i = 1; i <= m; i++) c[i][0] = 0;
	for(j = 0; j <= n; j++) c[0][j] = 0;

	for(i = 1; i <= m; i++)
		for(j = 1; j <= n; j++)
			if(x[i-1] == y[j-1]) c[i][j] = c[i-1][j-1] + 1;
			else c[i][j] = max(c[i-1][j], c[i][j-1]);

	return c[m][n];
}

void main () {
	//freopen("d:\\in\\#.in" ,"r", stdin);
	//freopen("d:\\in\\#.out" ,"w", stdout);

	char x[SIZE], y[SIZE];
	while(gets(x)) {
		gets(y);
		printf("%d\n", LCSLength(x, y));
	}
} 