#include<stdio.h>
#include<string.h>

#define SZ 100
#define max(a , b) (a > b ? a : b)
#define min(a , b) (a < b ? a : b)

int graph[SZ][SZ] , n , m , link[SZ];
int levelX[SZ] , levelY[SZ];
bool usedX[SZ] , usedY[SZ];

bool findpath(int i)
{
	int j;
	usedX[i] = true;
	for (j = 0; j < m; j++)
		if (!usedY[j] && levelX[i] + levelY[j] == graph[i][j])
		{
			usedY[j] = true;
			if (link[j] == -1 || findpath(link[j]))
			{
				link[j] = i;
				return true;
			}
		}
	return false;
}

int maxweight()
{
	memset(link , -1 , sizeof(link));
	memset(levelX , 0 , sizeof(levelX));
	memset(levelY , 0 , sizeof(levelY));

	int i , j,  k;
	for(i = 0;i<n;i++)
		for(j = 0;j<m;j++)
			levelX[i] = max(levelX[i] , graph[i][j]);

	for(k = 0;k<n;k++)
	{
		while(1)
		{
			memset(usedX , false , sizeof(usedX));
			memset(usedY , false , sizeof(usedY));
			if(findpath(k)) break;

			int delta = (1<<30);
			for (i = 0; i < n; i++)
				if (usedX[i])
					for (j = 0; j < m; j++)
						if (!usedY[j])
							delta = min(delta, levelX[i] + levelY[j] - graph[i][j]);
			if (delta == 0) break;
			for (i = 0; i < n; i++)
				if (usedX[i])
					levelX[i] += delta;
			for (i = 0; i < m; i++)
				if (usedY[i])
					levelY[i] -= delta;
		}
	}
	int result = 0;
	for (i = 0; i < n; i++)
		result += levelX[i];
	for (i = 0; i < m; i++)
		result += levelY[i];
	return result;
}

int main()
{
	int i , j;
	while(scanf("%d%d" , &n , &m) == 2)
	{
		memset(graph , 0 , sizeof(graph));
		for(i = 0;i<n;i++)
			for(j = 0;j<m;j++)
				scanf("%d" , &graph[i][j]);
		j = maxweight();
		printf("%d\n" , j);
	}
	return 0;
}
/*

3 3

1 4 5
5 7 6
5 8 8

3 3
1 1 1
1 1 1
1 1 1

*/