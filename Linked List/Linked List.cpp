#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct node //creating node
{
	int data;
	struct node *next;
}*first=NULL,*second=NULL;
//create the linked list of the array A
void createA(int A[],int n)
{
	struct node *t,*last;
	first=new node;	
	first->data=A[0];
	first->next=NULL;
	last=first;
	for(int i=1;i<n;i++)
	{
		t=new node;
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
}
//create the linked list of the array B
void createB(int B[],int n)
{
	struct node *t,*last;
	second=new node;	
	second->data=B[0];
	second->next=NULL;
	last=second;
	for(int i=1;i<n;i++)
	{
		t=new node;
		t->data=B[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
}
//display the innked list normal
void normaldisplay(struct node *p)
{
	while(p!=NULL)
	{
		cout<<p->data<<"->";
		p=p->next;
	}
}
//displaying the linked list recursively
void recursivedisplay(struct node *p)
{
	if(p!=NULL)
	{
		cout<<p->data<<"->";
		recursivedisplay(p->next);
	}
}
//displaying the linked list in reverse order recursively
void reverserecursivedisplay(struct node *p)
{
	if(p!=NULL)
	{
		reverserecursivedisplay(p->next);
		cout<<p->data<<"->";
	}
}
//normal count of the linked list
int normalcount(struct node *p)
{
	int count=0;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	}
	return count;
}
//recursive count of the linked list
int recursivecount(struct node *p)
{
	if(p==NULL)
		return 0;
	return recursivecount(p->next)+1;//1+recursivecount(p->next);
}
//normal additon of the linked list
int normaladd(struct node *p)
{
	int sum=0;
	while(p)
	{
		sum+=p->data;
		p=p->next;
	}
	return sum;
}
//recursive addition of the linked list
int recursiveadd(struct node *p)
{
	if(p==NULL)
		return 0;
	return recursiveadd(p->next)+p->data;
}
//normal max of the linked list
int normalmax(struct node *p)
{
	int m=INT_MIN;//minimum element of integer
	while(p)
	{
		if(m<p->data)
		{
			m=p->data;
		}
		p=p->next;
	}
	return m;
}
//recursive method 1 max of the linked list
int recursivemax1(struct node *p)
{
	int x=0;
	if(p==0)
		return INT_MIN;
	else
	{
		x=recursivemax1(p->next);
		if(x>p->data)
			return x;
		return p->data;
	}
}
//recursive method 2 max of the linked list
int recursivemax2(struct node *p)
{
	int x=0;
	if(p==0)
		return INT_MIN;
	x=recursivemax2(p->next);
	return x>p->data ? x:p->data;
}
//minimum of the linked list
int normalmin(struct node *p)
{
	int m=INT_MAX;//maximum element of integer
	while(p)
	{
		if(m>p->data)
		{
			m=p->data;
		}
		p=p->next;
	}
	return m;
}
//recursive method 1 min of the linked list
int recursivemin1(struct node *p)
{
	int x=0;
	if(p==0)
		return INT_MAX;
	else
	{
		x=recursivemin1(p->next);
		if(x<p->data)
			return x;
		return p->data;
	}
}
//recursive method 2 min of the linked list
int recursivemin2(struct node *p)
{
	int x=0;
	if(p==0)
		return INT_MAX;
	x=recursivemin2(p->next);
	return x<p->data ? x:p->data;
}
//normal linear search to find a element in linked list
struct node *normalsearch(struct node *p,int key)
{
	while(p)
	{
		if(p->data==key)
			return p;
		p=p->next;
	}
	return NULL;
}
//recursive linear search to find a element in linked list
struct node *recursivesearch(struct node *p,int key)
{
	if(p==NULL)
		return NULL;
	if(p->data==key)
		return p;
	recursivesearch(p->next,key);
}
//impoving the search of the linked list by move to head 
struct node *movetoheadsearch(struct node *p,int key)
{
	struct node *q=NULL;//q is tail pointer 
	while(p)
	{
		if(key==p->data)
		{
			q->next=p->next;
			p->next=first;
			first=p;
			return p;
		}
		q=p;
		p=p->next;
	}
	return NULL;
}
//inserting a element in linked list
void insertatfirst(struct node *p)
{
	int x;
	cout<<"Enter the element to be inserted at first : ";
	cin>>x;
	struct node *t;
	t=new node;
	t->data=x;
	t->next=first;
	first=t;
}
//inserting a element in linked list at given index
void insertatposition(struct node *p)
{
	int x,y;
	cout<<"Enter the element to be inserted : ";
	cin>>x;
	cout<<"Enter the index where the element "<<x<<" to be inserted : ";
	cin>>y;
	for(int i=0;i<y-1;i++)
	{
		p=p->next;
	}
	struct node *t;
	t=new node;
	t->data=x;
	t->next=p->next;
	p->next=t;
}
//insert function in linked list
void insert(struct node *p)
{
	int element,position;
	cout<<"Enter the element to be inserted : ";
	cin>>element;
	cout<<"Enter the index where the element "<<element<<" to be inserted : ";
	cin>>position;
	if(position<0 || position>normalcount(p))
	{
		cout<<"INVALID INDEX";
		return;
	}
	struct node *t=new node;
	t->data=element;
	if(position==0)
	{
		t->next=first;
		first=t;
	}
	else
	{
		for(int i=0;i<position-1;i++)
			p=p->next;
		t->next=p->next;
		p->next=t;
	}
}
//inserting element at only last in the linked list
void insertatlast(struct node *p)
{
	struct node *last=new node;
	int n;
	do
	{
		int element;
		cout<<"Enter the element to be inserted at last : ";
		cin>>element;
		struct node *t=new node;
		t->data=element;
		t->next=NULL;
		if(first==NULL)
			first=last=t;
		else
		{
			last->next=t;
			last=t;
		}
		cout<<"Enter 1 to add element else 0 : ";
		cin>>n;
	}while(n);
}
//inserting element in a sorted linked list using 3 pointers
void insertinsortedlinkedlist(struct node *p)
{
	int element;
	cout<<"Enter the element to be inserted in a sorted array : ";
	cin>>element;
	struct node *t=new node,*q=NULL;//q is tail pointer 
	t->data=element;
	t->next=NULL;
	if(first==NULL)
	{
		first=t;
		return;	
	}
	else if(p->data>element)
	{	
		t->next=first;
		first=t;
		return;
	}	
	while(p&&p->data<element)
	{
		q=p;
		p=p->next;
	}
	t->next=q->next;
	q->next=t;
}
//deletion of first node
void deleteatfirst(struct node *p)
{
	p=first;
	first=first->next;
	int x=p->data;
	delete p;
}
//deletion of node at anyposition except index 0
int deleteatanypositionexp0(struct node *p)
{
	int index;
	p=first;
	struct node *q=NULL;//tail pointer 
	cout<<"Enter the index to be deleted except 0 : ";
	cin>>index;
	for(int i=0;i<index;i++)
	{
		q=p;
		p=p->next;
	}
	q->next=p->next;
	int x=p->data;
	delete p;
	return x;
}
//deletion of node at any position
void deleteatanyposition(struct node *p)
{
	int x,index;
	p=first;
	cout<<"Enter the index to be deleted : ";
	cin>>index;
	if(index<0||index>normalcount(p)-1)
	{
		cout<<"INVALID INDEX";
		return;	
	}
	if(index==0)
	{
		first=first->next;
		x=p->data;
		delete p;//delete is used in C++
		cout<<endl<<"The deleted element is "<<x;
	}
	else
	{
		struct node *q=NULL;
		for(int i=0;i<index;i++)
		{
			q=p;
			p=p->next;
		}
		q->next=p->next;
		x=p->data;
		free(p);//free is used in C 
		cout<<endl<<"The deleted element is "<<x;
		
	}
}
//checking whether the linked list is sorted or not
void checksortlinkedlist(struct node *p)
{
	int x=INT_MIN;
	while(p!=NULL)
	{
		if(x>p->data)
		{
			cout<<"The linked list is not sorted ";
			return;
		}
		x=p->data;
		p=p->next;
	}
	cout<<"The linked list is sorted ";
}
//removing duplicate element in a linked list
void removeduplicate(struct node *p)
{
	p=first;
	struct node *q=p->next;
	while(q!=NULL)
	{
		if(p->data==q->data)
		{
			p->next=q->next;
			delete q;
			q=p->next;
		}
		else
		{
			p=q;
			q=q->next;	
		}
	}
}
//reversing the linked list using for loop
void reverselinkedlistforloop(struct node *p)
{
	int n=normalcount(p);
	int A[n];
	for(int i=0;i<n;i++)
	{
		A[i]=p->data;
		p=p->next;
	}
	p=first;
	for(int i=n-1;i>=0;i--)
	{
		p->data=A[i];
		p=p->next;
	}
}
//reversing the linked list using while loop
void reverselinkedlistwhileloop(struct node *p)
{
	int A[normalcount(p)],i=0;
	while(p)
	{
		A[i]=p->data;
		p=p->next;
		i++;
	}
	p=first;
	i--;
	while(p)
	{
		p->data=A[i];
		p=p->next;
		i--;
	}
}
//reversing the linked list using sliding pointers
void reverselinkedlistslidingpointers(struct node *p)
{
	struct node *q=NULL,*r=NULL;
	while(p)
	{
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	first=q;
}
//recursive method to reverse the linked list
void recursivereserve(struct node *q,struct node *p)
{
	if(p)
	{
		recursivereserve(p,p->next);
		p->next=q;
	}
	else
		first=q;
}
//concatenation of two linked list for this we have to create one more linked list 
void concatenate2linkedlists(struct node *p,struct node *q)
{
	while(p->next)
		p=p->next;
	p->next=q;
	q=NULL;
}
//merge two linked list
void mergelinkedlist(struct node *p,struct node *q)
{
	struct node *last,*third=NULL;
	if(p->data<q->data)
	{
		third=last=p;
		p=p->next;
		last->next=NULL;
	}
	else
	{
		third=last=q;
		q=q->next;
		last->next=NULL;
	}
	while(p&&q)
	{
		if(p->data<q->data)
		{
			last->next=p;
			last=p;
			p=p->next;
			last->next=NULL;
		}
		else
		{
			last->next=q;
			last=q;
			q=q->next;
			last->next=NULL;
		}
	}
	if(p)
		last->next=p;
	else
		last->next=q;
}
//checking the linked list is linear or looping 
int isloop(struct node *p)
{
	struct node *q;
	p=q=first;
	do
	{
		p=p->next;
		q=q->next;
		q=q?q->next:NULL;
	}while(p&&q and p!=q);
	return p==q?true:false;
}
int main()
{
	int A[]={1,2,3,5,7};
	createA(A,5);
	int B[]={2,4,6,8,10};
	createB(B,5);
	/*cout<<"Normal display : ";
	normaldisplay(first);
	cout<<endl<<"Recursive display : ";
	recursivedisplay(first);
	cout<<endl<<"Reverse recursive display : ";
	reverserecursivedisplay(first);
	cout<<endl<<"Normal count : "<<normalcount(first)<<endl;
	cout<<"Recursive count : "<<recursivecount(first)<<endl;
	cout<<"Normal Add : "<<normaladd(first)<<endl;
	cout<<"Recursive Add : "<<recursiveadd(first)<<endl;
	cout<<"Normal Maximum : "<<normalmax(first)<<endl;
	cout<<"Recursive 1 Maximum : "<<recursivemax1(first)<<endl;
	cout<<"Recursive 2 Maximum : "<<recursivemax2(first)<<endl;
	cout<<"Normal Miniimum : "<<normalmin(first)<<endl;	
	cout<<"Recursive 1 Minimum : "<<recursivemin1(first)<<endl;
	cout<<"Recursive 2 Minimum : "<<recursivemin2(first)<<endl;
	struct node *temp;//create temp node to get the return value of the search function
	temp=normalsearch(first,5);
	if(temp)
	{
		cout<<"Normal Search element is found : "<<temp->data<<endl;
	}
	else
	{
		cout<<"Normal Search element is not found "<<endl;
	}
	temp=recursivesearch(first,5);
	if(temp!=NULL)
	{
		cout<<"Recursive Search element is found : "<<temp->data<<endl;
	}
	else
	{
		cout<<"Recursive Search element is not found "<<endl;
	}
	temp=movetoheadsearch(first,5);
	temp=movetoheadsearch(first,4);
	if(temp!=NULL)
	{
		cout<<"Move to head Search element is found : "<<temp->data<<endl;
	}
	else
	{
		cout<<"Move to head Search element is not found "<<endl;
	}
	normaldisplay(first);cout<<endl;//to check whether the movetohead function change the key node 	
	insertatfirst(first);
	normaldisplay(first);cout<<endl;
	insertatposition(first);
	normaldisplay(first);cout<<endl;
	insert(first);//combination of insertatfirst and insertatpositon
	normaldisplay(first);
	insertatlast(first);//inserting element in the linked list at last only
	normaldisplay(first);cout<<endl;
	insertinsortedlinkedlist(first);//inserting element in the sorted linked list 
	normaldisplay(first);cout<<endl;
	insertinsortedlinkedlist(first);//inserting element in the sorted linked list 
	normaldisplay(first);cout<<endl;
	deleteatfirst(first);
	normaldisplay(first);cout<<endl;
	int d=deleteatanypositionexp0(first);
	normaldisplay(first);cout<<endl;
	cout<<"The deleted element is "<<d<<endl;
	deleteatanyposition(first);cout<<endl;
	normaldisplay(first);cout<<endl;
	checksortlinkedlist(first);
	removeduplicate(first);
	normaldisplay(first);
	reverselinkedlistforloop(first);
	normaldisplay(first);cout<<endl;
	reverselinkedlistwhileloop(first);
	normaldisplay(first);cout<<endl;
	reverselinkedlistslidingpointers(first);
	normaldisplay(first);cout<<endl;
	recursivereserve(NULL,first);
	normaldisplay(first);cout<<endl;
	concatenate2linkedlists(first,second);
	normaldisplay(first);cout<<endl;
	mergelinkedlist(first,second);
	normaldisplay(first);cout<<endl;
	//this code is to make the linked list looping 
	struct node *t1,*t2;
	t1=first->next->next;
	t2=first->next->next->next->next;
	t2->next=	t1;*/
	if(isloop(first))
		cout<<"The linked list is looping";
	else
		cout<<"The linked list is linear";
}
