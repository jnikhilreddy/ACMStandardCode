/*Strongly Connected Components by chormen*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

#define sz 11
#define NULL 0
#define INF (pow(2,31)-1)

struct node{
	long vert;
	node *forw;
};

node *strt, *ptr, *last;

long vert, edges, ntime, Flag, key;

long mat[sz][sz], dat[sz][sz], comp[sz][sz];
long start[sz], finish[sz], par[sz];
char color[sz];

void DFS_Visit(long und, long graph[][sz])
{
     long index, knd, vnd;

	color[und] = 'g';

	start[und] = ntime = ntime + 1;

	for(index = 1; index <= mat[und][0]; index++)
	{
		vnd = graph[und][index];

		if(color[vnd] == 'w')
		{
			knd = comp[key][0]+= 1;
               comp[key][knd] = vnd;

			par[vnd] = und;

			DFS_Visit(vnd, graph);
		}

		
	}

	color[und] = 'b';

	finish[und] = ntime = ntime + 1;

	if(Flag)
     {
		ptr->vert = und;
		ptr->forw = new(node);
		ptr = ptr->forw;
	}
}


void DFS(long graph[][sz])
{
     long und;

	for(und = 1; und <= vert; und++)
	{
		color[und] = 'w';
		par[und] = NULL; 
	}

	ntime = 0;

	for(und = 1; und <= vert; und++)
	{
		if(color[und] == 'w')
          {
			key = und;
			DFS_Visit(und, graph);

			comp[key][0]+= 1;
          }
	}
}

void CalculateComponents(node *ptr, long graph[][sz])
{
	if(ptr->forw == NULL)
     {
		for(long und = 1; und <= vert; und++)
		{
			color[und] = 'w';
			par[und] = NULL; 
		}

		return;
     }

	CalculateComponents(ptr->forw, graph);

	if(color[ptr->vert] == 'w')
     {
		key = ptr->vert;
		          
		DFS_Visit(ptr->vert, graph);

		comp[key][0]+= 1;
     }

	return;
}


void PrintFunction(void)
{
	long ind, jnd;

	for(ind = 1; ind <= vert; ind++)
	{

		if(comp[ind][0])
          {
			printf("%ld\t", ind);

			for(jnd = 1; jnd < comp[ind][0]; jnd++)
				printf("%ld\t", comp[ind][jnd]);

			printf("\n");
          }
	}

	return;
}

void StronglyConnectedComponents(void)
{
	strt->forw = new(node);
	ptr = strt->forw;

	printf("the dfs visit on graph are : \n");
	memset(comp, 0, sizeof(comp));
	DFS(mat);

	PrintFunction();
	printf("\n\n");

	ptr->vert = -INF;
	ptr->forw = NULL;

	Flag = 0;

	
	memset(comp, 0, sizeof(comp));
	CalculateComponents(strt->forw, dat);

	printf("the strongly connected components are : \n");
     PrintFunction();
	printf("\n\n");

	return;
}

void main(void)
{
	long ind, jnd, knd, index, query;

	strt = new(node);
	strt->vert = 0;

	while(1)
     {
          Flag = 1;

		scanf("%ld %ld %ld", &vert, &edges, &query);

		if(vert == 0 || edges == 0) break;

		memset(mat, 0, sizeof(mat));
		memset(dat, 0, sizeof(dat));
		
		for(knd = 1; knd <= edges; knd++)
		{
			scanf("%ld %ld", &ind, &jnd);

			index = mat[ind][0]+= 1;

			mat[ind][index] = jnd;

			index = dat[jnd][0]+= 1;

			dat[jnd][index] = ind;
		}

		StronglyConnectedComponents();
     
     }
}
/*

8 14 2

1 2
2 3 2 5 2 6
3 4 3 7
4 3 4 8
5 1 5 6
6 7
7 6 7 8
8 8





*/