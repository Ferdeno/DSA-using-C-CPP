#include<iostream>
using namespace std;
struct rectangle
{
	int l,b;
};
int main()
{
	struct rectangle r={10,5};
	struct rectangle *p=&r;
	r.l=20;
	r.b=15;
	cout<<r.l<<" ";
	cout<<r.b<<" ";
	(*p).l=30;
	p->b=25;
	cout<<r.l<<" ";
	cout<<r.b<<" ";
	cout<<(*p).l<<" ";
	cout<<p->b<<" ";
}
