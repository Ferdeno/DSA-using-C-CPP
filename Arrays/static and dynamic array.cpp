#include<iostream>
using namespace std;
int main()
{
	int a[]={1,2,3,4,5};
	int *p;
	p=new int[5];//creating array in heap memory
	p[0]=5;p[1]=6;p[2]=7;p[3]=8;p[4]=9;p[5]=10;
	for (int i=0;i<5;i++)
	{
		cout<<a[i]<<endl<<p[i]<<endl;
	}
}
