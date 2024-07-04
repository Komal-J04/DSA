class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
            return n;

        int i = 0;
        int modifyInd = 0;

        while (i < n)
        {
            int start = i;
            int curr = nums[i];
            int end = start + 1;
            while (nums[end] == curr)
                end++;

            cout << start << " " << end << " ";

            if ((end - start) >= 2)
            {
                nums[modifyInd] = curr;
                modifyInd++;
                nums[modifyInd] = curr;
            }
            else
                nums[modifyInd] = curr;

            modifyInd++;
            i = end;
            cout << i << endl;
        }

        return modifyInd;
    }
};