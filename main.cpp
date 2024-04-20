#include <iostream>
#include "triangle.h"

using namespace std;

// Default Constructor
Triangle::Triangle() : side1(0), side2(0), side3(0) 
{
    cout << "Default Constructor Called" << endl;
}

// Parameterized Constructor
Triangle::Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) 
{
    cout << "Parameterized Constructor Called" << endl;
}

// Copy Constructor
Triangle::Triangle(const Triangle& other) : side1(other.side1), side2(other.side2), side3(other.side3) 
{
    cout << "Copy Constructor Called" << endl;
}

// Destructor
Triangle::~Triangle() 
{
    cout << "Destructor Called" << endl;
}

// Method to calculate perimeter
double Triangle::perimeter() const 
{
    return side1 + side2 + side3;
}

// Method to check if triangle is equilateral
bool Triangle::isEquilateral() const 
{
    return (side1 == side2 && side2 == side3);
}
