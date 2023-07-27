#include<iostream>
using namespace std;
void fun(int n)
{
	if(n>0)
	{
		cout<<n;
		return fun(n-1);//calling of function only once is callled linear function
	}	
}
int main()
{
	fun(1);
}
