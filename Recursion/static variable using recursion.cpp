#include<iostream>
using namespace std;
int y=0;
int fun(int n)
{
	int static y=0;
	if(n>0)
	{
		y++;
		return fun(n-1)+y;
	}
}
int main()
{
	int x=5;
	cout<<fun(x);
}
