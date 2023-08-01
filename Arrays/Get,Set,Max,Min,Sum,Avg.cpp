#include<iostream>
using namespace std;
int A[]={52,43,76,45,13,64,29,81,19,9};
int get(int index)
{
	if(index>=0 && index<10)
		return A[index];
}
void set(int index,int x)
{
	if(index>=0 && index<10)
		A[index]=x;
}
int max()
{
	int max=A[0];
	for(int i=0;i<10;i++)
	{
		if(max<A[i])
			max=A[i];
	}
	return max;
}
int min()
{
	int min=A[0];
	for(int i=0;i<10;i++)
	{
		if(min>A[i])
			min=A[i];
	}
	return min;
}
int sum()
{
	int total=0;
	for(int i=0;i<10;i++)
	{
		total+=A[i];
	}
	return total;
}
int recursionsum(int n)
{
	if(n<0)
		return 0;
	else
		return recursionsum(n-1)+A[n];
}
float avg()
{
	return (float)sum()/10;
}
int main()
{
	cout<<get(8)<<endl;
	set(8,9);
	cout<<get(8)<<" "<<max()<<" "<<min()<<" "<<endl;
	cout<<sum()<<" "<<recursionsum(10)<<" "<<avg();
	
}
