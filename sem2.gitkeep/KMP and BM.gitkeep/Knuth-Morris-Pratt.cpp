﻿
#include <iostream>

using namespace std;

int* calcPrefixFunc(string pat, int size)
{
    int* lps = new int[size]; // longest prefix-seffix
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < size)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0) { len = lps[len - 1]; }
            else { lps[i] = 0; i++; }
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << lps[i];
    }
    cout << endl;
    return lps;
}

void knutMorrisPrattSearch(string str, string pat)
{
    int strSize = str.size();
    int patSize = pat.size();

    int* lps = calcPrefixFunc(pat, patSize);

    int strIdx = 0;
    int patIdx = 0;

    while ((strSize - strIdx) >= (patSize - patIdx))
    {
        if (pat[patIdx] == str[strIdx])
        {
            patIdx++;
            strIdx++;
        }

        if (patIdx == patSize)
        {
            cout << "Подстрока найдена по индкесу: " << strIdx - patIdx << endl;
            patIdx = lps[patIdx - 1];
        }
        else if (strIdx < strSize && pat[patIdx] != str[strIdx])
        {
            if (patIdx != 0) { patIdx = lps[patIdx - 1]; }
            else { strIdx++; }
        }
    }
}

int main()
{
    string inputStr, searchStr;
    cin >> inputStr;
    cin >> searchStr;
    knutMorrisPrattSearch(inputStr, searchStr);
    return 0;
}
