#include<iostream>
using namespace std;
void merge(int a[],int b[])
{
	int i=0,j=0,k=0,c[10];
	while(i<5&&j<5)
	{
		if(a[i]>b[j])
			c[k++]=b[j++];
		else
			c[k++]=a[i++];
	}
	for(;i<5;i++)
		c[k++]=a[i];
	for(;j<5;j++)
		c[k++]=b[j];
	for(int x=0;x<10;x++)
		cout<<c[x]<<" ";
}
int main()
{
	int a[]={1,5,55,65,78};
	int b[]={8,12,32,44,75};
	merge(a,b);
}
