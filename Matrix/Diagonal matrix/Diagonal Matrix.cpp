#include<iostream>
using namespace std;
void set(int A[],int i,int j,int x)
{
	if(i==j)
	{
		A[i-1]=x;
	}
}
int get(int A[],int i,int j)
{
	if(i==j)
		return A[i-1];
	return 0;
}

int main()
{
	int n;
	printf("Enter the dimensions of diagonal matrix : ");
	scanf("%d",&n);
	int A[n],x;
	for(int i=1;i<=n;i++)
	{
		printf("Enter value of the %d row and %d column : ",i,i);
		scanf("%d",&x);
		set(A,i,i,x);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%d ",get(A,i,j));
		}
		printf("\n");
	}
		
}
