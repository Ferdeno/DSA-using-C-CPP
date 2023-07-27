#include<iostream>
using namespace std;
template<class t>
class maths
{
	private:
		t a;
		t b;
	public:
		maths(t a,t b);
		t add();
		t sub();
};
template <class t>
maths<t>::maths(t a,t b)
{
	this->a=a;
	this->b=b;
}
template <class t>
t maths<t>::add()
{
	return a+b;
}
template <class t>
t maths<t>::sub()
{
	return a-b;
}
int main()
{
	maths <int> m(10,20);
	cout<<m.add()<<endl;
	cout<<m.sub()<<endl;
	maths<float>n(1.5,1.7);
	cout<<n.add()<<endl;
	cout<<n.sub()<<endl;
}
