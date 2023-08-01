#include<iostream>
using namespace std;
int main()
{
	int **a;
	a=new int*[2];//created in heap memory
	a[0]=new int[5];//created in heap memory
	a[1]=new int[5];//created in heap memory
	for (int i=0;i<2;i++)
	{
		for (int j=0;j<5;j++)
		{
			cin>>a[i][j];
		}
	}
	for (int i=0;i<2;i++)
	{
		for (int j=0;j<5;j++)
		{
			cout<<a[i][j]<<endl;
		}
	}
}
