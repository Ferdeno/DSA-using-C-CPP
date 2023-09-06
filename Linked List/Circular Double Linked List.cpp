#include<iostream>
using namespace std;
struct node
{
	struct node *prev;
	int data;
	struct node *next;
}*head=NULL;
//creating a circular double linked list
void create(int A[],int n)
{
	struct node *t,*last;
	head=new node;
	head->data=A[0];
	head->prev=NULL;
	head->next=NULL;
	last=head;
	for(int i=1;i<n;i++)
	{
		t=new node;
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		t->prev=last;
		last=t;
	}
	last->next=head;
	head->prev=last;
}
//normal display of circular double linked list
void display(struct node *p)
{
	do
	{
		cout<<p->data<<"->";
		p=p->next;
	}while(p!=head);
}
//length of the linked list
int length(struct node *p)
{
	int count=0;
	do
	{
		count++;
		p=p->next;
	}while(p!=head);
	return count;
}
void insertion(struct node *p)
{
	int x,y;
	cout<<"Enter the element to be inserted : ";
	cin>>x;
	cout<<"Enter the index where the element "<<x<<" to be inserted : ";
	cin>>y;
	struct node *t=new node;
	t->data=x;
	if(y<0 or y>length(p))
	{
		cout<<"Invalid index";
		return;
	}
	if(y==0)
	{
		t->next=head;
		t->prev=head->prev;
		head->prev=t;
		t->prev->next=t;
		head=t;
	}
	else
	{
		for(int i=0;i<y-1;i++)
			p=p->next;
		t->next=p->next;
		t->prev=p;
		if(p->next)
			p->next->prev=t;
		p->next=t;
	}
}
void deletion(struct node *p)
{
	int x,y;
	cout<<"Enter the index to be deleted : ";
	cin>>y;
	if(y<0 or y>length(p))
	{
		cout<<"Invalid index ";
		return;
	}
	if(y==0)
	{
		head->prev->next=head->next;
		head->next->prev=head->next;
		head=head->next;
		x=p->data;
		delete p;
		cout<<"The deleted element is "<<x;
	}
	else
	{
		for(int i=0;i<y;i++)
			p=p->next;
		p->prev->next=p->next;
		p->next->prev=p->prev;
		x=p->data;
		delete p;
		cout<<"The deleted element is "<<x;
	}
}
int main()
{
	int A[]={1,2,3,4,5};
	create(A,5);
	display(head);
	cout<<endl;
	insertion(head);
	cout<<endl;
	display(head);
	cout<<endl;
	deletion(head);
	cout<<endl;
	display(head);
}
