#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

void CreateFile(const char* s) {
    ofstream outfile(s);
    if (!outfile) {
        cout << "Error!" << endl;
        return;
    }

    srand(time(0));
    for (int i = 0; i < 50; ++i) {
        char ch = rand() % 52;
        if (ch < 26) {
            ch += 'A';
        }
        else {
            ch += 'a' - 26;
        }
        outfile.put(ch);
    }

    outfile.close();
}

void ReadFile(const char* s) {
    ifstream infile(s);
    if (!infile) {
        cout << "Error!" << endl;
        return;
    }
    char ch;
    while (infile.get(ch))
        cout << ch;
    cout << endl;
    infile.close();
}

void Change(const char* s1, const char* s2) {
    ifstream inf(s1);
    if (!inf) {
        cout << "Error!" << endl;
        return;
    }
    ofstream of(s2);
    if (!of) {
        cout << "Error!" << endl;
        return;
    }
    char ch;
    while (inf.get(ch)) {
        if (ch >= 'a' && ch <= 'z') {
            ch -= 32;
        }
        of.put(ch);
    }
    inf.close();
    of.close();
}

int main() {
    CreateFile("ff.txt");
    ReadFile("ff.txt");
    Change("ff.txt", "ff2.txt");
    ReadFile("ff2.txt");
    return 0;
}
