#include <list>

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>

#include<vector>
#include<queue>
#include<map>

#include<algorithm>
#include<iostream>
#include<sstream>
using namespace std;

#define VS vector<string>
#define VD vector<double>
#define VI vector<int>




int main ()
{
	int sum;
	list<int> mylist;
	list<int>::iterator it;

	sum=0;
	mylist.clear();
	mylist.push_back (100);
	mylist.push_back (200);
	mylist.push_back (300);

	mylist.push_front (4);
 
	for(it=mylist.begin();it!=mylist.end();it++)
	{
		cout<<" "<<*it;
	}
	cout<<endl;
	cout<<"After pop"<<endl;
	mylist.pop_front();
	for(it=mylist.begin();it!=mylist.end();it++)
	{
		cout<<" "<<*it;
	}
	mylist.reverse();
	cout<<endl;

	cout<<"After Reverse:"<<endl;
	for(it=mylist.begin();it!=mylist.end();it++)
	{
		cout<<" "<<*it;
	}
	cout<<endl;

	mylist.sort();
	cout<<"After sort:"<<endl;
	for(it=mylist.begin();it!=mylist.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	int l=mylist.size();

	cout<<"List Size "<<l<<endl;

	while (!mylist.empty())
	{
		sum+=mylist.back();
		mylist.pop_back();
	}

	cout << "The elements of mylist summed " << sum << endl;


	double mydoubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14,
                       12.77, 73.35, 72.25, 15.3,  72.25 };
	list<double> ml (mydoubles,mydoubles+10);
	list<double>::iterator itt;
	ml.sort();
	cout<<"After Sort double data"<<endl;
	for(itt=ml.begin();itt!=ml.end();itt++)
	{
		cout<<*itt<<" ";
	}cout<<endl;
	ml.unique();
	cout<<"After Remove repeate data: "<<endl;
	for(itt=ml.begin();itt!=ml.end();itt++)
	{
		cout<<*itt<<" ";
	}cout<<endl;

	return 0;
}
