#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class BadNeighbors 
{
	int max(int a,int b)
	{
		if(a>b)
		{
			return a;
		}
		
		return b;
	}
public:
	int BadNeighbors::maxDonations(vector <int> donations) 
	{
		int n,sz,dp[51],ma;
		sz=donations.size();
		dp[0]=donations[0];
		dp[1]=donations[0];

		for(n=2;n<sz-1;n++)
		{
			dp[n]=max(donations[n]+dp[n-2],dp[n-1]);
		}
		ma=dp[sz-2];

		dp[0]=0;
		dp[1]=donations[1];
		for(n=2;n<sz;n++)
		{
			dp[n]=max(donations[n]+dp[n-2],dp[n-1]);
		}
		return max(ma,dp[sz-1]);
	
		return 0;
	}
};


double test0() {
	int t0[] =  { 10, 3, 2, 5, 7, 8 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	BadNeighbors * obj = new BadNeighbors();
	clock_t start = clock();
	int my_answer = obj->maxDonations(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 19;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = { 11, 15 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	BadNeighbors * obj = new BadNeighbors();
	clock_t start = clock();
	int my_answer = obj->maxDonations(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 15;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = { 7, 7, 7, 7, 7, 7, 7 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	BadNeighbors * obj = new BadNeighbors();
	clock_t start = clock();
	int my_answer = obj->maxDonations(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 21;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	BadNeighbors * obj = new BadNeighbors();
	clock_t start = clock();
	int my_answer = obj->maxDonations(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 16;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int t0[] = { 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,    6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,  52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	BadNeighbors * obj = new BadNeighbors();
	clock_t start = clock();
	int my_answer = obj->maxDonations(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2926;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
