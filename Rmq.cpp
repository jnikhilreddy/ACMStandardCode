#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>

#include<vector>
#include<queue>
#include<list>
#include<set>
#include<map>

#include<algorithm>
#include<iostream>
#include<sstream>
using namespace std;

#define VS vector<string>
#define VD vector<double>
#define VI vector<int>

#define MAX(aa,bb) (aa>bb?aa:bb)
#define MIN(aa,bb) (aa<bb?aa:bb)


#define PI (2*acos(0.0))

#define PB push_back
#define POB pop_back

#define INF 10009
#define ERR 1e-8
#define CSE 109

void PL()
{
	cout<<endl;
}


void initialize(int node, int b, int e, int M[], int A[], int N)
{
      if (b == e)
          M[node] = b;
      else
       {
  //compute the values in the left and right subtrees
          initialize(2 * node, b, (b + e) / 2, M, A, N);
          initialize(2 * node + 1, (b + e) / 2 + 1, e, M, A, N);
  //search for the minimum value in the first and 
  //second half of the interval
          if (A[M[2 * node]] <= A[M[2 * node + 1]])
              M[node] = M[2 * node];
          else
              M[node] = M[2 * node + 1]; 
	  }
}

int query(int node, int b, int e, int M[], int A[], int i, int j)
{
      int p1, p2;


   
  //if the current interval doesn't intersect 
  //the query interval return -1
      if (i > e || j < b)
          return -1;
   
  //if the current interval is included in 
  //the query interval return M[node]
      if (b >= i && e <= j)
          return M[node];
   
  //compute the minimum position in the 
  //left and right part of the interval
      p1 = query(2 * node, b, (b + e) / 2, M, A, i, j);
      p2 = query(2 * node + 1, (b + e) / 2 + 1, e, M, A, i, j);
   
  //return the position where the overall 
  //minimum is
      if (p1 == -1)
          return M[node] = p2;
      if (p2 == -1)
          return M[node] = p1;
      if (A[p1] <= A[p2])
          return M[node] = p1;
      return M[node] = p2;


}

int main()
{
	int M[CSE],A[CSE],n,i;

	int st,ed,t,r;

	while(scanf("%d",&n)==1 && n)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&A[i]);
		}
		
		
		

		scanf("%d",&t);

		while(t--)
		{
			scanf("%d %d",&st,&ed);
			initialize(1,0,n-1,M,A,n);
			r=query(1,0,n-1,M,A,st,ed);
			printf("Res location %d value %d\n",r,A[r]);
		}
	}

	return 0;
}

/*

10
2 4 3 1 6 7 8 9 1 7
44
2 7





*/
