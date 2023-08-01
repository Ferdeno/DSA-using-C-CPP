#include<iostream>
using namespace std;
void perm(char S[],int low,int high)
{
	if(low==high)
	{
		printf("%s",S);
		printf("\n");
	}
	else
	{
		for(int i=low;i<=high;i++)
		{
			swap(S[low],S[i]);
			perm(S,low+1,high);
			swap(S[low],S[i]);
		}
	}
}
int main()
{
	char S[5]={'A','C','B'};
	perm(S,0,2);
}
