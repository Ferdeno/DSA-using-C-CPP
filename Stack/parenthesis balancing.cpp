#include<iostream>
#include<cstring>
using namespace std;
struct stack
{
	int size;
	int top=-1;
	char *s;
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
void push(char c)
{
	st.s[st.top++]=c;
}
void pop()
{
	if(isempty())
	{
		cout<<"Stack underflow";
		return;
	}
	st.top--;
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
bool checkparenthesis(char *exp)
{
	st.size=strlen(exp);
	st.s=new char[st.size];
	for(int i=0;i<st.size;i++)
	{
		if(exp[i]=='(')
		{
			push(exp[i]);
		}
		else if(exp[i]==')')
		{
			if(isempty())
			{
				return false;
			}
			pop();
		}
	}
	return isempty();
}
int main()
{
	char s[10];
	cout<<"Enter the expression for parenthesis checking : ";
	cin>>s;
	if(checkparenthesis(s))
		cout<<"Parenthesis is balancing";
	else
		cout<<"Parenthesis is not balancing";
}
