class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        set<int> s(nums.begin(), nums.end()); // to ensure that we are considering only unique elements
        vector<int> unique_vector(s.begin(), s.end());
        sort(unique_vector.begin(), unique_vector.end());
        int n = unique_vector.size();
        int i = 1, j = 0;

        while (j < n && unique_vector[j] <= 0)
            j++;

        while (j < n)
        {
            if (i != unique_vector[j])
                return i;
            i++;
            j++;
        }

        return i;
    }
};