#include <bits/stdc++.h>
using namespace std;
double e(int m, int n)
{
	static double s=1;
	if (n==0)
		return s;
	else
		s=1+m*s/n;
		return e(m,n-1);	
}
int main()
{
	cout<<e(4,25);
}
