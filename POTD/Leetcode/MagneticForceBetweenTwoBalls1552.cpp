// https://leetcode.com/problems/magnetic-force-between-two-balls/?envType=daily-question&envId=2024-06-20

class Solution
{
public:
    bool isPossible(int mid, vector<int> &position, int m)
    {
        int n = position.size();
        int lastPlaced = position[0];
        int no = 1; // 1st one is already placed at position[0]
        for (int i = 1; i < n; i++)
        {
            if ((position[i] - lastPlaced) >= mid)
            {
                lastPlaced = position[i];
                no++;
                if (no == m)
                    return true;
            }
        }
        return false;
    }

    int maxDistance(vector<int> &position, int m)
    {
        sort(position.begin(), position.end()); // sorting ensures that the 1st ball is placed in the leftmost bucket
        int start = 0;
        int end = *max_element(position.begin(), position.end());
        int ans = 0;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (isPossible(mid, position, m))
            {
                ans = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
        return ans;
    }
};