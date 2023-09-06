#include<iostream>
using namespace std;
class node
{
	public:
		int data;
	 	node *next;
};
class linkedlist
{
	private:
		node *first;
	public:
		linkedlist()
		{
			first=NULL;
		}
		linkedlist(int A[],int n);
		~linkedlist();
		void normaldisplay();
		int normalcount();
};
//creating a linked list
linkedlist::linkedlist(int A[],int n)
{
	struct node *t,*last;
	first=new node;	
	first->data=A[0];
	first->next=NULL;
	last=first;
	for(int i=1;i<n;i++)
	{
		t=new node;
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
}
//normal count
int linkedlist::normalcount()
{
	struct node *p=first;
	int count=0;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	}
	cout<<count;
}
//display
void linkedlist::normaldisplay()
{
	struct node *p=first;
	while(p!=NULL)
	{
		cout<<p->data<<"->";
		p=p->next;
	}
}
linkedlist::~linkedlist()
{
	struct node *p;
	while(first)
	{
		first=first->next;
		delete p;
		p=first;
	}
}
int main()
{
	int A[]={1,2,3,4,5};
	linkedlist l(A,5);
	l.normalcount();
	cout<<endl;
	l.normaldisplay();
}
