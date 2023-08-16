#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
}*top=NULL;
void push()
{
	struct node *t=new node;
	if(t==NULL)/*this condition is to check whether the heap memory is full or not 
	that is if the heap memory is full new node will not be created then t will be NULL*/
	{
		cout<<"Stack Overflow"<<endl;
		return;
	}
	else
	{
		cout<<"Enter the element : ";
		cin>>t->data;
		t->next=top;
		top=t;
	}
}
void pop()
{
	if(top==NULL)
	{
		cout<<"Stack underflow"<<endl;
		return;
	}
	else
	{
		cout<<"The poped element is "<<top->data<<endl;
		node *t=new node;
		t=top;
		top=top->next;
		delete t;
	}
}
void peek()
{
	int i,p;
	cout<<"Enter the peek value : ";
	cin>>p;
	struct node *t=new node;
	t=top;
	for(i=0;i<p;i++)
	{
		if(t==NULL)
		{
			cout<<"The peek value is invalid"<<endl;
			return;
		}
		t=t->next;
	}
	if(t)
		cout<<"The peek value is "<<t->data<<endl;
	else
		cout<<"The peek value is invalid"<<endl;
}
void stacktop()
{
	if(top==NULL)
	{
		cout<<"Stack underflow"<<endl;
		return;
	}
	cout<<"The stack top is "<<top->data<<endl;
}
void display()
{
	if(top==NULL)
	{
		cout<<"Stack underflow"<<endl;
		return;
	}
	struct node *t=new node;
	t=top;
	while(t)
	{
		cout<<t->data<<" ";
		t=t->next;
	}
	cout<<endl;
}
int main()
{
	cout<<"Stack using linked list"<<endl;
	int ch;
	do
	{
		cout<<"1.push\n2.pop\n3.peek\n4.stack top\n5.Display\n6.exit\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			case 4:
				stacktop();
				break;
			case 5:
				display();
				break;
			case 6:
				exit(1);
			default:
				cout<<"Invalid choice "<<endl;
		}
	}while(true);
		
	
}
