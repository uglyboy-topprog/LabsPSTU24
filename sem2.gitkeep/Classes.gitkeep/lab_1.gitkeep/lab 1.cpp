﻿// main

#include <iostream>
#include "fraction.h"
using namespace std;

fraction make_fraction(double F, int S)
{
    fraction t;//создали временную переменную
    t.Init(F, S);//инициализировали поля переменной t с помощью параметров функции 
    return t;//вернули значение переменной t
}

int main() 
{
    fraction A;
    A.Init(1, 1);
    A.Read();
    A.Show();
    cout << A.Summa();

    return 0;
}

// fraction.cpp

#include <iostream>
#include "fraction.h"
using namespace std;

void fraction::Init(double F, int S)
{
    first = F; second = S;
}

void fraction::Read()
{
    cout << "Salary: "; cin >> first;
    cout << "Days worked: "; cin >> second;
}

void fraction::Show()
{
    cout << "Salary: " << first;
    cout << "Days worked: " << second;
    cout << "\n";
}

double fraction::Summa()
{
    return (first * second) / 30;
}

