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
		cout<<"Enter the row column value of element "<<i<<" : ";
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
struct sparse *add(struct sparse *s1,struct sparse *s2)
{
	if(s1->m!=s2->m || s1->n!=s2->n)
	{
		return 0;
	}
	struct sparse *sum;
	int i=0,j=0,k=0;
	sum=new sparse[s.num];
	sum->e=new element[s1->num+s1->num];
	while(i<s1->num && j<s2->num)
	{
		if(s1->e[i].i<s2->e[j].i)
		{
			sum->e[k++]=s1->e[i++];
		}
		else if(s1->e[i].i>s2->e[j].i)
		{
			sum->e[k++]=s2->e[j++];
		}
		else if(s1->e[i].j<s2->e[j].j)
		{
			sum->e[k++]=s1->e[i++];
		}
		else if(s1->e[i].j>s2->e[j].j)
		{
			sum->e[k++]=s2->e[j++];
		}
		else
		{
			sum->e[k]=s1->e[i];
			sum->e[k++].x=s1->e[i++].x+s2->e[j++].x;
		}
		 
	}
	for(;i<s1->num;i++)
	{
		sum->e[k++]=s1->e[i];
	}
	for(;j<s2->num;j++)
	{
		sum->e[k++]=s2->e[j];
	}
	sum->m=s1->m;
	sum->n=s2->n;
	sum->num=k;
}
int main()
{
	struct sparse s1,s2,*s3;
	create(&s1);
	create(&s2);
	cout<<"Matrix 1 "<<endl;
	display(s1);
	cout<<"Matrix 2 "<<endl;
	display(s2);
	s3=add(&s1,&s2);
	cout<<"Sum of the Matrix "<<endl;
	display(*s3);
}
