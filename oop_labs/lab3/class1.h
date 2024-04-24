#ifndef CLASS_H
#define CLASS_H

class Triangle 
{
private:
    double side1;
    double side2;
    double side3;

public:
    Triangle();  // Default Constructor
    Triangle(double s1, double s2, double s3);  // Parameterized Constructor
    Triangle(const Triangle& other);  // Copy Constructor
    ~Triangle();  // Destructor

    double perimeter() const;
    bool isEquilateral() const;
};

#endif
