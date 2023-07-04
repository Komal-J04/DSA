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

void merge(int *arr, int start, int end)
{
    int mid = (start + end) / 2;

    int mainArrIndex = start;

    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *arr1 = new int[len1];
    int *arr2 = new int[len2];

    // copy start to mid values in arr1 and mid to end in arr2
    for (int i = 0; i < len1; i++)
    {
        arr1[i] = arr[mainArrIndex++];
    }

    for (int i = 0; i < len2; i++)
    {
        arr2[i] = arr[mainArrIndex++];
    }

    // merge 2 sorted arrays
    int index1 = 0, index2 = 0;
    mainArrIndex = start;
    while (index1 < len1 && index2 < len2)
    {
        if (arr1[index1] < arr2[index2])
        {
            arr[mainArrIndex++] = arr1[index1++];
        }
        else
        {
            arr[mainArrIndex++] = arr2[index2++];
        }
    }

    while (index1 < len1)
    {
        arr[mainArrIndex++] = arr1[index1++];
    }

    while (index2 < len2)
    {
        arr[mainArrIndex++] = arr2[index2++];
    }

    delete[] arr1;
    delete[] arr2;
}

void mergeSort(int *arr, int start, int end)
{
    if (start == end)
        return;

    int mid = (start + end) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    merge(arr, start, end);
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

// Advantages - Stability, Guaranteed worst-case performance(O(N logN)), Parallelizable