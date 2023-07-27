#include<iostream>
using namespace std;
void g(int *A,int n)//for passing array as parameter we can use int A[] or int *A
{
	for (int i=0;i<n;i++)
	{
		cout<<A[i]<<endl;
	}
}
int main()
{
	int A[]={1,2,3};
	g(A,3);
}

