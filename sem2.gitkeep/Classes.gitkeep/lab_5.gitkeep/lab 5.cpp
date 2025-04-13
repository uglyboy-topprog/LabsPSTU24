﻿// time.cpp

#include <iostream>
#include "time.h"

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
	if (&time == this) {
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

// triad.cpp

#include "triad.h"
#include <iostream>

Triad::Triad(void) 
{
	first = 0;
	second = 0;
	third = 0;
}
Triad::~Triad(void) {}

Triad::Triad(int F, int S, int T) 
{
	first = F;
	second = S;
	third = T;
}

Triad::Triad(const Triad& triad) 
{
	first = triad.first;
	second = triad.second;
	third = triad.third;
}

void Triad::setFirst(int F) 
{
	first = F;
}
void Triad::setSecond(int S) 
{
	second = S;
}
void Triad::setThird(int T) 
{
	third = T;
}

Triad& Triad::operator =(const Triad& triad) 
{
	if (&triad == this) 
	{
		return *this;
	}
	first = triad.first;
	second = triad.second;
	third = triad.third;
	return *this;
}

istream& operator >>(istream& in, Triad& T)
{
	cout << "\nFirst: "; in >> T.first;
	cout << "\nSecond: "; in >> T.second;
	cout << "\nThird: "; in >> T.third;
	return in;
}

ostream& operator <<(ostream& out, const Triad& T) 
{
	out << "\nFIRST: " << T.first;
	out << "\nSECOND: " << T.second;
	out << "\nTHIRD: " << T.third;
	return out;

}

// vector.cpp

#include <iostream>
#include "vector.h"

using namespace std;

Vector::Vector() 
{
	ptr = 0;
	size = 0;
	cur = 0;
}

Vector::~Vector() 
{
	if (ptr != 0) 
	{
		delete[] ptr;
	}
	ptr = 0;
}

Vector::Vector(int n) 
{
	ptr = new Object * [n];
	cur = 0;
	size = n;
}

void Vector::Add(Object* p) 
{
	if (cur < size) 
	{
		ptr[cur] = p;
		cur++;
	}
}
ostream& operator <<(ostream& out, const Vector& v) 
{
	if (v.size == 0) 
	{
		out << "EMPTY" << endl;
	}
	Object** p = v.ptr;
	for (int i = 0; i < v.cur; i++) 
	{
		(*p)->Show();
		p++;
	}
	return out;
}

// main lab.cpp

#include "object.h"
#include "object.h"
#include "time.h"
#include "vector.h"
#include <iostream>

using namespace std;

int main()
{
	Triad a;

	cin >> a;
	cout << a << endl;

	Object* p = &a;
	p->Show();

	Time b;

	cin >> b;
	cout << b << endl;

	p = &b;
	p->Show();

	Vector v(5);
	Triad c;
	Time d;

	cin >> c >> d;

	p = &c;
	v.Add(p);
	p = &d;
	v.Add(p);

	cout << v;

	return 0;
}