// Вариант 11

#include <iostream>  
#include <cstdlib>  
#include <ctime>  
using namespace std;

void printArray(int** array, int rows, int columns) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < columns; j++) 
        {
            cout << array[i][j] << " ";   
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел.  

    int rows, columns;

    cout << "Введите количество строк: ";
    cin >> rows;

    cout << "Введите количество столбцов: ";
    cin >> columns;

    // Выделение памяти для двумерного массива.  
    int** array = new int* [rows];
    for (int i = 0; i < rows; ++i) 
    {
        array[i] = new int[columns];
    }

    // Заполнение массива случайными числами.  
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < columns; ++j) 
        {
            array[i][j] = rand() % 100; // Генерация случайного числа от 0 до 99.  
        }
    }

    // Номера строки и столбца для добавления.  
    int rowNumber = 1; // Пример: добавление строки на позицию 1 (вторая строка).  
    int columnNumber = 1; // Пример: добавление столбца на позицию 1 (второй столбец).  

    // Выделение памяти для нового массива с добавленной строкой.  
    int** newArray = new int* [rows + 1];
    for (int i = 0; i < rows + 1; ++i) 
    {
        newArray[i] = new int[columns + 1]; // Увеличено количество столбцов для нового массива.  
    }

    // Копирование существующих данных и добавление новой строки.  
    for (int i = 0; i < rows + 1; ++i) 
    {
        for (int j = 0; j < columns + 1; ++j) 
        {
            if (i < rowNumber) 
            {
                newArray[i][j] = array[i][j]; // Копируем строки до новой  
            }
            else if (i == rowNumber) 
            {
                newArray[i][j] = rand() % 100; // Заполняем новую строку случайными числами  
            }
            else 
            {
                newArray[i][j] = array[i - 1][j]; // Копируем оставшиеся строки  
            }
        }
    }

    // Вставка нового столбца.  
    for (int i = 0; i < rows + 1; ++i) 
    {
        for (int j = columns; j >= columnNumber; --j) 
        {
            newArray[i][j] = newArray[i][j - 1]; // Сдвигаем элементы вправо  
        }
        newArray[i][columnNumber] = rand() % 100; // Заполняем новый столбец случайными числами  
    }

    cout << "Исходный массив:" << endl;
    printArray(array, rows, columns);
  
    cout << "Новый массив:" << endl;
    printArray(newArray, rows + 1, columns + 1);

    // Освобождение памяти.  
    for (int i = 0; i < rows; ++i) 
    {
        delete[] array[i];
    }
    delete[] array;

    for (int i = 0; i < rows + 1; ++i) 
    {
        delete[] newArray[i];
    }
    delete[] newArray;

    return 0;
}