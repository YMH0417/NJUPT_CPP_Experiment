#include<iostream>
using namespace std;
class Vehicle
{
protected:
	int MaxSpeed;
	int Weight;
public:
	Vehicle(int m, int w)
	{
		MaxSpeed = m;
		Weight = w;
		cout << "Constructing Vehicle¡­\n";
	}
	~Vehicle()
	{
		cout << "Destructing Vehicle¡­\n";
	}
	void Run()
	{
		cout << "The vehicle is running!\n";
	}
	void Stop()
	{
		cout << "Please stop running!\n";
	}
	void Show()
	{
		cout << "It\'s maxspeed is:" << MaxSpeed << endl;
		cout << "It\'s weight is:" << Weight << endl;
	}
};
class Bicycle :virtual public Vehicle
{
protected:
	int Height;
public:
	Bicycle(int m, int w, int h) :Vehicle(m, w)
	{
		Height = h;
		cout << "Constructing Bicycle¡­\n";
	}
	~Bicycle()
	{
		cout << "Destructing Bicycle¡­\n";
	}
	void Show()
	{
		Vehicle::Show();
		cout << "It\'s height is:" << Height << endl;
	}
};
class Car :virtual public Vehicle
{
protected:
	int SeatNum;
public:
	Car(int m, int w, int s) :Vehicle(m, w)
	{
		SeatNum = s;
		cout << "Constructing Car¡­\n";
	}
	~Car()
	{
		cout << "Destructing Car¡­\n";
	}
	void Show()
	{
		Vehicle::Show();
		cout << "It\'s SeatNum is:" << SeatNum << endl;
	}
};
class MotorCycle :public Bicycle, public Car
{
public:
	MotorCycle(int m, int w, int h, int s) :Bicycle(m, w, h), Car(m, w, s), Vehicle(m, w)
	{
		cout << "Constructing MotorCycle¡­\n";
	}
	~MotorCycle()
	{
		cout << "Destructing MotorCycle¡­\n";
	}
	void Show()
	{
		cout << "It\'s maxspeed is:" << MaxSpeed << endl;
		cout << "It\'s weight is:" << Weight << endl;
		cout << "It\'s height is:" << Height << endl;
		cout << "It\'s SeatNum is:" << SeatNum << endl;
	}
};
int main()
{
	Bicycle b(15, 75, 60);
	b.Run();
	b.Stop();
	b.Show();
	Car c(120, 1500, 5);
	c.Run();
	c.Stop();
	c.Show();
	MotorCycle mc(60, 240, 80, 2);
	mc.Run();
	mc.Stop();
	mc.Show();
	return 0;
}