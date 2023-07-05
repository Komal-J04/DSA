// using indexes

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

void merge(int *arr, int start, int mid, int end)
{
    int start2 = mid + 1;

    while (start <= mid && start2 <= end)
    {
        if (arr[start] <= arr[start2])
            start++;
        else
        {
            int temp = arr[start2];
            int index = start2;
            while (index != start)
            {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[start] = temp;

            start++;
            start2++;
            mid++;
        }
    }
}

void mergeSort(int *arr, int start, int end)
{
    if (start == end)
        return;

    int mid = start + (end - start) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    merge(arr, start, mid, end);
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

    mergeSort(arr, 0, size - 1);

    cout << "After sorting - ";
    print(arr, size);
}