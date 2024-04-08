#include<iostream>
using namespace std;
class Time
{
private:
    int Hour, Minute, Second;
public:
    Time(int h = 0, int m = 0, int s = 0);
    Time(const Time &ob);
    ~Time();
    void ChangeTime(int h, int m, int s);
    int GetHour();
    int GetMinute();
    int GetSecond();
    void PrintTime();
};

Time::Time(int h, int m, int s)
{
    Hour = h;
    Minute = m;
    Second = s;
    cout << "Constructing..." << endl;
}
Time::Time(const Time& ob)
{
    cout << "Copy constructing..." << endl;
    Hour = ob.Hour;
    Minute = ob.Minute;
    Second = ob.Second;
}
Time::~Time()
{
    cout << "Destructing..." << endl;
}
void Time::ChangeTime(int h, int m, int s)
{
    Hour = h;
    Minute = m;
    Second = s;
}
int Time::GetHour()
{
    return Hour;
}
int Time::GetMinute()
{
    return Minute;
}
int Time::GetSecond()
{
    return Second;
}
void Time::PrintTime()
{
    cout << Hour << ":" << Minute << ":" << Second << endl;
}

int main()
{
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
    t4.ChangeTime(14, 45, 11);    
    cout << "ChangeTime " << t4.GetHour() << ":" << t4.GetMinute() << ":" << t4.GetSecond() << endl;
}
