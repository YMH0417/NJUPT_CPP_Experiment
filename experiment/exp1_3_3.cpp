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
    void VisitGirl(Girl& g);
    friend class Girl;
};

class Girl {
private:
    string Name;
    int Age;
public:
    Girl(string N = "ABC", int A = 18);
    void Output();
    void VisitBoy(Boy& b);
    friend class Boy;
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

void Girl::VisitBoy(Boy& boy) {
    cout << "Boy's name: " << boy.Name << endl;
    cout << "Boy's age: " << boy.Age << endl;
}

void Boy::VisitGirl(Girl& girl) {
    cout << "Girl's name: " << girl.Name << endl;
    cout << "Girl's age: " << girl.Age << endl;
}

int main() {
    Girl g("yuxiaojing", 22);
    Boy b("yuminghong", 19);
    g.VisitBoy(b);
    b.VisitGirl(g);
    b.Output();
    g.Output();
    return 0;
}
