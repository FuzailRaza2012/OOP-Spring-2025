#include <iostream>
#include <string>

using namespace std;

class Shape{
	public:
		float position;
		string color;
		int borderThickness;
		
		virtual void draw(){
			cout << "rendering..." << endl;
		}
		
		virtual void calculateArea(){
			cout << "Calculating Area..." << endl;
		}
		
		virtual void calculatePerimeter(){
			cout << "Calculating Perimeter..." << endl;
		}
};

class Circle: virtual public Shape{
	public:
		float radius;
		float centerPosition;
		
		void draw() override{
			cout << "drawing circle..." << endl;
		}
		
		void calculateArea() override{
			cout << "Area of Circle: " << 3.142 * radius * radius << endl;
		}
		
		void calculatePerimeter() override{
			cout << "Perimeter of Circle: " << 2 * 3.142 * radius << endl;
		}
};

class Rectangle: virtual public Shape{
	public:
		float width;
		float height;
		float topLeftCorner;
		
		void draw() override{
			cout << "drawing Rectangle..." << endl;
		}
		
		void calculateArea() override{
			cout << "Area of Rectangle: " << width * height << endl;
		}
		
		void calculatePerimeter() override{
			cout << "Perimeter of Rectangle: " << 2 * (width + height) << endl;
		}
};

class Triangle: virtual public Shape{
	public:
		float height;
		float hypotenuse;
		float base;
		
		void draw() override{
			cout << "drawing Triangle..." << endl;
		}
		
		void calculateArea() override{
			cout << "Area of Triangle: " << 0.5 * base * height << endl;
		}
		
		void calculatePerimeter() override{
			cout << "Perimeter of Triangle: " << (base + hypotenuse + height) << endl;
		}
};

class Polygon: virtual public Shape{
	public:
		int sides;
		float length;
		
		void draw() override{
			cout << "drawing polygon..." << endl;
		}
		
		void calculateArea() override{
			cout << "Area of Polygon depends on the type... "<< endl;
		}
		
		void calculatePerimeter() override{
			cout << "Perimeter of Polygon: " << sides * length << endl;
		}
};

int main() {
    Circle c;
    c.radius = 5;
    c.draw();
    c.calculateArea();
    c.calculatePerimeter();
    
    Rectangle r;
    r.width = 4;
    r.height = 6;
    r.draw();
    r.calculateArea();
    r.calculatePerimeter();
    
    Triangle t;
    t.base = 3;
    t.height = 4;
    t.hypotenuse = 5;
    t.draw();
    t.calculateArea();
    t.calculatePerimeter();
    
    Polygon p;
    p.sides = 5;
    p.length = 3;
    p.draw();
    p.calculateArea();
    p.calculatePerimeter();
    
    return 0;
}
