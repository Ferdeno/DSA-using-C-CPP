#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct element
{
	int i;
	int j;
	int x;
}e;
struct sparse
{
	int m;
	int n;
	int num;
	struct element *e;
}s;
void create(struct sparse *s)
{
	int a,b,c;
	cout<<"Enter dimensions : ";
	cin>>s->m>>s->n;
	cout<<"Enter number of non zero elements : ";
	cin>>s->num;
	s->e=new element[s->num];
	//s->e=(struct element *)malloc(s->num*sizeof(struct element));
	for(int i=0;i<s->num;i++)
	{
		cout<<"Enter the ROW __ COLUMN __ VALUE __ of element "<<i+1<<" : ";
		cin>>s->e[i].i>>s->e[i].j>>s->e[i].x;
	}// the input of row and column should be enter by decrement by 1
}
void display(struct sparse s)
{
	int k=0;
	for(int i=0;i<s.m;i++)
	{
		for(int j=0;j<s.n;j++)
		{
			if(i==s.e[k].i && j==s.e[k].j)
			{
				cout<<s.e[k++].x<<" ";
			}
			else
			{
				cout<<"0 ";
			}
		}
		cout<<endl;
	}
}
int main()
{
	struct sparse s;
	create(&s);	
	display(s);
}
