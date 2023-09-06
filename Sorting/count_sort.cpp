#include<iostream>
using namespace std;

int FindMax(int A[],int n)
{
	int max=-9999;
	int i;
	for(i=0;i<n;i++)
	{
		if(A[i]>max)
			max=A[i];
	}
	return max;
}

void count_sort(int A[],int n)
{
	int max,i,*C;
	max=FindMax(A,n);
	C=new int[max+1];
	for(i=0;i<max+1;i++)
		C[i]=0;
	for(i=0;i<n;i++)
		C[A[i]]++;
	i=0;
	int j=0;
	while(i<max+1)
	{
		if(C[i]>0)
		{
			A[j++]=i;
			C[i]--;
		}
		else
			i++;
	}
}

int main()
{
	int A[]={6,3,9,10,15,6,8,12,3,6};
	int n=10;
	printf("Count sort\n");
	printf("Before sorting : ");
	for(int i=0;i<n;i++)
		printf("%d ",A[i]);
	count_sort(A,n);
	printf("\nAfter sorting : ");
	for(int i=0;i<n;i++)
		printf("%d ",A[i]);
	
}
