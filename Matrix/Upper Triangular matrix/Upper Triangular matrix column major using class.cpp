#include<iostream>
using namespace std;
class Uppertriangle
{
	private:
		int n;
		int *A;
	public:
		Uppertriangle(int n)
		{
			this->n=n;
			A=new int[(n*(n+1))/2];
		}
		void set(int i,int j,int x);
		int get(int i,int j);
		void display();
		~Uppertriangle()
		{
			delete []A;
		}
};
void Uppertriangle::set(int i,int j,int x)
{
	if(i>=j)
		A[i*(i-1)/2+j-1]=x;
}
int Uppertriangle::get(int i,int j)
{
	if(i>=j)
		return A[i*(i-1)/2+j-1];
	return 0;
}
void Uppertriangle::display()
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
	cout<<"Enter the dimension of the Uppertriangle row major matrix : ";
	cin>>temp;
	Uppertriangle d(temp);
	for(int i=1;i<=temp;i++)
	{
		for(int j=i;j<=temp;j++)
		{
			cout<<"Enter the "<<i<<"th row and "<<j<<"th column : ";
			cin>>y;
			d.set(i,j,y);
			//cout<<d.get(i,j)<<endl;	
		}
	}
	d.display();
}
