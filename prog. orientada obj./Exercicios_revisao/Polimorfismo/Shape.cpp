#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3,14;

class Shape{
    
    public:
        Shape(){}
        virtual  double area() = 0; // polimorfismo - virtual puro
        virtual  double perimeter() = 0;
};

class Circle :: public Shape(){
    private:
        double radius;
    public:
        Circle() : Shape(){}
        Circle(double rad):radius(rad){
            rad = nullptr;
        }
        double area(){ return PI * pow(radius, 2); } //pow = potencia 
        double perimeter(){return 2 * PI * radius;}
}

class Rectangle :: public Shape(){
    private:
        double length;
        double width;
    public:
        Rectangle(double len, double wid) : length(len), width(wid){}
        double area(){ return length * width;}
        double perimeter(){ return 2* (length + width); }
}

