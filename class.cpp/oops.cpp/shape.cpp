/*
Program(04):Create a Class Shape and multiple constructor to calculate the areas of different
shapes.
agrs:area,radius,length,width,base,height
method: displayArea()
*/

#include <iostream>
#include <cmath>

using namespace std;

class Shape {
private:
    double area; // Variable to store the calculated area

public:
    // Constructor for Circle (Area = π * r²)
    Shape(double radius) {
        area = M_PI * radius * radius;
    }

    // Constructor for Rectangle (Area = length * width)
    Shape(double length, double width) {
        area = length * width;
    }

    // Constructor for Triangle (Area = 0.5 * base * height)
    Shape(double base, double height, bool isTriangle) {
        if (isTriangle) {
            area = 0.5 * base * height;
        }
    }

    // Function to display the calculated area
    void displayArea() {
        cout << "Calculated Area: " << area << endl;
    }
};

int main() {
    Shape circle(5.0); // Circle with radius 5
    Shape rectangle(4.0, 6.0); // Rectangle with length 4 and width 6
    Shape triangle(3.0, 8.0, true); // Triangle with base 3 and height 8

    cout << "Circle ";
    circle.displayArea();

    cout << "Rectangle ";
    rectangle.displayArea();

    cout << "Triangle ";
    triangle.displayArea();

    return 0;
}