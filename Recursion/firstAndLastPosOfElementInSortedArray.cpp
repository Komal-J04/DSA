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

int ans = -1;

int firstPos(int *arr, int start, int end, int elt)
{
    print(arr, end - start + 1);
    if (start > end)
        return ans;

    int mid = (start + end) / 2;

    if (arr[mid] == elt)
    {
        ans = mid;
        return firstPos(arr, start, mid - 1, elt);
    }
    if (elt < arr[mid])
        return firstPos(arr, start, mid - 1, elt);
    if (elt > arr[mid])
        return firstPos(arr, mid + 1, end, elt);
}

int ans2 = -1;

int lastPos(int *arr, int start, int end, int elt)
{
    print(arr, end - start + 1);
    if (start > end)
        return ans2;

    int mid = (start + end) / 2;

    if (arr[mid] == elt)
    {
        ans2 = mid;
        return firstPos(arr, mid + 1, end, elt);
    }
    if (elt < arr[mid])
        return firstPos(arr, start, mid - 1, elt);
    if (elt > arr[mid])
        return firstPos(arr, mid + 1, end, elt);
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

    int elt;
    cout << "Enter element to be searched - ";
    cin >> elt;
    cout << "First occurence of " << elt << " is at position " << firstPos(arr, 0, size - 1, elt) << endl;
    cout << "Last occurence of " << elt << " is at position " << lastPos(arr, 0, size - 1, elt) << endl;
}