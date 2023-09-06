#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
}*front=NULL,*rear=NULL;
void enqueue()
{
	struct node *t=new node;
	if(!t)//check new node can be created or not
	{
		cout<<"Heap memory is full or queue is full"<<endl;
		return;
	}
	else
	{
		cout<<"Enter element : ";
		cin>>t->data;
		t->next=NULL;
		if(front==NULL)//insertion of first node with the queue is empty
			front=rear=t;
		else
		{
			rear->next=t;
			rear=t;
		}
	}
}
void dequeue()
{
	if(front==NULL)//queue empty condition
	{
		cout<<"Queue underflow"<<endl;
		return;
	}
	node *p;
	p=front;
	front=front->next;
	cout<<"The deleted element is : "<<p->data<<endl;
	delete p;
}
void display()
{
	if(front==NULL)
		cout<<"Queue underflow"<<endl;
	else
	{
		node *p;
		p=front;
		while(p)
		{
			cout<<p->data<<" ";
			p=p->next;
		}
		cout<<endl;
	}
}
int main()
{
	int ch;
	cout<<"\tQUEUE USING Linkedlist"<<endl;
	do
	{
		cout<<"1.Enqueue \n2.Dequeue \n3.Display\n4.Exit\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default :
				cout<<"Invalid option "<<endl;
				break;
		}
	}while(ch!=4);
}






