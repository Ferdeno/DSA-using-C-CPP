#include<iostream>
using namespace std;
class queue
{
	private:
		int front;
		int rear;
		int size;
		int *Q;
	public:
		queue()
		{
			front=rear=-1;
			size=10;
			Q=new int[size];
		}
		queue(int size)
		{
			front=rear=-1;
			this->size=size;
			Q=new int[this->size];
		}
		bool isfull();
		bool isempty();
		void enqueue();
		void dequeue();
		void display();
};
bool queue::isfull()
{
	if(rear==size-1)
		return true;
	return false;
}
bool queue::isempty()
{
	if(rear==front)
		return true;
	return false;
}
void queue::enqueue()
{
	if (isfull())
	{
		cout<<"Queue overflow"<<endl;
		return;
	}
	else
	{
		rear++;
		cout<<"Enter element : ";
		cin>>Q[rear];
	}
}
void queue::dequeue()
{
	if(isempty())
	{
		cout<<"Queue underflow"<<endl;
		return;
	}
	else
	{
		front++;
		cout<<"The deleted element : "<<Q[front]<<endl;
	}
}
void queue::display()
{
	if (isempty())
	{
		cout<<"Queue underflow"<<endl;
		return;
	}
	for(int i=front+1;i<=rear;i++)
	{
		cout<<Q[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int ch,size;
	cout<<"\tQUEUE USING ARRAY CLASS"<<endl;
	cout<<"Enter the size of the queue : ";
	cin>>size;
	queue q(size);
	do
	{
		cout<<"1.Enqueue \n2.Dequeue \n3.Display\n4.Exit\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				q.enqueue();
				break;
			case 2:
				q.dequeue();
				break;
			case 3:
				q.display();
				break;
			case 4:
				exit(0);
			default :
				cout<<"Invalid option "<<endl;
				break;
		}
	}while(ch!=4);
}





