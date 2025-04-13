// main 

#include "Car.h" 
#include <iostream> 
#include <string> 
using namespace std;

//функция для возврата объекта как результата 
Car makeCar()
{
	string b;
	string m;
	int c;
	cout << "Enter brand: ";
	cin >> b;
	cout << "Enter model: ";
	cin >> m;
	cout << "Enter cost: ";
	cin >> c;
	Car t(b, m, c);
	return t;
}

//функция для передачи объекта как параметра 
void printCar(Car t)
{
	t.show();
}

void main()
{
	//конструктор без параметров 
	Car t1;
	t1.show();

	//коструктор с параметрами 
	Car t2("Lada ", "Vesta", 1500000);
	t2.show();

	//конструктор копирования 
	Car t3 = t2;
	t3.setBrand("Mersedes");
	t3.setModel("Benz");
	t3.setCost(5000000);

	//конструктор копирования 
	printCar(t3);

	//конструктор копирования 
	t1 = makeCar();
	t1.show();
}

// Car.cpp

#include "Car.h" 
#include <iostream> 
#include <string> 
using namespace std;

//конструктор без параметров 
Car::Car()
{
	brand = "";
	model = "";
	cost = 0;
	cout << "Constructor without parameters " << this << endl;
}

//конструктор с параметрами 
Car::Car(string N, string K, int S)
{
	brand = N;
	model = K;
	cost = S;
	cout << "Constructor with parameters " << this << endl;
}

//конструктор копирования 
Car::Car(const Car& t)
{
	brand = t.brand;
	model = t.model;
	cost = t.cost;
	cout << "Copy constructor " << this << endl;
}

//деструктор 
Car::Car()
{
	cout << "Destructor " << this << endl;
}

//селекторы
string Car::getBrand()
{
	return brand;
}
string Car::getModel()
{
	return model;
}
int Car::getCost()
{
	return cost;
}

//модификаторы
void Car::setBrand(string N)
{
	brand = N;
}
void Car::setModel(string K)
{
	model = K;
}
void Car::setCost(int S)
{
	cost = S;
}

//метод для просмотра атрибутов 
void Car::show()
{
	cout << "Brand :" << brand << endl;
	cout << "Model :" << model << endl;
	cout << "Cost :" << cost << endl;
}