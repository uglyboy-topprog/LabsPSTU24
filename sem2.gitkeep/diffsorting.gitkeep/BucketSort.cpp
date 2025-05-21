#include <iostream>

using namespace std;

void bucketSort(int arr[], int length)
{
    int buckets[10][10];
    int bucketSizes[10] = { 0 };
    int min = arr[0], max = arr[0];
    for (int i = 1; i < length; i++)
    {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    for (int i = 0; i < length; i++)
    {
        int bucketIndex = (arr[i] - min) * 10 / (max - min + 1);
        if (bucketIndex >= 10) bucketIndex = 9;
        buckets[bucketIndex][bucketSizes[bucketIndex]] = arr[i];
        bucketSizes[bucketIndex]++;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 1; j < bucketSizes[i]; j++)
        {
            int temp = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > temp)
            {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = temp;
        }
    }

    int index = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < bucketSizes[i]; j++)
        {
            arr[index++] = buckets[i][j];
        }
    }
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
    bucketSort(arr, n);
    cout << "Sorted: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}