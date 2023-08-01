#include<iostream>
using namespace std;
class Lowertriangle
{
	private:
		int n;
		int *A;
	public:
		Lowertriangle(int n)
		{
			this->n=n;
			A=new int[(n*(n+1))/2];
		}
		void set(int i,int j,int x);
		int get(int i,int j);
		void display();
		~Lowertriangle()
		{
			delete []A;
		}
};
void Lowertriangle::set(int i,int j,int x)
{
	if(i>=j)
		A[(i*(i-1))/2+(j-1)]=x;
}
int Lowertriangle::get(int i,int j)
{
	if(i>=j)
		return A[(i*(i-1))/2+(j-1)];
	return 0;
}
void Lowertriangle::display()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%d ",get(i,j));
		}
		cout<<endl;
	}	
}
int main()
{
	int temp,y;
	cout<<"Enter the dimension of the Lowertriangle row major matrix : ";
	cin>>temp;
	Lowertriangle d(temp);
	for(int i=1;i<=temp;i++)
	{
		for(int j=1;j<=i;j++)
		{
			cout<<"Enter the "<<i<<"th row and "<<j<<"th column : ";
			cin>>y;
			d.set(i,j,y);
			//cout<<d.get(i,j)<<endl;	
		}
	}
	d.display();
}
