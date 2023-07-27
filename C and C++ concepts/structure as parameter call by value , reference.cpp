#include<iostream>
using namespace std;
struct rectangle
{
	int l,b;
};
int area(struct rectangle r)
{
	r.l++;//trying to update 
	return r.l*r.b;
}
int main()
{
	struct rectangle r={10,5};
	cout<<area(r)<<endl;
	cout<<r.l<<" "<<r.b;	
}
