#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	struct node *lchild;
	int data;
	struct node *rchild;
};

struct queue
{
	int size;
	int front;
	int rear;
	node **Q;
};

void create(struct queue *q,int size)
{
	q->size=size;
	q->front=q->rear=0;
	q->Q=new node*[q->size];
	//q->Q=(node **)malloc(q->size*sizeof(node *)); c language
}

void enqueue(queue *q,node *x)
{
	if((q->rear+1)%q->size==q->front)
	{
		cout<<"Queue overflow "<<endl;
		return;
	}
	else
	{
		q->rear=(q->rear+1)%q->size;
		q->Q[q->rear]=x;
	}
}

node *dequeue(queue *q)
{
	node *x=NULL;
	if(q->front==q->rear)
	{
		cout<<"Queue underflow"<<endl;
		
	}
	else
	{
		q->front=(q->front+1)%q->size;
		x=q->Q[q->front];
		return x;
	}
}

bool isempty(queue q)
{
	if(q.front==q.rear)
		return true;
	return false;
}

struct node *root=NULL;

void treecreate()
{
	struct node *p,*t;
	int x;
	struct queue q;
	create(&q,100);
	cout<<"Enter the root value : ";
	cin>>x;
	root=new node;
//	root=(struct node *)malloc(sizeof(struct node));
	root->data=x;
	root->lchild=root->rchild=NULL;
	enqueue(&q,root);
	
	while(!isempty(q))
	{
		p=dequeue(&q);
		cout<<"Enter left child of "<<p->data<<" : ";
		cin>>x;
		if(x!=-1)
		{
			t=(struct node *)malloc(sizeof(struct node));
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->lchild=t;
			enqueue(&q,t);
		}
		cout<<"Enter right child "<<p->data<<" : ";
		cin>>x;
		if(x!=-1)
		{
			t=(struct node *)malloc(sizeof(struct node));
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->rchild=t;
			enqueue(&q,t);
		}
	}
}

void preorder(struct node *p)
{
	if(p)
	{
		cout<<p->data<<" ";
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

void inorder(struct node *p)
{
	if(p)
	{
		inorder(p->lchild);
		cout<<p->data<<" ";
		inorder(p->rchild);
	}
}

void postorder(struct node *p)
{
	if(p)
	{
		postorder(p->lchild);
		postorder(p->rchild);
		cout<<p->data<<" ";
	}
}
int main()
{
	treecreate();
	cout<<"Preorder : ";
	preorder(root);
	cout<<endl<<"Inorder : ";
	inorder(root);
	cout<<endl<<"Postorder : ";
	postorder(root);
	return 0;
}
