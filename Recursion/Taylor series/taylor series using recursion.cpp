#include <bits/stdc++.h>
using namespace std;
double e(int m, int n)
{
	static double  p=1,f=1;
	double r;	
	if(n==0)
		return 1;
	else
		r=e(m,n-1);
		p=p*m;
		f=f*n;
		return r+p/f;
}
int main()
{
	int m,n;
	cout<<e(4,25);
}
