#include<iostream>
using namespace std;

class Time {
private:

    int Hour, Minute, Second;
public:
    Time(int h = 0, int m = 0, int s = 0);
    Time(const Time& ob);
    ~Time();
    void ChangeTime(int h, int m, int s);
    int GetHour();
    int GetMinute();
    int GetSecond();
    void PrintTime();
    void IncreaseOneSecond();
};

Time::Time(int h, int m, int s) {
    Hour = h;
    Minute = m;
    Second = s;
    cout << "Constructing..." << endl;
}

Time::Time(const Time& ob) {
    cout << "Copy constructing..." << endl;
    Hour = ob.Hour;
    Minute = ob.Minute;
    Second = ob.Second;
}

Time::~Time() {
    cout << "Destructing..." << endl;
}

void Time::ChangeTime(int h, int m, int s) {
    Hour = h;
    Minute = m;
    Second = s;
}

int Time::GetHour() {
    return Hour;
}

int Time::GetMinute() {
    return Minute;
}

int Time::GetSecond() {
    return Second;
}

void Time::PrintTime() {
    cout << Hour << ":" << Minute << ":" << Second << endl;
}

void Time::IncreaseOneSecond() {
    if (Second < 59)
        Second++;
    else {
        Second = 0;
        if (Minute < 59)
            Minute++;
        else {
            Minute = 0;
            if (Hour < 23)
                Hour++;
            else
                Hour = 0;
        }
    }
}

void f1(Time t)
{
    t.PrintTime();
}

void f2(Time& t)
{
    t.PrintTime();
}

void f3(Time* t)
{
    t->PrintTime();
}

int main() {
    Time t1;
    t1.PrintTime();

    Time t2(11);
    t2.PrintTime();

    Time t3(11, 45);
    t3.PrintTime();

    Time t4(11, 45, 14);
    t4.PrintTime();

    t1.ChangeTime(23, 59, 59);
    cout << "ChangeTime " << t1.GetHour() << ":" << t1.GetMinute() << ":" << t1.GetSecond() << endl;
    t1.IncreaseOneSecond();
    cout << "After IncreaseOneSecond " << t1.GetHour() << ":" << t1.GetMinute() << ":" << t1.GetSecond() << endl;

    t4.ChangeTime(14, 45, 11);
    cout << "ChangeTime " << t4.GetHour() << ":" << t4.GetMinute() << ":" << t4.GetSecond() << endl;
    t4.IncreaseOneSecond();
    cout << "After IncreaseOneSecond " << t4.GetHour() << ":" << t4.GetMinute() << ":" << t4.GetSecond() << endl;

    cout << "Start f" << endl;
    cout << "Function f1" << endl;
    Time t5;
    f1(t5);
    cout << "Function f2" << endl;
    Time t6;
    f2(t6);
    cout << "Function f3" << endl;
    Time t7;
    f3(&t7);
    cout << "End f" << endl;
}
