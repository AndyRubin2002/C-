#include<iostream>
using namespace std;

int main()
{
	int a[20];
	int i,b, max=0;
	cout<<"Enter the number :"<<endl;
	cin>>b;
	cout<<"Enter the elements of array :"<<endl;
	
	for(i=0;i<b;i++)
	{
		cin>>*(a+i);
	}
	for(i=0;i<b;i++)
	{
		if(*(a+i)>max)
		{
			max=*(a+i);
		}
	}
	cout<<"miximum number is :"<< max;
}
