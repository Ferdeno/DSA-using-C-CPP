#include<iostream>
#include<stdlib.h>
using namespace std;
struct rectangle
{
	int l,b;
};
int main()
{
	struct rectangle r;
	struct rectangle *p;
	p=(struct rectangle *)malloc(sizeof(struct rectangle));
	p->l=20;
	p->b=15;
	cout<<p->l<<" "<<p->b;
}
