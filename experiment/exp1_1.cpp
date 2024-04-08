#include <iostream>
#include <string>
using namespace std;

class BookCard {
private:
    string id;
    string stuName;
    int number;

public:
    BookCard(string id = "", string stuName = "", int number = 0) {
        this->id = id;
        this->stuName = stuName;
        this->number = number;
    }

    void display() {
        cout << id << " " << stuName << " " << number << endl;
    }

    bool borrow() {
        if (number < 10) {
            number++;
            return true;
        }
        else {
            return false;
        }
    }
};

void f(BookCard& bk) {
    if (!bk.borrow()) {
        bk.display();
        cout << "you have borrowed 10 books, can not borrow any more!" << endl;
    }
    else {
        bk.display();
    }
}

int main() {
    BookCard bk1("B20190620", "东平", 10), bk2("B19010250", "雪峰", 4);
    f(bk1);
    f(bk2);

    return 0;
}
