#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
struct queue
{
	struct node *front;
	struct node *rear;
};
void enqueue(struct queue *q,int x)
{
	struct node *t=new node;
	if(t==NULL)
	{
		cout<<"Heap memory is full or queue is full"<<endl;
		return;
	}
	else
	{
		t->data=x;
		t->next=NULL;
		if(q->front==NULL)
			q->front=q->rear=t;
		else
		{
			q->rear->next=t;
			q->rear=t;
		}
	}
}
void display(struct queue q)
{
	if(q.front==NULL)
	{
		cout<<"Queue underflow"<<endl;
		return;
	}
	else
	{
		node *p;
		p=q.front;
		while(p)
		{
			cout<<p->data<<" ";
			p=p->next;
		}
	}
	cout<<endl;
}
void dequeue(struct queue *q)
{
	if(q->front==NULL)
	{
		cout<<"Queue underflow"<<endl;
		return;
	}
	else
	{
		struct node *t;
		t=q->front;
		q->front=q->front->next;
		cout<<t->data<<" ";
		delete t;
	}
}
bool isempty(struct queue q)
{
	if(q.front==NULL)
		return true;
	return false;
}
void clear(struct queue *q)
{
	struct node *p;
	p=q->front;
	while(p)
	{
		q->front=q->front->next;
		delete p;
		p=q->front;
	}
}
int main()
{
	struct queue q1,q2,q3;
	q1.front=NULL;
	q1.rear==NULL;
	q2.front=NULL;
	q2.rear==NULL;
	q3.front=NULL;
	q3.rear==NULL;
	int n,element,priority;
	cout<<"Enter the no of threads : ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter element "<<i<<" as element and priority : ";
		cin>>element>>priority;
		switch(priority)
		{
			case 1:
				enqueue(&q1,element);
				break;
			case 2:
				enqueue(&q2,element);
				break;
			case 3:
				enqueue(&q3,element);
				break;
		}
	}
	cout<<"Queue 1 : ";
	display(q1);
	cout<<"Queue 2 : ";
	display(q2);
	cout<<"Queue 3 : ";
	display(q3);
	cout<<"The thread will execute in the order : ";
	while(!isempty(q1)||!isempty(q2)||!isempty(q3))
	{
		if(!isempty(q1))
			dequeue(&q1);
		if(!isempty(q2) && isempty(q1))
			dequeue(&q2);
		if(!isempty(q3) && isempty(q1) && isempty(q2))
			dequeue(&q3);
	}
	clear(&q1);
	clear(&q2);
	clear(&q3);
}








