//Вариант 11
//Преобразовать строку таким образом, чтобы в ее начале были записаны слова, содержащие только цифры, потом слова, содержащие только буквы, а затем слова, которые содержат и буквы и цифры.

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>
using namespace std;

bool onlyNumbers(const string& str)
{
	return all_of(str.begin(), str.end(), isdigit);
}

bool onlyLetters(const string& str)
{
	return all_of(str.begin(), str.end(), isalpha);
}

int main()
{
	setlocale(LC_ALL, "RUS");
	string str, word;
	string numbersOnly, lettersOnly, mixedWords;
	cout << "Введите строку" << endl;
	getline(cin, str);
	istringstream iss(str);
	while (iss >> word)
	{
		if (onlyNumbers(word))
		{
			numbersOnly += word + " ";
		}
		else if (onlyLetters(word))
		{
			lettersOnly += word + " ";
		}
		else
		{
			mixedWords += word + " ";
		}
	}
	string result;
	result = numbersOnly + lettersOnly + mixedWords;
	cout << result;
}


