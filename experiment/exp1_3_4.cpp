#include<iostream>
#include<string>
using namespace std;

class Girl;

class Boy {
private:
    string Name;
    int Age;
public:
    Boy(string N = "ABC", int A = 18);
    void Output();
    friend void VisitBoyGirl(Boy& boy, Girl& girl);
};

class Girl {
private:
    string Name;
    int Age;
public:
    Girl(string N = "ABC", int A = 18);
    void Output();
    friend void VisitBoyGirl(Boy& boy, Girl& girl);
};

Girl::Girl(string N, int A) {
    Name = N;
    Age = A;
}

void Girl::Output() {
    cout << "Girl's name: " << Name << endl;
    cout << "Girl's age: " << Age << endl;
}

Boy::Boy(string N, int A) {
    Name = N;
    Age = A;
}

void Boy::Output() {
    cout << "Boy's name: " << Name << endl;
    cout << "Boy's age: " << Age << endl;
}

void VisitBoyGirl(Boy& boy, Girl& girl) {
    cout << "Boy's name: " << boy.Name << endl;
    cout << "Boy's age: " << boy.Age << endl;
    cout << "Girl's name: " << girl.Name << endl;
    cout << "Girl's age: " << girl.Age << endl;
}

int main() {
    Girl g("yuxiaojing", 22);
    Boy b("yuminghong", 19);
    VisitBoyGirl(b, g);
    return 0;
}
