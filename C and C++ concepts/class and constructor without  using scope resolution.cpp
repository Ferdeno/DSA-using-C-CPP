#include<iostream>
using namespace std;
class rectangle
{
	private:
		int length;
		int breadth;
	public:
		rectangle()//default constructor 
		{
			length=0;
			breadth=0;
		}
		rectangle(int l,int b)//parameterized constructor
		{
			length=l;
			breadth=b;
		}
		int area()//facilitators
		{
			return length*breadth;
		}
		int perimeter()//facilitators
		{
			return 2*(length+breadth);
		}
		int getlength()//accesser
		{
			return length;
		}
		void setlength(int l)//mutator
		{
			length=l;
		}
};
int main()
{
	rectangle r(10,20);
	cout<<r.area()<<endl;
	cout<<r.perimeter()<<endl;
	r.setlength(20);
	cout<<r.getlength()<<endl;
}
