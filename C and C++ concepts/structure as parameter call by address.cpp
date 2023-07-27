#include<iostream>
using namespace std;
struct rectangle 
{
	int l,b;
};
void changelength(struct rectangle *P,int N)
{
	P->l=N;
}
int main()
{
	struct  rectangle r={10,5};
	cout<<r.l<<" "<<r.b<<endl;
	changelength(&r,15);
	cout<<r.l<<" "<<r.b;
}
