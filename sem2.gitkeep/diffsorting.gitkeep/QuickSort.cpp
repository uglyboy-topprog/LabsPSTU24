#include <iostream>

using namespace std;

int quickSort(int arr[], int start, int end)
{
    int p = arr[end];
    int index = start;
    for (int i = start; i < end; i++)
    {
        if (arr[i] <= p)
        {
            swap(arr[i], arr[index]);
            index++;
        }
    }
    swap(arr[index], arr[end]);
    return index;
}

void Sort(int arr[], int start, int end)
{
    if (start >= end)  return;
    int p = quickSort(arr, start, end);
    Sort(arr, start, p - 1);
    Sort(arr, p + 1, end);
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
    Sort(arr, 0, n - 1);
    cout << "Sorted: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}