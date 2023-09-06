#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
}*head;
//creating a circular linked list
void create(int A[],int n)
{
	struct node *t,*last;
	head=new node;//to create memory in heap C++
	//head=(struct node *)malloc(sizeof(struct node));//to create memory in heap C
	head->data=A[0];
	head->next=head;
	last=head;	
	for(int i=1;i<n;i++)
	{
		t=new node;
		t->data=A[i];
		t->next=last->next;
		last->next=t;
		last=t;
	}
}
//normal display circular linked list
void normaldisplay(struct node *p)
{
	do
	{
		cout<<p->data<<"->";
		p=p->next;
	}while(p!=head);
}
//recursive display circular linked list
//int flag=0;//global variable
void recursivedisplay(struct node *p)
{
	static int flag=0;//instead of creating static flag creating global flag can be also used
	if(p!=head || flag==0)
	{
		flag=1;
		cout<<p->data<<"->";
		recursivedisplay(p->next);
	}	
}
//insertion at any position except zero circular linked list 
void insertionatanypositionexcept0(struct node *p)
{
	int x,y;
	cout<<"Enter the element to be inserted : ";
	cin>>x;
	cout<<"Enter the index except 0 where the element "<<x<<" to be inserted : ";
	cin>>y;
	for(int i=0;i<y-1;i++)
	{
		p=p->next;
	}
	struct node *t;
	t=new node;
	t->data=x;
	t->next=p->next;
	p->next=t;
}
//insertion at zero circular linked list
void insertionatzeroposition(struct node *p)
{
	int x;
	cout<<"Enter the element to be inserted at first position : ";
	cin>>x;
	while(p->next!=head)
	{
		p=p->next;
	}
	struct node *t=new node;
	t->data=x;
	t->next=head;
	p->next=t;
	head=t;
}
//insertion at any position 
void insertionatanyposition(struct node *p)
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
		while(p->next!=head)
		{
			p=p->next;
		}
		t->next=head;
		p->next=t;
		head=t;
	}
	else
	{
		for(int i=0;i<y-1;i++)
		{
			p=p->next;
		}
		t->next=p->next;
		p->next=t;
	}
}
//delete at any postition except at first node 
void deleteatanypositionexceptfirstnode(struct node *p)
{
	int index;
	cout<<"Enter the index of the element to be deleted : ";
	cin>>index;
	for(int i=0;i<index-1;i++)
	{
		p=p->next;
	}
	struct node *q=p->next;
	p->next=q->next;
	cout<<"The deleted element is "<<q->data<<endl;
	delete q;
}
//delete at head node method 1
void deleteatfirst1(struct node *p)
{
	do
	{
		p=p->next;
	}while(p->next!=head);
	//struct node *q=p->next;
	p->next=head->next;
	cout<<endl<<"The delete element at head : "<<head->data<<endl;
	delete head;
	head=p->next;
}
//delete at head node method 2
void deleteatfirst2(struct node *p)
{
	while(p->next!=head)
		p=p->next;
	p->next=head->next;
	cout<<endl<<"The delete element at head : "<<head->data<<endl;
	delete head;
	head=p->next;
}
//delete at any position 
void deleteatanyposition(struct node *p)
{
	int index;
	cout<<"Enter the index of the element to be deleted : ";
	cin>>index;
	if(index==0)
	{
		if(p->next==head)
		{//if the list has only one element in it this condition is used 
			cout<<endl<<"The delete element at head : "<<head->data<<endl;
			delete head;
			head=NULL;
		}
		else
		{
			while(p->next!=head)
			p=p->next;
			p->next=head->next;
			cout<<endl<<"The delete element at head : "<<head->data<<endl;
			delete head;
			head=p->next;
		}
	}
	else
	{
		for(int i=0;i<index-1;i++)
		{
			p=p->next;
		}
		struct node *q=p->next;
		p->next=q->next;
		cout<<"The deleted element is "<<q->data<<endl;
		delete q;
	}
}
int main()
{
	int A[]={1,2,3,4,5};
	create(A,5
	);
	recursivedisplay(head);
	cout<<endl;
	/*insertionatanypositionexcept0(head);
	normaldisplay(head);
	cout<<endl;
	insertionatzeroposition(head);
	normaldisplay(head);
	cout<<endl;
	insertionatanyposition(head);
	normaldisplay(head);
	deleteatanypositionexceptfirstnode(head);
	normaldisplay(head);
	deleteatfirst1(head);
	normaldisplay(head);
	deleteatfirst2(head);
	normaldisplay(head);*/
	deleteatanyposition(head);
	normaldisplay(head);
}
