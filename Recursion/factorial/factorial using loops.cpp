#include<iostream>
using namespace std;
int fact(int n)
{
	int s=1;
	for (int i=1;i<=n;i++)
		s=s*i;
	return s;
}
int main()
{
	cout<<fact(3);
}
