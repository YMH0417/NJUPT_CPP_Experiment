#include <iostream>
using namespace std;

class Point {
private:
    double x, y;
public:
    Point(double x0 = 0, double y0 = 0);
    Point operator++();
    Point operator-(const Point& a);
    friend Point operator+(const Point& a, const Point& b);
    friend Point operator+(const Point& a, double n);
    friend ostream& operator<<(ostream& out, const Point& point);
};

Point::Point(double x0, double y0) {
    x = x0;
    y = y0;
}

Point Point::operator++() {
    ++x;
    ++y;
    return *this;
}

Point Point::operator-(const Point& a) {
    Point temp;
    temp.x = x - a.x;
    temp.y = y - a.y;
    return temp;
}

Point operator+(const Point& a, const Point& b) {
    Point temp;
    temp.x = a.x + b.x;
    temp.y = a.y + b.y;
    return temp;
}

Point operator+(const Point& a, double n) {
    Point temp;
    temp.x = a.x + n;
    temp.y = a.y + n;
    return temp;
}

ostream& operator<<(ostream& out, const Point& point) {
    out << "(" << point.x << ", " << point.y << ")" << endl;
    return out;
}

int main() {
    Point pt1(10.5, 20.8), pt2(-5.3, 18.4), pt3;
    cout << "original pt1,pt2,pt3 are:\n";
    cout << pt1 << pt2 << pt3;
    pt3 = pt1 + 100.8;
    cout << "after pt3=pt1+100.8, pt3 is:" << pt3;
    pt3 = pt1 + pt2;
    cout << "after pt3=pt1+pt2, pt3 is:" << pt3;
    pt3 = ++pt1;
    ++pt2;
    cout << "after ++ pt1,pt2,pt3 are:\n";
    cout << pt1 << pt2 << pt3;
    pt3 = pt1 - pt2;
    cout << "after pt3=pt1-pt2, pt3 is:" << pt3;
    return 0;
}
