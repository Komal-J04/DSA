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

int findPivot(int *arr, int start, int end)
{
    if (start > end)
        return -1;

    int mid = (start + end) / 2;

    // In a mountain array, elements cannot be equal!
    //  if (arr[mid] == arr[start])
    //  {
    //      // mid-1 will return largest element   mid will return smallest element
    //      return mid;
    //  }

    // Check if the middle element is the pivot.
    if (arr[mid] > arr[mid + 1])
    {
        return mid;
    }

    // Check if the middle element-1 is the pivot.
    if (arr[mid] < arr[mid - 1])
    {
        return mid - 1;
    }

    if (arr[mid] > arr[start])
    {
        return findPivot(arr, mid + 1, end);
    }
    if (arr[mid] < arr[start])
    {
        return findPivot(arr, start, mid);
    }
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

    print(arr, size);

    cout << "Peak index in the array is " << findPivot(arr, 0, size - 1) << endl;
}