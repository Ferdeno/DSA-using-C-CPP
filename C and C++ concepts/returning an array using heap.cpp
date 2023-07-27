#include<iostream>
using namespace std;
int * g(int n)
{
	int *p;
	p=new int[n];
	return p;
}
int main()
{
	int *a;
	a=g(5);
}
