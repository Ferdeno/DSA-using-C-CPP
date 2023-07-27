#include<iostream>
using namespace std;
int main()
{
	int a=10;
	int &r=a;
	cout<<a<<" ";
	cout<<r<<" ";
	r++;
	cout<<a<<" ";
	cout<<r<<" ";
	a++;
	cout<<a<<" ";
	cout<<r<<" ";
	
}
