#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

#include <iostream>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <utility>

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cassert>
#include <complex>


using namespace std;

#define MIN(A, B) (((A) < (B)) ? (A) : (B))
#define MAX(A, B) (((A) > (B)) ? (A) : (B))
#define EPS 1e-7
#define Pi 3.14159265358979323846

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;


#define SZ 100//0009

__int64 n,m,a[SZ],res[SZ];

int main()
{
	__int64 i,j,prevMax,s,t;
    while(scanf("%I64d %I64d", &m, &n) == 2)
    {

		for(i=0;i<n;i++)
		{
            scanf("%I64d", &a[i]);
		}
        memset(res, 0, sizeof(res));
       
		for(i=0;i<m;i++)
        {
            s = 0;
            prevMax = 0;
       
			for(j=0;j<i;j++)
			{
                s += a[j];
			}
            if(i)
			{
                prevMax = res[i - 1] - s;
			}
            else
			{
                prevMax = 0;
			}
			for(j=i;j<n;j++)
            {
                s += a[j];
                t = res[j] - s;
                if(j > i)
				{
                    res[j] = MAX(res[j - 1], s + prevMax);
				}
                else
				{
                    res[j] = s - prevMax;
				}
                prevMax = MAX(prevMax, t);
            }
        }
        printf("%I64d\n", res[n - 1]);
    }
    return 0;
}
/*


3 5
2
3
4
-1
5
output:
14

5=number of input;
m=number of part;

*/