#include<iostream>
using namespace std;
struct term
{
	int coeff;
	int exp;
}t;
struct poly
{
	int n;
	struct term *t;
}p;
void create(struct poly *p)
{
	cout<<"Enter the count of non zero elements : ";
	cin>>p->n;
	p->t=new term[p->n];
	for(int i=0;i<p->n;i++)
	{
		cout<<"Enter the coefficient and exponential of element "<<i+1<<" : ";
		cin>>p->t[i].coeff>>p->t[i].exp;
	}
}
void display(struct poly p)
{
	for(int i=0;i<p.n;i++)
	{
		cout<<p.t[i].coeff<<"X"<<p.t[i].exp<<" + ";
	}
}
struct poly *add(struct poly *p1,struct poly *p2)
{
	int i,j,k;
	i=j=k=0;
	struct poly *sum;
	sum=new poly[p1->n+p2->n];
	sum->t=new term[p1->n+p2->n];
	while(i<p1->n && j<p2->n)
	{
		if(p1->t[i].exp>p2->t[j].exp)
		{
			sum->t[k++]=p1->t[i++];
		}
		else if (p1->t[i].exp<p2->t[j].exp)
		{
			sum->t[k++]=p2->t[j++];
		}
		else
		{
			sum->t[k].exp=p1->t[i].exp;
			sum->t[k++].coeff=p1->t[i++].coeff+p2->t[j++].coeff;
		}
	}
	for(;i<p1->n;i++)
	{
		sum->t[k++]=p1->t[i];
	}
	for(;j<p2->n;j++)
	{
		sum->t[k++]=p2->t[j];
	}
	sum->n=k;
	return sum;
}

int main()
{
	struct poly p1,p2,*p3;
	create(&p1);
	create(&p2);
	p3=add(&p1,&p2);
	cout<<"Polynomial 1 : ";
	display(p1);
	cout<<endl;
	cout<<"Polynomial 2 : ";
	display(p2);
	cout<<endl;
	cout<<"Addtion of Polynomial : ";
	display(*p3);
}
