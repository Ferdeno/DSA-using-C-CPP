#include<iostream>
using namespace std;
class element
{
	public:
		int i,j,x;
	
};
class sparse
{
	private:
		int m,n,num;
		element *e;
	public:
		sparse(int m,int n,int num)
		{
			this->m=m;
			this->n=n;
			this->num=num;
			e=new element[this->num];
		}
		~sparse()
		{
			delete []e;
		}
		friend istream & operator>>(istream &is,sparse &s);
		friend ostream & operator<<(ostream &os,sparse &s);
};
		istream & operator>>(istream &is,sparse &s)
		{
			for(int i=0;i<s.num;i++)
			{
				cout<<"Enter the row column value "<<i+1<<" : ";
				cin>>s.e[i].i>>s.e[i].j>>s.e[i].x;
			}
			return is;
		}
		ostream & operator<<(ostream &os,sparse &s)
		{
			int k=0;
			for(int i=0;i<s.m;i++)
			{
				for(int j=0;j<s.n;j++)
				{
					if(s.e[k].i==i && s.e[k].j==j)
					{
						cout<<s.e[k++].x<<" ";
					}
					else
					{
						cout<<"0 ";
					}
				}
				cout<<endl;
			}
			return os;	
		}

int main()
{
	sparse s1(5,5,5);
	cin>>s1;
	cout<<s1;
}
