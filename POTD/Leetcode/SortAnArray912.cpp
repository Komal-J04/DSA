// /https://leetcode.com/problems/sort-an-array/submissions/1332841155/?envType=daily-question&envId=2024-07-25

// APPROACH 1 - MERGE SORT

class Solution
{
public:
    void merge(vector<int> &nums, int s, int m, int e)
    {
        int mainArrIndex = s;
        int len1 = m - s + 1;
        int len2 = e - m;
        vector<int> temp1(len1), temp2(len2);

        for (int i = 0; i < len1; i++)
        {
            temp1[i] = nums[mainArrIndex++];
        }

        for (int i = 0; i < len2; i++)
        {
            temp2[i] = nums[mainArrIndex++];
        }

        int ind1 = 0, ind2 = 0;
        mainArrIndex = s;
        while (ind1 < len1 && ind2 < len2)
        {
            if (temp1[ind1] <= temp2[ind2])
            {
                nums[mainArrIndex++] = temp1[ind1++];
            }
            else
            {
                nums[mainArrIndex++] = temp2[ind2++];
            }
        }

        while (ind1 < len1)
        {
            nums[mainArrIndex++] = temp1[ind1++];
        }

        while (ind2 < len2)
        {
            nums[mainArrIndex++] = temp2[ind2++];
        }
    }

    void mergeSort(vector<int> &nums, int start, int end)
    {
        if (start >= end)
            return;
        int mid = start + (end - start) / 2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }

    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
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

// APPROACH 2 - RECURSION [Memory limit exceeded because of too many recursive calls]
class Solution
{
public:
    void insert(vector<int> &nums, int n)
    {
        if (nums.size() == 0 || nums[nums.size() - 1] <= n)
        {
            nums.push_back(n);
            return;
        }

        int val = nums[nums.size() - 1];
        nums.pop_back();
        insert(nums, n);
        nums.push_back(val);
    }

    vector<int> sortArray(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums;

        int num = nums[nums.size() - 1];
        nums.pop_back();
        sortArray(nums);
        insert(nums, num);
        return nums;
    }
};