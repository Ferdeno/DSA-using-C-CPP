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
		sparse operator+(sparse &s);
		friend istream & operator>>(istream &is,sparse &s);
		friend ostream & operator<<(ostream &os,sparse &s);
};
		sparse sparse::operator+(sparse &s)
		{
			if(m!=s.m ||n!=s.n)
			{
				return sparse(0,0,0);
			}
			int i,j,k;
			sparse *sum=new sparse(m,n,num+s.num);
			i=j=k=0;
			while(i<num && j<s.num)
			{
				if(e[i].i<s.e[j].i)
				{
					sum->e[k++]=e[i++];
				}
				else if(e[i].i>s.e[j].i)
				{
					sum->e[k++]=s.e[j++];
				}
				else if(e[i].j<s.e[j].j)
				{
					sum->e[k++]=e[i++];
				}
				else if(e[i].j>s.e[j].j)
				{
					sum->e[k++]=s.e[j++];
				}
				else
				{
					sum->e[k]=e[i];
					sum->e[k++].x=e[i++].x+s.e[j++].x;
				}
			}
			for(;i<num;i++)
			{
				sum->e[k++]=e[i];
			}
			for(;j<s.num;j++)
			{
				sum->e[k++]=s.e[j];
			}
			sum->num=k;
			return *sum;
		}
		
		
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
	sparse s1(3,3,3);
	sparse s2(3,3,3);
	cin>>s1;
	cin>>s2;
	sparse sum=s1+s2;
	cout<<"First Matrix : "<<endl<<s1;
	cout<<"Second Matrix : "<<endl<<s2;
	cout<<"Sum Matrix : "<<endl<<sum;
	
}
