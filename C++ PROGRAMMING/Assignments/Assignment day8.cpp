#include<iostream>
using namespace std;
class shape{
	public:
		virtual void display(){
			cout<<"shape"<<endl;
		}
	    virtual int calArea()=0;
};

class Square:public shape{
	int side;
	public:
		Square(int s){
		side = s;
	}
		void display();
		int calArea();
	
};

void Square::display(){
	cout<<"Side of square is :"<<side<<endl;
}
int Square::calArea(){
	return side * side;
}
class Rectangle:public Square{
int widht,height;
	public:
	Rectangle(int w,int h,int s):Square(s){
	widht = w;
	height = h;
}
	void display();
	int calArea();
};

void Rectangle::display(){
//	Square::display();
	cout<<endl;
	
	cout<<"Width of rectangle:"<<widht<<endl;
	cout<<"height of rectangle is:"<<height<<endl;
}
int Rectangle::calArea(){
	return widht * height;
}

int main(){
	shape *ptr=new Rectangle(2,4,5);
	ptr->display();
	cout<<"Rectangle Area is:"<<ptr->calArea()<<endl;
	ptr=new Square(2);
	ptr->display();
	cout<<"Square Area is :"<<ptr->calArea()<<endl;
	
}
