#include <iostream> 
using namespace std; 
  
int main() 
{ 
    int a[2][2];    
	int b[2][2];     
	int c[2][2];	
  
    cout<<"Enter the first matrix elements :"<<endl;
    for(int i=0; i<2;i++)
    {
    	for(int j=0;j<2;j++)
    	{
    		cin>>*(*(a+i)+j);
		}
	}
	for(int i=0; i<2;i++)
    {
    	for(int j=0;j<2;j++)
    	{
    		cout<<*(*(a+i)+j)<<"\t";
		}
		cout<<endl;
	}
	
	cout<<"Enter the second matrix elements :"<<endl;
    for(int i=0; i<2;i++)
    {
    	for(int j=0;j<2;j++)
    	{
    		cin>>*(*(b+i)+j);
		}
	}
	for(int i=0; i<2;i++)
    {
    	for(int j=0;j<2;j++)
    	{
    		cout<<*(*(b+i)+j)<<"\t";
		}
		cout<<endl;
	}
	
	cout<<"m of the matrix is :"<<endl;
	
	for(int i=0; i<2;i++)
    {
    	for(int j=0;j<2;j++)
    	{
    		c[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
			
                c[i][j] += a[i][k] * b[k][j];
        	}
        }
        cout<<endl;
	}
		
		

	
	for(int i=0; i<2;i++)
    {
    	for(int j=0;j<2;j++)
    	{
    		cout<<*(*(c+i)+j)<<"\t";
		}
		cout<<endl;
	}
	
	
	
}
