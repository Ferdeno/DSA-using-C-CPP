#include<iostream>
using namespace std;
void fun(int n)
{
	if(n>0)
	{
		cout<<n;
		fun(n-1);//when a function is called two or more times then it is called tree recursion
		fun(n-1);
	}	
}
int main()
{
	fun(3);
}
