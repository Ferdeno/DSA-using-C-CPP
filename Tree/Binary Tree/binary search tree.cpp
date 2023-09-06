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
		struct node *root=NULL;
		tree()
		{
			root=NULL;
		}
		void treecreate();
		void bst(node *p);
		node *Recursivebst(node *t ,int key);
		void normalinsert(node* t,int key);
		void preorder(node* p);
		node* recursiveinsert(node *t,int key);
		node* ndelete(node *t,int key);
		void inorder(node *t);
		node* inorderpredecessor(node *t);
		node* inordersuccessor(node *t);
		int height(node *t);
};

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
//this works by comparing the data of the p and finds the search element
void tree::bst(node *p)
{
	int key;
	cout<<"Enter the search element : ";
	cin>>key;
	while(p)
	{
		if (p->data==key)
		{
			cout<<"Key element is found";
			return;
		}
		else if (p->data>key)
			p=p->lchild;
		else
			p=p->rchild;
	}
	cout<<"Key element is not found";
	return;
}

node* tree::Recursivebst(node *t,int key)
{
	if(t==NULL)
		return NULL;
	else if (t->data==key)
		return t;
	else if(t->data>key)
		return tree::Recursivebst(t->lchild,key);
	else
		return tree::Recursivebst(t->rchild,key);
}
/*comparing the value of key and t->data and move to the desired place and insert the new data using
tail pointer */
void tree::normalinsert(node *t,int key)
{
	node *r=NULL,*p;
	while(t)
	{
		r=t;
		if(key==t->data)
			return;
		else if (key<t->data)
			t=t->lchild;
		else
			t=t->rchild;
	}
	p=new node;
	p->data=key;
	p->lchild=p->rchild=NULL;
	if(p->data<r->data)
		r->lchild=p;
	else
		r->rchild=p;
}

node* tree::recursiveinsert(node *p,int key)
{
	node *t;
	if(p==NULL)
	{
		t=new node;
		t->data=key;
		t->lchild=t->rchild=NULL;
		return t;
	}
	if(key<p->data)
		p->lchild=tree::recursiveinsert(p->lchild,key);
	else if (key>p->data)
		p->rchild=tree::recursiveinsert(p->rchild,key);
	return p;
}
void tree::preorder(node *p)
{
	if(p)
	{
		cout<<p->data<<" ";
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

void tree::inorder(node *p)
{
	if(p)
	{
		tree::inorder(p->lchild);
		cout<<p->data<<" ";
		tree::inorder(p->rchild);
	}
}

node *tree::inorderpredecessor(node *t)
{
	while(t && t->rchild!=NULL)
	{
		t=t->rchild;
	}
	return t;
}

node *tree::inordersuccessor(node *t)
{
	while(t && t->lchild!=NULL)
	{
		t=t->lchild;
	}
	return t;
}

int tree::height(node *t)
{
	int x,y;
	if(t==NULL)
		return 0;
	x=tree::height(t->lchild);
	y=tree::height(t->rchild);
	return x>y?x+1:y+1;
}
//delete the node recursively
node* tree::ndelete(node* p,int key)
{
	if(p==NULL)
		return NULL;
	if(p->lchild==p->rchild==NULL)
	{
		if(p==tree::root)
			tree::root==NULL;
		delete p;
		return NULL;	
	}
	node *q;
	if(key<p->data)
		p->lchild=tree::ndelete(p->lchild,key);
	else if (key>p->data)
		p->rchild=tree::ndelete(p->rchild,key);
	else
	{
		if(tree::height(p->lchild)>tree::height(p->rchild))
		{
			q=tree::inorderpredecessor(p->lchild);
			p->data=q->data;
			p->lchild=tree::ndelete(p->lchild,q->data);
		}
		else
		{
			q=tree::inordersuccessor(p->rchild);
			p->data=q->data;
			p->rchild=tree::ndelete(p->rchild,q->data);
		}
	}
	return p;
}
int main()
{
	tree t;
	t.treecreate();
//	t.bst(t.root);
//	node *temp;
//	temp=t.Recursivebst(t.root,25);
//	if(temp)
//		cout<<"The key element is found";
//	else
//		cout<<"The key element is not found";
//	t.preorder(t.root);
//	t.normalinsert(t.root,20);
//	cout<<"\n";
//	t.preorder(t.root);
//	cout<<"\n";
//	node *insert=t.recursiveinsert(t.root,15);
	t.preorder(t.root);
	node *temp=t.ndelete(t.root,20);
	cout<<"\n";
	t.preorder(t.root);
	return 0;
}











