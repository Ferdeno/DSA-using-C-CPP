#include<iostream>
#include<stdio.h>
using namespace std;
struct Array
{
	int A[10];	
};
void swap(int *x,int *y)//swaping the elements
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
int LinearSearch(struct Array *arr ,int key)//address is passed to change the elements of the array
{
	for(int i=0;i<10;i++)
	{
		if(key==arr->A[i])
		{
			swap(&arr->A[i],&arr->A[i-1]);
			return i;
		}
	}
	return -1;
}
void display(struct Array arr)
{
	for(int i=0;i<10;i++)
	{
		cout<<arr.A[i]<<" ";
	}
}
int main()
{
	struct Array arr={5,4,6,7,8,1,2,9,0,3};
	cout<<LinearSearch(&arr,0)<<"\n";
	display(arr);
	
}
