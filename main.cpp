#include <iostream>

using namespace std;

class Cylinder {
private:
    double radius;
    double height;
    double pi = 3.14159;

public:
    Cylinder(double r, double h) : radius(r), height(h) {}

    double getRadius() const {
        return radius;
    }

    void setRadius(double r) {
        if (r > 0)
            radius = r;
        else
            cout << "Error: Radius must be positive." << endl;
    }

    double getHeight() const {
        return height;
    }

    void setHeight(double h) {
        if (h > 0)
            height = h;
        else
            cout << "Error: Height must be positive." << endl;
    }

    // Метод для обчислення об'єму циліндра
    double calculateVolume() const {
        return pi * radius * radius * height;
    }

    // Метод для обчислення площі бічної поверхні циліндра
    double calculateLateralSurfaceArea() const {
        return 2 * pi * radius * height;
    }

    // Метод для обчислення загальної поверхні циліндра
    double calculateTotalSurfaceArea() const {
        return 2 * pi * radius * (radius + height);
    }
};

int main() {
    Cylinder cylinder(3.0, 5.0);

    cout << "Radius: " << cylinder.getRadius() << endl;
    cout << "Height: " << cylinder.getHeight() << endl;

    cylinder.setRadius(4.0);
    cylinder.setHeight(6.0);

    cout << "Updated Radius: " << cylinder.getRadius() << endl;
    cout << "Updated Height: " << cylinder.getHeight() << endl;

    cout << "Volume: " << cylinder.calculateVolume() << endl;
    cout << "Lateral Surface Area: " << cylinder.calculateLateralSurfaceArea() << endl;
    cout << "Total Surface Area: " << cylinder.calculateTotalSurfaceArea() << endl;

    cylinder.setRadius(10.0);
    cylinder.setHeight(7.0);
    cout << "Lateral Surface Area: " << cylinder.calculateLateralSurfaceArea() << endl;

    return 0;
}
