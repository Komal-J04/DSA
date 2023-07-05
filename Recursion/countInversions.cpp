// how far (or close) the array is from being sorted.
// Input: arr[] = {8, 4, 2, 1}
// Output: 6
// Explanation: Given array has six inversions: (8, 4), (4, 2), (8, 2), (8, 1), (4, 1), (2, 1).

#include <iostream>
using namespace std;

int count = 0;

void print(int *arr, int size)
{
    cout << "The array is - ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void mergeSort(int *arr, int start, int end)
{
    if (start == end)
        return;

    int mid = start + (end - start) / 2;

    count += mergeSort(arr, start, mid);
    count += mergeSort(arr, mid + 1, end);

    count += countInv(arr, start, mid, end);
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

    cout << "Inversion count = " << countInv(arr, size) << endl;
}