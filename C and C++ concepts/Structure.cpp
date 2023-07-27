#include<iostream>
using namespace std;
struct rectangle
{
	int l,b;
};
int main()
{
	struct rectangle r;
	r={10,5};
	cout<<r.l<<r.b;
}
