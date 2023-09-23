class Solution
{
public:
    int findPeakIndex(vector<int> arr)
    {
        int start = 0;
        int end = arr.size() - 1;
        while (start < end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] < arr[mid + 1])
                start = mid + 1;
            else
                end = mid;
        }
        return start;
    }
    bool validMountainArray(vector<int> &arr)
    {
        if (arr.size() >= 3)
        {
            int peak = findPeakIndex(arr);
            if (peak == 0 || peak == (arr.size() - 1))
                return false; // sorted array in ascending or descending order
            cout << "peak=" << peak << endl;
            for (int i = 0; i < peak; i++)
            {
                if (arr[i] < arr[i + 1])
                    continue;
                else
                    return false;
            }
            for (int i = peak; i < arr.size() - 1; i++)
            {
                if (arr[i] > arr[i + 1])
                    continue;
                else
                    return false;
            }
            return true;
        }
        return false;
    }
};