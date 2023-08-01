#include<iostream>
using namespace std;
int A[]={11,23,36,45,53,68,79,81,90,99};
int BinarySearch(int key)//iterative search
{
	int low,high;
	low=0;
	high=sizeof(A)/sizeof(int) -1;
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(key==A[mid])
			return mid;
		else if(key>A[mid])
			low=mid+1;
		else
			high=mid-1;
	}
	return -1;
}
int RBinarySearch(int low,int high,int key)//Recursive search
{
	int mid=(low+high)/2;
	if(low<=high)
		if(key==A[mid])
			return mid;
		else if(key>A[mid])
			return RBinarySearch(mid+1,high,key);
		else
			return RBinarySearch(low,mid-1,key);
	return -1;
		
}
int main()
{
	//cout<<BinarySearch(991);
	cout<<RBinarySearch(0,10,9);
	return 0;
}
