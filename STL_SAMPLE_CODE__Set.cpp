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

set<int> ms;
set<int>::iterator ii;

int main()
{
	ms.clear();


	ms.insert(100);
	ms.insert(10);
	ms.insert(5);
	ms.insert(15);
	ms.insert(5);
	ms.insert(80);
	ms.insert(99);

	cout<<"List always save data sortedly & uniquily:"<<endl;
	for(ii=ms.begin();ii!=ms.end();ii++)
	{
		cout<<" "<<*ii;
	}
	PL();

	ii=ms.find(15);
	ms.erase(ii);
	ms.erase(ms.find(99));
	cout<<"List always save data sortedly & uniquily:"<<endl;
	for(ii=ms.begin();ii!=ms.end();ii++)
	{
		cout<<" "<<*ii;
	}
	PL();

	for (int i=4;i<8; i++)
	{
		cout << i;
		int yk=ms.count(i);
		if (ms.count(i)>0)
			cout << " is an element of myset.\n";
		else 
			cout << " is not an element of myset.\n";
		cout<<"YK "<<yk<<endl;
	}
	
	return 0;
}