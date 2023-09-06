#include<iostream>
#include<stdlib.h>
using namespace std;

class node
{
	public:
		node *lchild;
		int data;
		node *rchild;
};

class queue
{
	private:
		int front;
		int rear;
		int size;
		node **Q;
	public:
		queue()
		{
			front=rear=-1;
			size=10;
			Q=new node*[size];
		}
		queue(int size)
		{
			front=rear=-1;
			this->size=size;
			Q=new node*[this->size];
		}
		void enqueue(node* x);
		node *dequeue();
		bool isempty();
};

void queue::enqueue(node *x)
{
	if(rear==size-1)
		cout<<"Queue overflow";
	else
	{
		rear++;
		Q[rear]=x;
	}
}

node *queue::dequeue()
{
	node *x=NULL;
	if(front==rear)
		cout<<"Queue underflow";
	else
	{
		x=Q[front+1];
		front++;
	}
	return x;
}

bool queue::isempty()
{
	return front==rear;
}
class tree
{
	public:
		struct node *root;
		tree()
		{
			root=NULL;
		}
		void treecreate();
		void preorder(node *p);
		void inorder(node *p);
		void postorder(node *p);
		void levelorder(node *p);
		int height(node *p);
		int count(node *p);
		int optimalcount(node *p);
		int sum(node *p);
		int countofdegreeoftwo(node *p);
		int countleafnode(node *p);
		int countdegreeonetwo(node *p);
		int countdegreeone(node *p);
};

void tree::preorder(struct node *p)
{
	if(p)
	{
		cout<<p->data<<" ";
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

void tree::inorder(struct node *p)
{
	if(p)
	{
		inorder(p->lchild);
		cout<<p->data<<" ";
		inorder(p->rchild);
	}
}

void tree::postorder(struct node *p)
{
	if(p)
	{
		postorder(p->lchild);
		postorder(p->rchild);
		cout<<p->data<<" ";
	}
}

void tree::levelorder(struct node *root)
{
	queue q(100);
	q.enqueue(root);
	cout<<root->data<<" ";
	while(!q.isempty())
	{
		root=q.dequeue();
		if(root->lchild)
		{
			cout<<root->lchild->data<<" ";
			q.enqueue(root->lchild);
		}
		if(root->rchild)
		{
			cout<<root->rchild->data<<" ";
			q.enqueue(root->rchild);
		}
	}
}

int tree::height(struct node *root)
{
	int x=0,y=0;
	if(root==0)
		return 0;
	x=height(root->lchild);
	y=height(root->rchild);
	if(x>y)
		return x+1;
	else
		return y+1;
}

int tree::count(struct node *p)
{
	int x,y;
	if(p)
	{
		x=tree::count(p->lchild);
		y=tree::count(p->rchild);
		return x+y+1;
	}
	return 0;
}

int tree::optimalcount(struct node *p)
{
	int x,y;
	if(p)
	{
		return tree::optimalcount(p->lchild)+tree::optimalcount(p->rchild)+1;
	}
	return 0;
}

int tree::sum(struct node *p)
{
	int x,y;
	if(p)
	{
		x=tree::sum(p->lchild);
		y=tree::sum(p->rchild);
		return x+y+p->data;
	}
	return 0;
}

int tree::countofdegreeoftwo(struct node *p)
{
	int x,y;
	if(p)
	{
		x=tree::countofdegreeoftwo(p->lchild);
		y=tree::countofdegreeoftwo(p->rchild);
		if(p->lchild && p->rchild)
			return x+y+1;
		else
			return x+y;
	}
	return 0;
}

int tree::countleafnode(struct node *p)
{
	int x,y;
	if(p)
	{
		x=tree::countleafnode(p->lchild);
		y=tree::countleafnode(p->rchild);
		if(!p->lchild && !p->rchild)
			return x+y+1;
		else
			return x+y;
	}
	return 0;
}

int tree::countdegreeonetwo(struct node *p)
{
	int x,y;
	if(p)
	{
		x=tree::countdegreeonetwo(p->lchild);
		y=tree::countdegreeonetwo(p->rchild);
		if(p->lchild || p->rchild)
			return x+y+1;
		else
			return x+y;
	}
	return 0;
}

int tree::countdegreeone(struct node *p)
{
	int x,y;
	if(p)
	{
		x=tree::countdegreeone(p->lchild);
		y=tree::countdegreeone(p->rchild);
		if(p->lchild!=NULL ^ p->rchild!=NULL)
			return x+y+1;
		else
			return x+y;
	}
	return 0;
}


void tree::treecreate()	
{
	node *p,*t;
	int x;
	queue q(100);
	cout<<"If there is no leaf node enter -1 \n";
	cout<<"Enter the root value : ";
	cin>>x;
	root=new node;
	root->data=x;
	root->lchild=root->rchild=NULL;
	q.enqueue(root);
	
	while(!q.isempty())
	{
		p=q.dequeue();
		cout<<"Enter left child of "<<p->data<<" : ";
		cin>>x;
		if(x!=-1)
		{
			t=new node;
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->lchild=t;
			q.enqueue(t);
		}
		cout<<"Enter right child "<<p->data<<" : ";
		cin>>x;
		if(x!=-1)
		{
			t=new node;
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->rchild=t;
			q.enqueue(t);
		}
	}
}

int main()
{
	tree t;
	t.treecreate();
	cout<<"Preorder : ";
	t.preorder(t.root);
	cout<<endl<<"Inorder : ";
	t.inorder(t.root);
	cout<<endl<<"Postorder : ";
	t.postorder(t.root);
	cout<<endl<<"Levelorder : ";
	t.levelorder(t.root);
	cout<<endl<<"Count : "<<t.count(t.root);
	cout<<endl<<"Optimalcount : "<<t.optimalcount(t.root);
	cout<<endl<<"Height : "<<t.height(t.root);
	cout<<endl<<"Sum : "<<t.sum(t.root);
	cout<<endl<<"Count of degree of two : "<<t.countofdegreeoftwo(t.root);
	cout<<endl<<"Count of leaf nodes : "<<t.countleafnode(t.root);
	cout<<endl<<"Count of degree of one or two : "<<t.countdegreeonetwo(t.root);
	cout<<endl<<"Count of degree of one : "<<t.countdegreeone(t.root);
}

