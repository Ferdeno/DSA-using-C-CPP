#include<iostream>
using namespace std;

struct node
{
	struct node *lchild;
	int data;
	int height;
	struct node *rchild;
}*root=NULL;
//to find the height of the node 
int nodeheight(struct node *p)
{
	int hl,hr;
	
	hl=p&&p->lchild?p->lchild->height:0;
	hr=p&&p->rchild?p->rchild->height:0;
	
	if(!p)
		return 0;
	return hl>hr?hl+1:hr+1;
}
//calculating balancing factor
int balancefactor(struct node *p)
{
	int hl,hr;
	
	hl=p&&p->lchild?p->lchild->height:0;
	hr=p&&p->rchild?p->rchild->height:0;
	
	return hl-hr;
}
//when the last node is inserted in LEFT LEFT then this function executes 
struct node *LLRotation(struct node *p)
{
	struct node *pl=p->lchild;
	struct node *plr=pl->rchild;
	
	pl->rchild=p;
	p->lchild=plr;
	
	p->height=nodeheight(p);
	pl->height=nodeheight(pl);
	
	if(root==p)
		root=pl;
	
	return pl;
}
//when the last node is inserted in LEFT RIGHT then this function executes 
struct node *LRRotation(struct node *p)
{
	struct node *pl=p->lchild;
	struct node *plr=pl->rchild;
	
	pl->rchild=plr->lchild;
	p->lchild=plr->rchild;
	
	plr->lchild=pl;
	plr->rchild=p;
	
	p->height=nodeheight(p);
	pl->height=nodeheight(pl);
	plr->height=nodeheight(plr);
	
	if(root==p)
		root=plr;
	
	return plr;
}
//when the last node is inserted in RIGHT LEFT then this function executes 
struct node *RLRotation(struct node *p)
{
	struct node *pr=p->rchild;
	struct node *prl=pr->lchild;
	
	p->rchild=prl->lchild;
	pr->lchild=prl->rchild;
	
	prl->lchild=p;
	prl->rchild=pr;
	
	pr->height=nodeheight(pr);
	p->height=nodeheight(p);
	prl->height=nodeheight(prl);
	
	if(root==p)
		root=prl;
	
	
	return prl;
	
}
//when the last node is inserted in RIGHT RIGHT then this function executes 
struct node *RRRotation(struct node *p)
{
	struct node *pr=p->rchild;
	struct node *prl=pr->lchild;
	
	p->rchild=prl;
	pr->lchild=p;
	
	p->height=nodeheight(p);
	pr->height=nodeheight(pr);
	
	if(root==p)
		root=pr;
	
	return pr;
	
}
//inserting node in a binary tree 
struct node *recursiveinsert(node *p,int key)
{
	node *t;
	if(p==NULL)
	{
		t=new node;
		t->data=key;
		t->height=1;//starting height from 1 not 0 if 0 make t->height to 0
		t->lchild=t->rchild=NULL;
		return t;
	}
	if(key<p->data)
		p->lchild=recursiveinsert(p->lchild,key);
	else if (key>p->data)
		p->rchild=recursiveinsert(p->rchild,key);
		
	p->height=nodeheight(p);
	
	if(balancefactor(p)==2 && balancefactor(p->lchild)==1)
		return LLRotation(p);
		
	else if(balancefactor(p)==2 && balancefactor(p->lchild)==-1)
		return LRRotation(p);
		
	else if(balancefactor(p)==-2 && balancefactor(p->rchild)==1)
		return RLRotation(p);

	else if(balancefactor(p)==-2 && balancefactor(p->rchild)==-1)
		return RRRotation(p);
		
	return p;
}

void preorder(node *p)
{
	if(p)
	{
		cout<<p->data<<" ";
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

void inorder(node *p)
{
	if(p)
	{
		inorder(p->lchild);
		cout<<p->data<<" ";
		inorder(p->rchild);
	}
}
int main()
{
	root=recursiveinsert(root,50);
	recursiveinsert(root,45);
	recursiveinsert(root,47);
	preorder(root);
	cout<<"\n";
	inorder(root);	
}
