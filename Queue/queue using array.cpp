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
void display(queue q)
{
	if (isempty(&q))
	{
		cout<<"Queue underflow"<<endl;
		return;
	}
	for(int i=q.front+1;i<=q.rear;i++)
	{
		cout<<q.Q[i]<<" ";
	}
	cout<<endl;
}
void enqueue(queue *q)
{
	if (isfull(q))
	{
		cout<<"Queue overflow"<<endl;
		return;
	}
	else
	{
		q->rear++;
		cout<<"Enter element : ";
		cin>>q->Q[q->rear];
	}
}
void dequeue(queue *q)
{
	if(isempty(q))
	{
		cout<<"Queue underflow"<<endl;
		return;
	}
	else
	{
		q->front++;
		cout<<"The deleted element : "<<q->Q[q->front]<<endl;
	}
}
int main()
{
	int ch;
	cout<<"\tQUEUE USING ARRAY"<<endl;
	struct queue q;
	cout<<"Enter the size of the queue : ";
	cin>>q.size;
	q.front=q.rear=-1;
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
