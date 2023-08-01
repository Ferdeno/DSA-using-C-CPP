#include<iostream>
using namespace std;
int main()
{
	int a[2][5]={{1,2,3,4,5},{6,7,8,9,10}};//this 2D array is created in stack
	for (int i=0;i<2;i++)
	{
		for (int j=0;j<5;j++)
		{
			cout<<a[i][j]<<endl;
		}
	}
}
