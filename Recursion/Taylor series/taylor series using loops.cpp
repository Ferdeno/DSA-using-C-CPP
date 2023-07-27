#include <bits/stdc++.h>
using namespace std;
double e(int m, int n)
{
	double s=1;
	for (;n>0;n--)
		s=1+ m*s/n ;
	return s;	
}
int main()
{
	cout<<e(1,10);
}
