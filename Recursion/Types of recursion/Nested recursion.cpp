#include<iostream>
using namespace std;
int fun(int n)
{
	if(n>0)
	{
		cout<<n<<endl;
		return fun(fun(n-1));
	}	
}
int main()
{
	cout<<fun(10);
}
