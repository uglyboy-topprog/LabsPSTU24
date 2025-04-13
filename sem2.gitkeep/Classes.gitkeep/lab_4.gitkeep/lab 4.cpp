// triadMain.cpp

#include <iostream>
#include "Time.h"
#include "Triad.h"
using namespace std;

void f1(Triad& triad)
{
	triad.setFirst(111111111);
	triad.setSecond(222222222);
	triad.setThird(33333333);
	cout << triad;
}

Triad f2()
{
	Time time(00, 00, 00);
	return time;
}

int main()
{
	Triad num0;
	cin >> num0;
	cout << num0;
	Triad num1(0, 11, 22);
	cout << num1;

	num0 = num1;
	cout << num0;

	Time time;
	cin >> time;
	cout << time;

	return 0;
}

// Triad.cpp

#include "Triad.h"
//конструктор без параметров 
Triad::Triad(void)
{
	first = 0;
	second = 0;
	third = 0;
}
//деструктор
Triad::~Triad(void) {}
//конструктор с параметрами
Triad::Triad(int F, int S, int T)
{
	first = F;
	second = S;
	third = T;
}
//конструктор копирования 
Triad::Triad(const Triad& triad)
{
	first = triad.first;
	second = triad.second;
	third = triad.third;
}
//модификаторы
void Triad::setSecond(int S)
{
	second = S;
}
void Triad::setFirst(int F)
{
	first = F;
}
void Triad::setThird(int T)
{
	third = T;
}
//перегрузка операции присваивания 
Triad& Triad::operator=(const Triad& T)
{
	if (&T == this) return *this;
	first = T.first;
	second = T.second;
	third = T.third;
	return *this;
}
//глобальная функция для ввода
istream& operator<<(istream& in, Triad& T)
{
	cout << "\nFIRST:"; in >> T.first;
	cout << "\nSECOND:"; in >> T.second;
	cout << "\nTHIRD:"; in >> T.third;
	return in;
}
//глобальная функция для вывода 
ostream& operator<<(ostream& out, const Triad& T)
{
	out << "\nFIRST:" << T.first;
	out << "\nSECOND:" << T.second;
	out << "\nTHIRD:" << T.third;
	out << "\n";
	return out;
}

// Time.cpp

#include <iostream>
#include "Time.h"

using namespace std;

Time::Time(void) :Triad()
{
	hour = 0;
	min = 0;
	sec = 0;
}

Time::~Time(void) {}

Time::Time(int H, int M, int S)
{
	hour = H;
	min = M;
	sec = S;
}

Time::Time(const Time& time)
{
	hour = time.hour;
	sec = time.sec;
	min = time.min;
}

void Time::setHour(int H)
{
	hour = H;
}
void Time::setMin(int M)
{
	min = M;
}
void Time::setSec(int S)
{
	sec = S;
}

Time& Time::operator =(const Time& time)
{
	if (&time == this)
	{
		return *this;
	}
	first = time.first;
	second = time.second;
	third = time.third;
	hour = time.hour;
	min = time.min;
	sec = time.sec;
	return *this;
}

istream& operator >>(istream& in, Time& time)
{
	cout << "\nFirst: " << time.first;
	cout << "\nSecond: " << time.second;
	cout << "\nThird: " << time.third;
	cout << "\nHour: " << time.hour;
	cout << "\nMinutes: " << time.min;
	cout << "\nSeconds: " << time.sec;
	return in;
}

ostream& operator <<(ostream& out, const Time& time)
{
	out << "\nFirst: " << time.first;
	out << "\nSecond: " << time.second;
	out << "\nThird: " << time.third;
	out << "\nHour: " << time.hour;
	out << "\nMinutes: " << time.min;
	out << "\nSeconds: " << time.sec;
	return out;
}