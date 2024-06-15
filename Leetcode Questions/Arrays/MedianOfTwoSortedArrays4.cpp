class Solution
{
public:
    void print(vector<int> arr)
    {
        for (int i = 0; i < arr.size(); i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    vector<int> merge(vector<int> nums1, vector<int> nums2, int m, int n)
    {
        vector<int> merged;
        int i = 0, j = 0;
        while (i < m && j < n)
        {
            if (nums1[i] <= nums2[j])
            {
                merged.push_back(nums1[i]);
                i++;
            }
            else
            {
                merged.push_back(nums2[j]);
                j++;
            }
        }

        while (i < m)
        {
            merged.push_back(nums1[i]);
            i++;
        }

        while (j < n)
        {
            merged.push_back(nums2[j]);
            j++;
        }
        return merged;
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        double ans = 0;
        int m = nums1.size();
        int n = nums2.size();

        vector<int> merged = merge(nums1, nums2, m, n);
        double i = 0, j = merged.size() - 1;

        while (i <= (j - 2))
        {
            i++;
            j--;
        }

        if (i == j)
            ans = merged[i];
        else
            ans = ((double)merged[i] + (double)merged[j]) / 2;

        return ans;
    }
};