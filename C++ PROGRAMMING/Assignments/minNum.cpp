#include<iostream>
using namespace std;

int main()
{
	int a[20];
	int i,b;
	cout<<"Enter the number :"<<endl;
	cin>>b;
	cout<<"Enter the elements of array :"<<endl;
	
	for(i=0;i<b;i++)
	{
		cin>>*(a+i);
	}
	int min = *(a+0);
	for(i=1;i<b;i++)
	{
		if(*(a+i)<min)
		{
			min=*(a+i);
		}
	}
	cout<<"minimum number is :"<< min;
}
