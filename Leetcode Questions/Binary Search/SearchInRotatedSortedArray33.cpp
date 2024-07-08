class Solution
{
public:
    int findPivot(vector<int> nums, int start, int end)
    {
        while (start < end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] >= nums[0])
                start = mid + 1;
            else
                end = mid;
        }
        return start;
    }

    int searchTgt(vector<int> nums, int tgt, int start, int end)
    {
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == tgt)
                return mid;
            else if (nums[mid] < tgt)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }

    int search(vector<int> &nums, int target)
    {
        int pivot = findPivot(nums, 0, nums.size() - 1);

        cout << pivot << endl;

        if ((target >= nums[pivot]) && (target <= nums[nums.size() - 1]))
            return searchTgt(nums, target, pivot, nums.size() - 1);

        return searchTgt(nums, target, 0, pivot - 1);
    }
};

// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************
// *********************************************************************************

// APPROACH 2
class Solution
{
public:
    int search(std::vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }

            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target < nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (nums[mid] < target && target <= nums[high])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};