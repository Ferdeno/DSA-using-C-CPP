#include<iostream>
using namespace std;

struct stack
{
	int size;
	int top=-1;
	int *s;
}st;
bool isfull()
{
	return st.top==st.size-1;
	/*if(st.top==st.size-1)
		return true;
	return false;*/
}
bool isempty()
{
	return st.top==-1;
	/*if(st.top==-1)
		return true;
	return false;*/
}
void push()
{
	if(isfull())
	{
		cout<<"The stack is full "<<endl;
	}
	else
	{
		int temp;
		cout<<"Enter the element to be pushed : ";
		cin>>temp;
		st.top++;
		st.s[st.top]=temp;
	}
}
void pop()
{
	if(isempty())
		cout<<"The stack is empty"<<endl;
	else
	{
		int temp=st.s[st.top--];
		cout<<"The poped element is : "<<temp<<endl;
	}
}
void peek()
{
	int p,temp;
	cout<<"Enter the peek value : ";
	cin>>p;
	temp=st.top-p;
	if(temp>-1 and temp<st.top+1)
		cout<<"The peek element in the stack is : "<<st.s[temp]<<endl;
	else
		cout<<"The peak value is invalid"<<endl;
}
void stacktop()
{
	if(isempty())
		cout<<"The stack is empty"<<endl;
	else
		cout<<"The stack top value is : "<<st.s[st.top]<<endl;
}
void display()
{
	if(isempty())
	{
		cout<<"The stack is empty"<<endl;
		return;
	}
	
	for(int i=0;i<=st.top;i++)
		cout<<st.s[i]<<" ";
	cout<<endl;
}
int main()
{
	cout<<"Stack using array"<<endl;
	cout<<"Enter the maximum size of the stack : ";
	cin>>st.size;
	st.s=new int[st.size];
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
