#include<iostream>
using namespace std;
int main()
{
	int *a[2];//this 2D array is created as pointer in stack
	a[0]=new int[5];//this rows and columns are created inside heap
	a[1]=new int[5];//this rows and columns are created inside heap
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
