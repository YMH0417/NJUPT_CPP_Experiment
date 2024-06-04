#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

class Student {
private:
    char num[20];
    char name[20];
    char sex[10];
    double score;

public:
    Student() {}
    Student(const char* nu, const char* na, const char* se, double s) {
        strcpy_s(num, sizeof(num), nu);
        strcpy_s(name, sizeof(name), na);
        strcpy_s(sex, sizeof(sex), se);
        score = s;
    }

    friend ostream& operator<<(ostream& out, const Student& s) {
        out << setw(10) << s.num << setw(15) << s.name << setw(4) << s.sex << setw(8) << s.score << endl;
        return out;
    }
};

void CreateBiFile(const char* filename) {
    ofstream out(filename, ios::binary);
    Student stu[3] = { Student("B23041011", "MinghongYu", "M", 99.01),
                       Student("B23041012", "YimingWang", "M", 79.49),
                       Student("B23041013", "YimingFang", "M", 84.51)};
    out.write((char*)stu, sizeof(Student) * 3);
    out.close();
}

void ReadBiFile(const char* filename) {
    Student stu[10];
    int i = 0;
    ifstream in(filename, ios::binary);
    while (in.read((char*)&stu[i], sizeof(Student))) {
        i++;
    }
    for (int j = 0; j < i; j++) {
        cout << stu[j];
    }
    in.close();
}

int main() {
    CreateBiFile("stu.dat");
    ReadBiFile("stu.dat");
    return 0;
}
