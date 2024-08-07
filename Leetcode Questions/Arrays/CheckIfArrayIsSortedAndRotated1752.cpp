// Solution 1
// works only if array is sorted initially and then rotated i.e, does not check for an initially sorted array
int Pivot(vector<int> &nums, int n)
{
    int start = 0;
    int end = n - 1;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] >= nums[0])
            start = mid + 1;
        else if (nums[mid] < nums[0])
            end = mid;
    }
    return start;
}

bool check(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] > nums[i])
            count++;
    }
    if (count > 1)
        return false;

    int pivot = Pivot(nums, n);
    bool isSortedRotated = false;
    for (int i = 0; i < pivot; i++)
    {
        if (nums[i] <= nums[i + 1])
            isSortedRotated = true;
        else
        {
            isSortedRotated = false;
            break;
        }
    }
    for (int i = pivot; i < n - 1; i++)
    {
        if (nums[i] <= nums[i + 1])
            isSortedRotated = true;
        else
        {
            isSortedRotated = false;
            break;
        }
    }
    return isSortedRotated;
}

// Solution 2 - not very optimized
class Solution
{
public:
    bool isSorted(vector<int> arr, int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
                return false;
        }
        return true;
    }

    vector<int> rotate(vector<int> nums, int n, int k)
    {
        vector<int> temp(nums);
        for (int i = 0; i < n; i++)
        {
            temp[i] = nums[(i + k) % n];
        }

        return temp;
    }

    bool check(vector<int> &nums)
    {
        int n = nums.size();
        if (isSorted(nums, n))
            return true;
        int count = 0;
        while (true)
        {
            nums = rotate(nums, n, 1);
            count++;
            if (count >= n)
                return false;
            if (isSorted(nums, n))
                return true;
        }
        return false;
    }
};

// Solution 3 - Answer
class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int n = nums.size();
        int count = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] > nums[i])
                count++;
        }
        if (nums[n - 1] > nums[0])
            count++;

        return count <= 1;
    }
};