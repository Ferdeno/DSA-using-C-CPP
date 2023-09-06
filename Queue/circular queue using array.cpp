#include<iostream>
using namespace std;
struct queue
{
	int size;
	int front;
	int rear;
	int *Q;
};
bool isfull(queue *q)
{
	if(q->rear==q->size-1)	
		return true;
	return false;
}
bool isempty(queue *q)
{
	if(q->front==q->rear)
		return true;
	return false;
}
void enqueue(queue *q)
{
	if((q->rear+1)%q->size==q->front)
	{
		cout<<"Queue overflow "<<endl;
		return;
	}
	else
	{
		q->rear=(q->rear+1)%q->size;
		cout<<"Enter element : ";
		cin>>q->Q[q->rear];
	}
}
void dequeue(queue *q)
{
	if(q->front==q->rear)
	{
		cout<<"Queue underflow"<<endl;
		return;
	}
	q->front=(q->front+1)%q->size;
	cout<<"The deleted element is "<<q->Q[q->front]<<endl;
}
void display(queue q)
{
	if(q.front==q.rear)
	{
		cout<<"Queue underflow"<<endl;
		return;
	}
	int i=(q.front+1)%q.size;
	do
	{
		cout<<q.Q[i]<<" ";
		i=(i+1)%q.size;
	}while(i!=(q.rear+1)%q.size);
	cout<<endl;
}
int main()
{
	int ch;
	cout<<"\tCIRCULAR QUEUE USING ARRAY"<<endl;
	struct queue q;
	cout<<"Enter the size of the queue : ";
	cin>>q.size;
	q.front=q.rear=0;
	q.Q=new int[q.size];
	do
	{
		cout<<"1.Enqueue \n2.Dequeue \n3.Display\n4.Exit\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				enqueue(&q);
				break;
			case 2:
				dequeue(&q);
				break;
			case 3:
				display(q);
				break;
			case 4:
				exit(0);
			default :
				cout<<"Invalid option "<<endl;
				break;
		}
	}while(ch!=4);
}
