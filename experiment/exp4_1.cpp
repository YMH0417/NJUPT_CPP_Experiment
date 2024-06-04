#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Course {
private:
    string name;
    int number;

public:
    Course() : name(""), number(0) {}

    friend istream& operator>>(istream& in, Course& p);
    friend ostream& operator<<(ostream& out, const Course& p);
};

istream& operator>>(istream& in, Course& p) {
    in >> ws;
    getline(in, p.name, ' ');
    in >> p.number;
    return in;
}

ostream& operator<<(ostream& out, const Course& p) {
    out << setw(30) << left << p.name << setw(5) << p.number;
    return out;
}

int main() {
    ofstream outfile("course.txt");
    if (!outfile) {
        cerr << "Error!" << endl;
        return 1;
    }

    outfile << "高级语言程序设计 3018\n";
    outfile << "面向对象程序设计及c++ 487\n";
    outfile << "程序设计（实践） 2046\n";
    outfile.close();

    ifstream infile("course.txt");
    if (!infile) {
        cerr << "Error!" << endl;
        return 1;
    }

    Course course;
    int count = 0;

    while (infile >> course) {
        cout << course << endl;
        count++;
    }

    cout << "Total: " << count << endl;

    infile.close();
    return 0;
}
