#include <iostream> 
using namespace std; 
  
int main() 
{ 
//   int a[2][2];    
//	int b[2][2];     
//	int c[2][2];	
//  
//    cout<<"Enter the first matrix elements :"<<endl;
//    for(int i=0; i<2;i++)
//    {
//    	for(int j=0;j<2;j++)
//    	{
//    		cin>>*(*(a+i)+j);
//		}
//		cout<<endl;
//	}
//	for(int i=0; i<2;i++)
//    {
//    	for(int j=0;j<2;j++)
//    	{
//    		cout<<*(*(a+i)+j)<<"\t";
//		}
//		cout<<endl;
//	}
//	
//	cout<<"Enter the second matrix elements :"<<endl;
//    for(int i=0; i<2;i++)
//    {
//    	for(int j=0;j<2;j++)
//    	{
//    		cin>>*(*(b+i)+j);
//		}
//		cout<<endl;
//	}
//	for(int i=0; i<2;i++)
//    {
//    	for(int j=0;j<2;j++)
//    	{
//    		cout<<*(*(b+i)+j)<<"\t";
//		}
//		cout<<endl;
//	}
//	
//	cout<<"Addition of the matrix is :"<<endl;
//	
//	for(int i=0; i<2;i++)
//    {
//    	for(int j=0;j<2;j++)
//    	{
//    		c[i][j]= a[i][j] + b[i][j];
//		}
//		cout<<endl;
//	}
//	
//	for(int i=0; i<2;i++)
//    {
//    	for(int j=0;j<2;j++)
//    	{
//    		cout<<*(*(c+i)+j)<<"\t";
//		}
//		cout<<endl;
//	}



//int a[3][3]={1,2,3,4,5,6,7,8,9};
//int b[3][3]={1,2,3,4,5,6};
//int c[3][3];
//int i;
//for (i=0;i<3;i++){
//	for (int j=0;j<3;j++){
//		c[i][j]= a[i][j]+b[i][j];
//	}
//}
//for (i=0;i<3;i++){
//	for (int j=0;j<3;j++){
//		cout<<b[i][j];
//	}
//	cout<<endl;
//}

int a[3][3]={{1,2},{4,5},{7,8,9}}; 
for(int i=0;i<3;i++){
	for(int j = 0;j<3;j++){
		cout<<a[i][j];
	}
	cout<<endl;
}


	
	
	
}
