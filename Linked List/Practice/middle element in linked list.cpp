#include<iostream>
#include<stack>
using namespace std;
struct node //creating node
{
	int data;
	struct node *next;
}*first;
//create the linked list of the array A
void create(int A[],int n)
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
//display the innked list normal
void normaldisplay(struct node *p)
{
	while(p!=NULL)
	{
		cout<<p->data<<"->";
		p=p->next;
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
void middleelement1(struct node *p)
{//this method takes the length of the linked list and make it half and traverse the linked list to half
	int mid=normalcount(p)/2;
	for(int i=0;i<mid;i++)
		p=p->next;
	cout<<"The middle element is "<<p->data<<" and its index is "<<mid;
}
void middleelement2(struct node *p)
{
/* this will take two pointers the first pointer will move two next and second pointer will 
move one next when the first pointer reaches the last node the second pointer will be in 
middle of the linked list */
	struct node *q=first;
	while(q)
	{
		q=q->next;
		if(q)
			q=q->next;
		if(q)
			p=p->next;
	}
	cout<<"The middle element is "<<p->data;
}
/*void middleelement3(struct Node *p)
{
    stack<Node> *s;
    while (p)
	{
        s.push(p);
        p=p->next;
    }
    int length = s.size();
    int popLength =length/2;
    while (popLength){
        s.pop();
        popLength--;
    }
    cout << "Middle Element (Method-III): " << s.top()->data << endl;
}*/
int main()
{
	int A[]={1,2,3,4,5,6};
	create(A,6);
	normaldisplay(first);
	cout<<endl;
	middleelement1(first);
	cout<<endl;
	middleelement2(first);
	cout<<endl;
	//middleelement3(first);
}
