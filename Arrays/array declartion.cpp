#include<iostream>
using namespace std;
int main()
{
	int a=0; //scalar variable 
	int x[5]={1,2,3,4,5};//vector variable
	int y[5]={1,2};//remaining value will be initialize by 0
	int z[]={1,2,3,4,5};//it automatically creates it size
	cout<<z[3]<<endl;
	cout<<4[y]<<endl;
	cout<<*(x)<<endl;//using pointer displaying
	cout<<*(x+1)<<endl;
	cout<<*(x+2)<<endl;

	
}
