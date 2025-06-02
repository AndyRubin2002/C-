#include <iostream> 
using namespace std; 
  
int main() 
{ 
    int a[3][3];
    int b[3][3];
    
    cout<<"Enter the elements :"<<endl;
    for(int i=0; i<3;i++)
    {
    	for(int j=0;j<3;j++)
    	{
    		cin>>*(*(a+i)+j);
		}
	}
	for(int i=0; i<3;i++)
    {
    	for(int j=0;j<3;j++)
    	{
    		cout<<*(*(a+i)+j)<<"\t";
		}
		cout<<endl;
	}
	
	cout<<"transpose matrix :"<<endl;
    for(int i=0; i<3;i++)
    {
    	for(int j=0;j<3;j++);
    	{
    		b[i][j]=a[j][i];
		}
	}
	for(int i=0; i<3;i++)
    {
    	for(int j=0;j<3;j++)
    	{
    		cout<<*(*(b+i)+j)<<"\t";
		}
		cout<<endl;
	}
	
	
	
}
