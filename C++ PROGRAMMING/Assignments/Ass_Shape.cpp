#include<iostream>
using namespace std;

class shape
{
	public:
		virtual void display()
		{
			cout<<"Shape"<<endl;
		}
		
		virtual double area()=0;

};

class circle:public shape
{
	double radius;
	float pi = 3.14,res;
	public:
		circle()
		{
			radius=0;
		}
		
		circle(int r)
		{
			radius = r;
		}
		
		void display()
		{
			cout<<"radius is :"<<radius<<endl;
			cout<<"area of circle is :"<<area()<<endl;
		}
		
		double area()
		{
			res = (float)pi*radius*radius;
			return res;
		}
};

class rectangle:public circle
{
	double length, width;
	public:
		rectangle()
		{
			length = width=0;
		}
		rectangle(double r,double l,double w):circle(r)
		{
			length = l;
			width = w;
		}
		
		void display()
		{
			circle::area();
			cout<<"length is :"<<length<<endl;
			cout<<"width is :"<<width<<endl;
			cout<<"area of rectangle is :"<<area()<<endl;
		}
		
		double area()
		{
			return length*width;
		}
	
		
};

int main()
{
	shape* ptr = new circle(4);
	ptr->display();
	ptr->area();
	
	cout<<"-----------------------------------------------------"<<endl;
	
	ptr = new rectangle(4.3,5.5,7.6);
	ptr->display();
	ptr->area();
	
	cout<<"-----------------------------------------------------"<<endl;
}
