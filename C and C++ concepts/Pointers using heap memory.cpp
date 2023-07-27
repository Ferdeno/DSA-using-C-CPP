#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int *p;
	p=(int *)malloc(sizeof(int));//used in C
	//p=new int[5];//used in C++
	p[0]=1;
	p[1]=2;
	p[2]=3;
	p[3]=4;
	p[4]=5;
	for (int i=0;i<5;i++)
		cout<<p[i];
}
