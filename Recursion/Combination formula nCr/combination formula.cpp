#include<iostream>
using namespace std;
int fact(long double m)
{
	if(m<=1)
		return 1;
	else
		return fact(m-1)*m;
}
int ncr(long double n,long double r)
{
	long double t1,t2,t3;
	t1=fact(n);
	t2=fact(r);
	t3=fact(n-r);
	return t1/(t2*t3);
}
int main()
{
	cout<<ncr(978,978);
}
