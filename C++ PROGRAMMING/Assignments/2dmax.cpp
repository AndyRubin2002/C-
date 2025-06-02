#include<iostream>
using namespace std;

int main()
{
	int a[3][3];
	int max=0, row = 0, col = 0;
	cout<<"Enter the elements of 2array :"<<endl;
	
    for(int i=0; i<3;i++)
    {
    	for(int j=0;j<3;j++)
    	{
    		cin>>a[i][j];
		}
	}
	for(int i=0; i<3;i++)
    {
    	for(int j=0;j<3;j++)
    	{
    		cout<<a[i][j]<<"\t";
    		if(a[i][j] > max){
    			max = a[i][j];
    			row = i;
    			col = j;
			}
		}
		cout<<endl;
	}
	cout<<"miximum number is :"<< max<<endl<<"index of maximum numbar is : "<<row<<col;
}
