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

list<int> ml;
list<int>::iterator it;
list<string> ls;
list<string>::iterator it1;

int main()
{
	int s;
	s=0;

	ls.push_back("one");
	ls.push_back("two");
	ls.push_back("three");
	
	ls.sort();

	for(it1=ls.begin();it1!=ls.end();it1++)
	{
		cout<<" "<<*it1;
	}
	PL();

	
	ml.push_back(40);
	ml.push_back(12);
	ml.push_back(1);
	ml.push_back(5);
	ml.push_back(12);

	cout<<"Before Sort:";
	for(it=ml.begin();it!=ml.end();it++)
	{
		cout<<" "<<*it;
	}
	PL();

	ml.sort();

	cout<<"After sort:";
	for(it=ml.begin();it!=ml.end();it++)
	{
		cout<<" "<<*it;
	}
	PL();

	while(!ml.empty())
	{
		s+=ml.back();
		ml.pop_back();
	}
	printf("Sum of all elements : %d\n",s);


	//list merge;

	list<int> a,b;

	a.push_back(5);
	a.push_back(1);
	a.push_back(6);
	a.push_back(2);
	a.push_back(2);

	b.push_back(9);
	b.push_back(4);
	b.push_back(3);
	b.push_back(10);
	b.push_back(4);

	a.sort();
	b.sort();

	cout<<"Array A:";
	for(it=a.begin();it!=a.end();it++)
	{
		cout<<" "<<*it;
	}
	PL();
	cout<<"Array B:";
	for(it=b.begin();it!=b.end();it++)
	{
		cout<<" "<<*it;
	}
	PL();

	a.merge(b);



	cout<<"Merge A,B:";
	for(it=a.begin();it!=a.end();it++)
	{
		cout<<" "<<*it;
	}
	PL();

	a.unique();
	cout<<"Remain only unique value:";
	for(it=a.begin();it!=a.end();it++)
	{
		cout<<" "<<*it;
	}
	PL();
	a.reverse();
	cout<<"Reverse:";
	for(it=a.begin();it!=a.end();it++)
	{
		cout<<" "<<*it;
	}
	PL();
	a.clear();
	printf("After clear, Size of a is: %d\n",a.size());

	return 0;
}