#include<iostream>
using namespace std;
int f[10];
int fib(int n)
{
	if(n<=1)
	{
		f[n]=n;
		return n;
	}
	else 
	{
		if(f[n]==-1)
			f[n-2]=fib(n-2);
		if(f[n]==-1)
			f[n-1]=fib(n-1);
		f[n]=fib(n-2)+fib(n-1);
		return fib(n-2)+fib(n-1);
	}
}
int main()
{
	cout<<fib(10);
}
