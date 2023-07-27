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
		rectangle(int l,int b);//parameterized constructor
		int area();//facilitators
		int perimeter();//facilitators
		int getlength()//accesser
		{
			return length;
		}
		void setlength(int l)//mutator
		{
			length=l;
		}
		~rectangle();
};
rectangle::rectangle(int l,int b)//scope resolution
{
	length=l;
	breadth=b;
}
int rectangle::area()
{
	return length*breadth;
}
int rectangle::perimeter()
{
	return 2*(length+breadth);
}
rectangle::~rectangle()
{
}
int main()
{
	rectangle r(10,20);
	cout<<r.area()<<endl;
	cout<<r.perimeter()<<endl;
	r.setlength(20);
	cout<<r.getlength()<<endl;
}
