#include<iostream>
using namespace std;
struct Matrix
{
	int A[10];	
	int n;
}m;
void set(struct Matrix *m,int i,int j,int x)
{
	if(i==j)
	{
		m->A[i-1]=x;
	}
}
int get(struct Matrix m,int i,int j)
{
	if(i==j)
		return m.A[i-1];
	return 0;
}
void display(struct Matrix m)
{
	for(int i=1;i<=m.n;i++)
	{
		for(int j=1;j<=m.n;j++)
		{
			printf("%d ",get(m,i,j));
		}
		printf("\n");
	}
}
int main()
{
	struct Matrix;
	printf("Enter the dimensions of diagonal matrix : ");
	scanf("%d",&m.n);
	int x;
	for(int i=1;i<=m.n;i++)
	{
		printf("Enter value of the %d row and %d column : ",i,i);
		scanf("%d",&x);
		set(&m,i,i,x);
	}
	display(m);
	
		
}
