#include <iostream>
using namespace std;

void print(int *arr, int size)
{
    cout << "The array is - ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int *arr, int start, int end)
{
    int pivot = arr[start];
    int count = 0;

    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    swap(arr[start], arr[pivotIndex]); // place pivot at right index

    // left and right part
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= arr[pivotIndex])
            i++;

        while (arr[j] > arr[pivotIndex]) // take equal elements on any 1 side of the pivotIndex
            j--;

        if (i < pivotIndex && j > pivotIndex)
            swap(arr[i++], arr[j--]);
    }

    return pivotIndex;
}

void quickSort(int *arr, int start, int end)
{
    if (start >= end)
        return;

    int part = partition(arr, start, end);

    quickSort(arr, start, part - 1);
    quickSort(arr, part + 1, end);
}

int main()
{
    int arr[50];
    int size;
    cout << "Enter size of array\n";
    cin >> size;
    cout << "Enter elements of array\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Before sorting - ";
    print(arr, size);

    quickSort(arr, 0, size - 1);

    cout << "After sorting - ";
    print(arr, size);
}