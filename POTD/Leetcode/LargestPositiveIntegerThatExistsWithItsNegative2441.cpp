// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/?envType=daily-question&envId=2024-05-02

class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        int ans = -1;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < n && nums[i] < 0)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (abs(nums[i]) == nums[j])
                {
                    ans = max(ans, abs(nums[i]));
                    break; // since the array is sorted, so the smallest -ve (its abs will be largest +ve), will be the 1st from left and hence, we can break
                }
            }
            i++;
        }
        return ans;
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

// APPROACH 2 - Two pointer approach
class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        int ans = -1;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        while (start < end && nums[start] < 0) // because when start=end, ofc nums[start] will be equal to nums[end] && nums[start]<0 if all numbers are positive, then we wont have the required answer
        {
            if (abs(nums[start]) == nums[end])
            {
                ans = max(ans, abs(nums[start]));
                break;
            }
            else if (abs(nums[start]) < nums[end])
                end--;
            else if (abs(nums[start]) > nums[end])
                start++;
        }

        return ans;
    }
};