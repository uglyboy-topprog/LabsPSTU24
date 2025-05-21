
#include <iostream>

using namespace std;

void countSort(int arr[], int length)
{
    int* countArr = new int[length];
    int max = arr[0];

    for (int i = 1; i < length; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int* count = new int[max + 1];

    for (int i = 0; i <= max; ++i)
    {
        count[i] = 0;
    }

    for (int i = 0; i < length; i++)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = length - 1; i >= 0; i--)
    {
        countArr[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < length; i++)
    {
        arr[i] = countArr[i];
    }
    delete[] count;
    delete[] countArr;
}

int main()
{
    int n;
    cout << "Number of elements in array" << endl;
    cin >> n;
    int arr[n];
    int range_min = 2;
    int range_max = 280000;
    cout << "Array: ";
    for (int i = 0; i < n; i++)
    {
        arr[i] = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
        cout << arr[i] << " ";
    }
    cout << endl;
    countSort(arr, n);
    cout << "Sorted: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
