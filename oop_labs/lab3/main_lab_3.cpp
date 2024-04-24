#include "triangle.h"
#include <iostream>

using namespace std;

int main() 
{
    const int numTriangles = 3;
    Triangle* triangles[numTriangles];

    // Create triangles using different constructors
    triangles[0] = new Triangle();  // Default Constructor
    triangles[1] = new Triangle(3, 4, 5);  // Parameterized Constructor
    triangles[2] = new Triangle(*triangles[1]);  // Copy Constructor

    // Access and manipulate the created triangles
    for (int i = 0; i < numTriangles; ++i) 
    {
        cout << "Triangle " << i + 1 << " Perimeter: " << triangles[i]->perimeter() << endl;
        cout << "Triangle " << i + 1 << " is " << (triangles[i]->isEquilateral() ? "" : "not ") << "equilateral" << endl;
    }

    // Clean up memory by deleting triangles
    for (int i = 0; i < numTriangles; ++i) 
    {
        delete triangles[i];
    }

    return 0;
}
 