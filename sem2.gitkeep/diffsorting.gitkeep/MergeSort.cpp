#include <iostream>

using namespace std;

void merge(int arr[], int leftPart, int midPart, int rightPart)
{
    int leftRange = midPart - leftPart + 1;
    int rightRange = rightPart - midPart;

    int* leftArr = new int[leftRange];
    int* rightArr = new int[rightRange];

    for (int i = 0; i < leftRange; i++)
    {
        leftArr[i] = arr[leftPart + i];
    }
    for (int i = 0; i < rightRange; i++)
    {
        rightArr[i] = arr[midPart + 1 + i];
    }
    int leftIndex = 0;
    int rightIndex = 0;
    int mergeIndex = leftPart;

    while (leftIndex < leftRange && rightIndex < rightRange)
    {
        if (leftArr[leftIndex] <= rightArr[rightIndex])
        {
            arr[mergeIndex] = leftArr[leftIndex];
            leftIndex++;
        }
        else
        {
            arr[mergeIndex] = rightArr[rightIndex];
            rightIndex++;
        }
        mergeIndex++;
    }

    while (leftIndex < leftRange)
    {
        arr[mergeIndex] = leftArr[leftIndex];
        leftIndex++;
        mergeIndex++;
    }
    while (rightIndex < rightRange)
    {
        arr[mergeIndex] = rightArr[rightIndex];
        rightIndex++;
        mergeIndex++;
    }

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(int arr[], int start, int end)
{
    if (start >= end) return;

    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
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
    mergeSort(arr, 0, n - 1);
    cout << "Sorted: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}