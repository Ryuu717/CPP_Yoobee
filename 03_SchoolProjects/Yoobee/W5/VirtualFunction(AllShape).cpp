#include <iostream>
using namespace std;


//abstraction class (includes at least one virtual function)
class Shape
{
public:
    virtual void draw() //with virtual keyword
    // void draw() //without virtual keyword
    {
    	cout << "Shape" << endl;
    }
   
};
class Triangle :public Shape
{
public:
    void draw()
    {
    	cout << "Draw Triangle" << endl;
    }	
};
class Circle :public Shape
{
public:
    void draw()
    {
    	cout << "Draw Circle" << endl;
    }
};

class Square :public Shape
{
public:
    void draw()
    {
    	cout << "Draw Square" << endl;
    }
};
 class Pentagon :public Shape
 {
    	public:
        	void draw()
        	{
            	cout << "Draw Pentagon" << endl;
       	}
 };
class Line :public Shape
{
public:
    void draw()
    {
    	cout << "Draw Line" << endl;
    }
};


int main()
{
    Triangle t1;
    Circle c1;
    Square s1;
    Pentagon p1;
    Line l1;

 // Pointer array
    Shape* ptr[5] = {&t1,&c1,&s1,&p1,&l1};         
    for (int j = 0; j < 5; j++)
    	ptr[j]->draw();
     return 0;
}




