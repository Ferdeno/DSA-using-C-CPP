#include<iostream>
using namespace std;
struct Matrix
{
	int *A;	
	int n;
}m;
void set(struct Matrix *m,int i,int j,int x)
{
	if(i>=j)
	{
		m->A[((m->n*(j-1))-((j-2)*(j-1))/2)+(i-j)]=x;
	}
}
int get(struct Matrix m,int i,int j)
{
	if(i>=j)
		return m.A[((m.n*(j-1))-((j-2)*(j-1))/2)+(i-j)];
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
	printf("Enter the dimensions of Lower Triangle Column major matrix : ");
	scanf("%d",&m.n);
	m.A=new int((m.n*(m.n+1))/2);
	int x;
	for(int i=1;i<=m.n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			printf("Enter value of the %d row and %d column : ",i,j);
			scanf("%d",&x);
			set(&m,i,j,x);
		}
	}
	display(m);
	
		
}
