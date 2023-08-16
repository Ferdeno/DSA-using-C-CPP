#include<iostream>
#include<cstring>
using namespace std;
struct stack
{
	int size;
	int top=-1;
	char *s;
}st;

//to check it operand or operator
bool isoperand(char x)
{
	if(x=='+'||x=='-'||x=='/'||x=='*')
		return false;	
	return true;
}

//to check the precedence of the operator
int precedence(char x)
{
	if(x=='+'||x=='-')
		return 1;
	else if(x=='*'||x=='/')
		return 2;
	return 0;
}

bool isfull()
{
	return st.top==st.size-1;
}

bool isempty()
{
	return st.top==-1;
}

void push(char x)
{
	st.top++;
	st.s[st.top]=x;
}

char pop()
{
	char temp=st.s[st.top--];
	return temp;
}

char stacktop()
{
	if(isempty())
		return 0;
	else
		return st.s[st.top];
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

char *infixtopostfix(char *infix)
{
	char *postfix=new char[strlen(infix)+1];//this array is to store the postfix expression
	int i=0,j=0;
	while(i<strlen(infix))
	{
		if(isoperand(infix[i]))
			postfix[j++]=infix[i++];
		else
		{
			if(precedence(infix[i])>precedence(stacktop()))
				push(infix[i++]);
			else
				postfix[j++]=pop();
		}
	}
	while(st.top!=-1)//this is to add the remaining elements in the stack to the postfix expression
	{
		postfix[j++]=pop();
	}
	postfix[j]='\0';//this is added to prevent the garbage value to the postfix array
	return postfix;
}

int main()
{
	char infix[]="a+b*d";
	st.size=strlen(infix);
	st.s=new char[st.size];//creating a array in stack structure 
	char *postfix=infixtopostfix(infix);
	cout<<"THE INFIX EXPRESSION : "<<infix<<endl;
	cout<<"THE POSTFIX EXPRESSION : "<<postfix;
	delete [] postfix;//dealocating 
	delete [] st.s;
}


