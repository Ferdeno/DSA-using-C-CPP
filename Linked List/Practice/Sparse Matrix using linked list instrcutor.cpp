#include<iostream>
using namespace std;
struct node
{
	int col;
	int value;
 	struct node *next;
};
void create1(int m,int n,int z,struct node *A[])
{
 
	int row,column,val; 
	for(int i=0;i<m;i++)/*first we have to initialize the each element
	of the array to NULL*/
	{
	// A[i]=new node; //not needed 
	A[i]=NULL;
	} 
	while(z)
	{ 
		cout<<"Enter ROW__ COLUMN__ VALUE__ : "; 
		cin>>row>>column>>val;
 
		struct node *temp=new node;
 
		temp->col=column;
 
		temp->value=val;
 
		temp->next=NULL;
 
		if(A[row]==NULL)//checking if the element in the list is empty
 
			A[row]=temp;
 
else//if it is not empty move to last element and add the node
 
{
node * travel=A[row]; //changes dont update content in A[row ] use travel var to travel till end
while(travel->next)
 
travel=travel->next;
 
travel->next=temp;
 
}
 
z--;
 
}
 
}
 
 
 
void create2(int m,int n,int z,struct node *B[])
 
{
 
int row,column,val;
 
for(int i=0;i<m;i++)
 
{
 
// B[i]=new node;
 
B[i]=NULL;
 
}
 
while(z)/*getting the non zero elements from user and adding it to the array
 
of linked list repective to its row number*/
 
{
 
cout<<"Enter ROW__ COLUMN__ VALUE__ : ";
 
cin>>row>>column>>val;
 
struct node *temp=new node;
 
temp->col=column;
 
temp->value=val;
 
temp->next=NULL;
 
if(B[row]==NULL)//checking if the element in the list is empty
 
B[row]=temp;
 
else//if it is not empty move to last element and add the node
 
{
 
node * travel=B[row]; //changes dont update content in B[row ] use travel var to travel till end
while(travel->next)
 
travel=travel->next;
 
 
travel->next=temp;
 
 
}
 
z--;
 
}
 
}
 
void create3(int m,struct node *C[])
 
{
 
for(int i=0;i<m;i++)
 
{
 
// C[i]=new node;
 
C[i]=NULL;
 
}
 
}
 
void display(int m,int n,struct node *p[])
 
{
 
for(int i=0;i<m;i++)
 
{
node *t=p[i];
 
for(int j=0;j<n;j++)
 
{
 
if(t && j==t->col)
 
{
 
cout<<t->value<<" ";
 
t=t->next;
 
}
 
else
 
cout<<"0 ";
 
}
 
cout<<endl;
 
}
 
}
 
void add(struct node *A[],struct node *B[],struct node *C[],int m,int n)
 
{
 
int t1,t2;
 
for(int i=0;i<m;i++)
 
{
node *travel1=A[i]; 
node *travel2=B[i];
 
for(int j=0;j<n;j++)
 
{
    
 
if(travel1 && j==travel1->col) //changes
 
{
 
t1=travel1->value;
 
travel1=travel1->next;
 
}
 
else
 
{
 
t1=0;
 
}
 
if(travel2 && j==travel2->col) //changes
 
{
 
t2=travel2->value;
 
travel2=travel2->next;
 
}
 
else
 
{
 
t2=0;
 
}
if(t1+t2){
struct node *temp=new node;
 
temp->col=j;
 
temp->value=t1+t2;
 
temp->next=NULL;
 
 
 
if(C[i]==NULL)
 
{
 
C[i]=temp;
 
}
 
else
 
{
node *t=C[i];
while(t->next)
 
t=t->next;
 
t->next=temp;
 
}
 
}
 
}
 
 
}
 
}
 
int main()
 
{
 
//for sparse matrix 1
 
int m,n,z;
 
cout<<"Enter the dimension of the sparse matrix 1 : ";
 
cin>>m>>n;
 
cout<<"Enter the non zero elements : ";
 
cin>>z;
 
struct node *A[m];//array of linked list
 
create1(m,n,z,A);
 
display(m,n,A);
 
//for sparse matrix 2
 
cout<<"Enter the dimension of the sparse matrix 2 : ";
 
cin>>m>>n;
 
cout<<"Enter the non zero elements : ";
 
cin>>z;
 
struct node *B[m];//array of linked list
 
create2(m,n,z,B);
 
display(m,n,B);
 
struct node *C[m];
 
create3(m,C);
 
add(A,B,C,m,n);
 
cout<<"Addition of two matrix : "<<endl;
 
display(m,n,C);
 
//also kindly deallocate the memory created in heap
 
}
