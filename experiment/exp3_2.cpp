#include<iostream>
#define PI 3.14
using namespace std;

class Container {
protected:
    double radius;
public:
    Container(double r) {
        radius = r;
    }
    virtual double area() = 0;
    virtual double volume() = 0;
    virtual void print() = 0;
};

class Cube : public Container {
protected:
    double length;
public:
    Cube(double l) : Container(0), length(l) {}
    double area() {
        return 6 * length * length;
    }
    double volume() {
        return length * length * length;
    }
    void print() {
        cout << "Cube" << endl;
        cout << "Length: " << length << endl;
        cout << "Cube Surface Area: " << area() << endl;
        cout << "Cube Volume: " << volume() << endl << endl;
    }
};

class Sphere : public Container {
public:
    Sphere(double r) : Container(r) {
        radius = r;
    }
    double area() {
        return 4 * PI * radius * radius;
    }
    double volume() {
        return 4.0 * PI * radius * radius * radius / 3.0;
    }
    void print() {
        cout << "Sphere" << endl;
        cout << "Radius: " << radius << endl;
        cout << "Sphere Surface Area: " << area() << endl;
        cout << "Sphere Volume: " << volume() << endl << endl;
    }
};

class Cylinder : public Container {
protected:
    double height;
public:
    Cylinder(double radius, double h) : Container(radius), height(h) {}
    double area() {
        return 2 * PI * radius * height + radius * radius * 2 * PI;
    }
    double volume() {
        return PI * radius * radius * height;
    }
    void print() {
        cout << "Cylinder" << endl;
        cout << "Height: " << height << " Radius: " << radius << endl;
        cout << "Cylinder Surface Area: " << area() << endl;
        cout << "Cylinder Volume: " << volume() << endl;
    }
};

int main() {
    Container* p;
    Cube cu(13);
    Sphere sp(14);
    Cylinder cy(13, 14);
    p = &cu;
    p->print();
    p = &sp;
    p->print();
    p = &cy;
    p->print();
    return 0;
}
