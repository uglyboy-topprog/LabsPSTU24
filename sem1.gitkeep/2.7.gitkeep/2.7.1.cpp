﻿#include <cmath>
#include<iostream>
using namespace std;
int main()
{
    int n, kr;
    cin >> n;
    kr = sqrt(n);
    for (int i = 0; i < kr; i++)
    {
        for (int j = 0; j < kr; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}
