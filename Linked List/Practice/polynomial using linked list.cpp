#include<iostream>
#include<math.h>
using namespace std;
struct node 
{
	int coeff;
	int expo;
	struct node *next;
}*poly1=NULL,*poly2=NULL;
void create1()
{
	struct node *t,*last=NULL;
	int n;
	cout<<"Polynomial 1 :"<<endl;
	cout<<"Enter the count of non zero elements : ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		t=new node;
		cout<<"Enter the coefficient and exponential of element "<<i+1<<" : ";
		cin>>t->coeff>>t->expo;
		t->next=NULL;
		if(poly1==NULL)
		{
			poly1=last=t;
		}
		else
		{
			last->next=t;
			last=t;
		}
	}
}
void create2()
{
	struct node *t,*last=NULL;
	int n;
	cout<<endl<<"Polynomial 2 :"<<endl;
	cout<<"Enter the count of non zero elements : ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		t=new node;
		cout<<"Enter the coefficient and exponential of element "<<i+1<<" : ";
		cin>>t->coeff>>t->expo;
		t->next=NULL;
		if(poly2==NULL)
		{
			poly2=last=t;
		}
		else
		{
			last->next=t;
			last=t;
		}
	}
}
void display(struct node *p)
{
	while(p)
	{
		cout<<p->coeff<<"X"<<p->expo<<" + ";
		p=p->next;
	}
}
int eval(struct node *p)
{
	int x,sum=0;
	cout<<endl<<"Enter the value for X : ";
	cin>>x;
	while(p)
	{
		sum+=p->coeff*pow(x,p->expo);
		p=p->next;
	}
	return sum;
}
struct node *add(struct node *p1,struct node *p2,struct node *p3)
{
	struct node *temp,*last=NULL;
	while(p1&&p2)
	{
		temp=new node;
		if(p1->expo==p2->expo)
		{
			temp->coeff=p1->coeff+p2->coeff;
			temp->expo=p1->expo;
			temp->next=NULL;
			p1=p1->next;
			p2=p2->next;
			if(p3==NULL)
				p3=last=temp;
			else
			{
				last->next=temp;
				last=temp;
			}
		}
		else if(p1->expo>p2->expo)
		{
			temp->coeff=p1->coeff;
			temp->expo=p1->expo;
			temp->next=NULL;
			p1=p1->next;
			if(p3)
			{
				last->next=temp;
				last=temp;
			}
			else
				p3=last=temp;
		}
		else
		{
			temp->coeff=p2->coeff;
			temp->expo=p2->expo;
			temp->next=NULL;
			p2=p2->next;
			if(p3)
			{
				last->next=temp;
				last=temp;
			}
			else
				p3=last=temp;
		}
	}
	if(p1)
	{
		temp=new node;
		while(p1)
		{
			temp->coeff=p1->coeff;
			temp->expo=p1->expo;
			temp->next=NULL;
			p1=p1->next;
			if(p3)
			{
				last->next=temp;
				last=temp;
			}
			else
				p3=last=temp;
		}
	}
	if(p2)
	{
		temp=new node;
		while(p2)
		{
			temp->coeff=p2->coeff;
			temp->expo=p2->expo;
			temp->next=NULL;
			p2=p2->next;
			if(p3)
			{
				last->next=temp;
				last=temp;
			}
			else
				p3=last=temp;
		}
	}
	return p3;
	
}
int main()
{
	int temp;
	create1();
	display(poly1);
	//temp=eval(poly1);
	//cout<<"The value of the polynomial equation is : "<<temp;
	create2();
	display(poly2);
	struct node *p3;
	p3=add(poly1,poly2,p3);
	display(p3);
	

}
