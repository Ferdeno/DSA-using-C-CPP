#include<iostream>
using namespace std;
int fibi(int n)
{
	if(n<=1)
		return n;
	return fibi(n-2)+fibi(n-1);
}
int main()
{
	cout<<fibi(6);
}
