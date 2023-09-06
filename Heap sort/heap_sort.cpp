#include<iostream>
using namespace std;

void insert(int A[],int n)
{
	int temp,i=n;
	temp=A[i];
	while(i>1 && temp>A[i/2])
	{
		A[i]=A[i/2];
		i=i/2;
	}
	A[i]=temp;
}

int delete_element(int A[],int n)
{
	int i,j,x,temp,val=A[1];
	x=A[n];
	A[1]=A[n];
	i=1;
	j=2*i;
	while(j<n-1)
	{
		if(A[j+1]>A[j])
			j+=1;
		if(A[i]<A[j])
		{
			temp=A[i];
			A[i]=A[j];
			A[j]=temp;
			i=j;
			j*=2;
		}
		else
			break;
	}
	A[n]=val;
	return val;
}
int main()
{
	int A[]={0,10,20,30,25,5,40,35};
	//here index 2 is taken in loop because the index 0 is null and index 1 is root of binary heap 
	//so from index 2 the loop starts
	
	for(int i=2;i<=7;i++)
		insert(A,i);
	for(int i=1;i<=7;i++)
		printf("Element %d : %d\n",i,A[i]);
	
	for(int i=7;i>1;i--)
		delete_element(A,i);
	printf("\n");
	for(int i=1;i<=7;i++)
		printf("Element %d : %d\n",i,A[i]);
}
