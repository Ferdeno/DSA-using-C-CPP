#include<iostream>
using namespace std;
class Diagonal
{
	private:
		int n;
		int *A;
	public:
		Diagonal(int n)
		{
			this->n=n;
			A=new int[n];
		}
		void set(int i,int j,int x);
		int get(int i,int j);
		void display();
		~Diagonal()
		{
			delete []A;
		}
};
void Diagonal::set(int i,int j,int x)
{
	if(i==j)
		A[j-1]=x;
}
int Diagonal::get(int i,int j)
{
	if(i==j)
		return A[j-1];
	return 0;
}
void Diagonal::display()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",get(i,j));
		}
		cout<<endl;
	}	
}
int main()
{
	int temp,y;
	cout<<"Enter the dimension of the diagonal matrix : ";
	cin>>temp;
	Diagonal d(temp);
	for(int i=0;i<temp;i++)
	{
		cout<<"Enter the "<<i+1<<"th row and "<<i+1<<"th column : ";
		cin>>y;
		d.set(i,i,y);
		cout<<d.get(i,i)<<endl;	
	}
	d.display();
}
