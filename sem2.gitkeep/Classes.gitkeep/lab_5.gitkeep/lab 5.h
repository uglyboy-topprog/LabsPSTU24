// object.h 

#pragma once
#include <iostream>

using namespace std;

class Object 
{
public:
	Object() {}
public:
	~Object() {}
	virtual void Show() = 0;
};


// time.h

#pragma once
#include <iostream>
#include "triad.h"

using namespace std;

class Time :
	public Triad 
{
public:
	Time(void);
public:
	~Time(void);
	Time(int, int, int);
	Time(const Time&);

	int getHour() { return hour; }
	int getMin() { return min; }
	int getSec() { return sec; }

	void setHour(int);
	void setMin(int);
	void setSec(int);

	Time& operator =(const Time&);

	friend istream& operator >>(istream& in, Time& time);
	friend ostream& operator <<(ostream& out, const Time& time);

protected:
	int hour, min, sec;
};


// triad.h

#pragma once
#include "object.h"
#include <iostream>

using namespace std;

class Triad :
	public Object 
{
public:
	Triad(void);
public:
	virtual ~Triad(void);
	void Show() {}
	Triad(int, int, int);
	Triad(const Triad&);

	int getFirst() { return first; }
	int getSecond() { return second; }
	int getThird() { return third; }

	void setFirst(int);
	void setSecond(int);
	void setThird(int);

	Triad& operator =(const Triad&);

	friend istream& operator >>(istream& in, Triad& T);
	friend ostream& operator <<(ostream& out, const Triad& T);

protected:
	int first, second, third;
};


// vector.h

#pragma once
#include <iostream>
#include "object.h"

using namespace std;

class Vector 
{
public:
	Vector(void);
	Vector(int);
public:
	~Vector(void);
	void Add(Object*);
	friend ostream& operator <<(ostream& out, const Vector&);
private:
	Object** ptr;
	int size, cur;
};
