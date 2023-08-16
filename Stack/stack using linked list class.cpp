#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node *next;
};
class stack
{
	private:
		node *top;
	public:
		stack()
		{
			top=NULL;
		}
		void push();
		void pop();
		void peek();
		void stacktop();
		void display();
};
void stack::push()
{
	struct node *t=new node;
	if(t==NULL)
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
void stack::pop()
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
void stack::peek()
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
void stack::stacktop()
{
	if(top==NULL)
	{
		cout<<"Stack underflow"<<endl;
		return;
	}
	cout<<"The stack top is "<<top->data<<endl;
}
void stack::display()
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
	stack stk;
	cout<<"Stack using linked list"<<endl;
	int ch;
	do
	{
		cout<<"1.push\n2.pop\n3.peek\n4.stack top\n5.Display\n6.exit\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				stk.push();
				break;
			case 2:
				stk.pop();
				break;
			case 3:
				stk.peek();
				break;
			case 4:
				stk.stacktop();
				break;
			case 5:
				stk.display();
				break;
			case 6:
				exit(1);
			default:
				cout<<"Invalid choice "<<endl;
		}
	}while(true);	
}
