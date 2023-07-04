// how far (or close) the array is from being sorted.
// Input: arr[] = {8, 4, 2, 1}
// Output: 6
// Explanation: Given array has six inversions: (8, 4), (4, 2), (8, 2), (8, 1), (4, 1), (2, 1).

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

int countInv(int *arr, int size)
{
    int count = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
                count++;
        }
    }
    return count;
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