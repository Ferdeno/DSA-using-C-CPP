#include<iostream>
using namespace std;
int main()
{
	int *p=new int[5];//creating an array in heap of size 5
	p[0]=1;p[1]=2;p[2]=3;p[3]=4;p[4]=5;
	int *q=new int[10];//creating an array in heap of size 10 
	/*for(int i=0;i<5;i++)
	{
		cout<<p[i];
	}*/
	for(int i=0;i<5;i++)
	{
		q[i]=p[i];//assinging value from p to q i.e changing value from array size 5 to size 10
	}
	/*for(int i=0;i<5;i++)
	{
		cout<<q[i];
	}*/
	//delete [] p;//deleting the array of size 5
	p=q;//making connection p to array q
	q=NULL;//disconnecting the array q 
	for(int i=0;i<5;i++)
	{
		cout<<p[i];
	}
	for(int i=0;i<5;i++)
	{
		cout<<q[i];//This will not get excuted because it there is no data there
	}
	
	
}
