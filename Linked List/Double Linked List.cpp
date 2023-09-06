#include<iostream>
using namespace std;
struct node
{
	struct node *prev;
	int data;
	struct node *next;
}*first=NULL;
//create the double linked list
void create(int A[],int n)
{
	struct node *t,*last;
	first=new node;
	first->data=A[0];
	first->prev=NULL;
	first->next=NULL;
	last=first;
	for(int i=1;i<n;i++)
	{
		t=new node;
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		t->prev=last;
		last=t;
	}
}
//find length of the linked list
int length(struct node *p)
{
	int len=0;
	while(p)
	{
		len++;
		p=p->next;
	}
	return len;
}
//display double linked list
void display(struct node *p)
{
	while(p)
	{
		cout<<p->data<<"->";
		p=p->next;
	}
}
//insert at first for double linked list
void insertatfirst(struct node *p)
{
	int x;
	cout<<"Enter the element to be inserted at first : ";
	cin>>x;
	struct node *t=new node;
	t->data=x;
	t->next=NULL;
	t->next=first;
	first->prev=t;
	first=t;
}
void insertatanypositionexcept0(struct node *p)
{
	int x,y;
	cout<<"Enter the element to be inserted : ";
	cin>>x;
	cout<<"Enter the index except 0 where the element "<<x<<" to be inserted : ";
	cin>>y;
	for(int i=0;i<y-1;i++)
		p=p->next;
	struct node *t=new node;
	t->data=x;
	t->next=p->next;
	t->prev=p;
	if(p->next)//this condition is to inserted element at last of the linked list
		p->next->prev=t;
	p->next=t;
}
//insertion at any position 
void insertatanyposition(struct node *p)
{
	int x,y;
	cout<<"Enter the element to be inserted : ";
	cin>>x;
	cout<<"Enter the index where the element "<<x<<" to be inserted : ";
	cin>>y;
	struct node *t=new node;
	t->data=x;
	if(y==0)
	{
		t->next=NULL;
		t->next=first;
		first->prev=t;
		first=t;
	}
	else
	{
		for(int i=0;i<y-1;i++)
			p=p->next;
		t->next=p->next;
		t->prev=p;
		if(p->next)//this condition is to inserted element at last of the linked list
			p->next->prev=t;
		p->next=t;
	}
}
//delete at first node 
void deleteatfirst(struct node *p)
{
	first=first->next;
	delete p;
	if(first)//this condition is to check the first is pointing to a node 
		first->prev=NULL;
}
//delete at any position except 0
void deleteatanypositionexcept0(struct node *p)
{
	int x,y;
	cout<<"Enter the index to be deleted : ";
	cin>>y;
	for(int i=0;i<y;i++)
		p=p->next;
	x=p->data;
	p->prev->next=p->next;
	if(p->next)
		p->next->prev=p->prev;
	delete p;
	cout<<"The deleted element is "<<x<<endl;
}
//delete at any position
void deleteatanyposition(struct node *p)
{
	int x,y;
	cout<<"Enter the index to be deleted : ";
	cin>>y;
	if(y<0 or y>=length(p))
	{
		cout<<"Invalid index";
		return;
	}
	if(y==0)
	{
		first=first->next;
		x=p->data;
		delete p;
		if(first)//this condition is to check the first is pointing to a node 
			first->prev=NULL;
		cout<<"The deleted element is "<<x;
	}
	else
	{
		for(int i=0;i<y;i++)
			p=p->next;
		x=p->data;
		p->prev->next=p->next;
		if(p->next)
			p->next->prev=p->prev;
		delete p;
		cout<<"The deleted element is "<<x<<endl;
	}
}
//reversing the doubly linked list
void reverse(struct node *p)
{
	struct node *t=new node;
	while(p)
	{
		t=p->next;
		p->next=p->prev;
		p->prev=t;
		p=p->prev;
		if(p!=NULL and p->next==NULL)
			first=t;
	}
}
int main()
{
	int A[]={1,2,3,4,5};
	create(A,5);
	cout<<"The length of the linked list : "<<length(first)<<endl;
	display(first);
	cout<<endl;
	/*insertatfirst(first);
	display(first);
	cout<<endl;
	insertatanypositionexcept0(first);
	display(first);
	cout<<endl;
	insertatanyposition(first);
	display(first);
	cout<<endl;
	deleteatfirst(first);
	display(first);
	cout<<endl;
	deleteatanypositionexcept0(first);
	display(first);
	deleteatanyposition(first);
	cout<<endl;
	display(first);*/
	reverse(first);
	cout<<endl;
	display(first);
}
