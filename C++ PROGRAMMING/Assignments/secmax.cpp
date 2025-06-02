#include<iostream>
using namespace std;

int main()
{
	int a[20]={1,5,3,7};
	int i,b, max=0, max2 = 0;
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
			max2 = max;
			max=*(a+i);
		}
	}
	cout<<"Second miximum number is :"<< max2;
}
