class Solution
{
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
    {
        int maxi = -1, r = mat.size(), c = mat[0].size(), rowInd = -1;
        ;

        for (int i = 0; i < r; i++)
        {
            int cnt = 0;
            for (int j = 0; j < c; j++)
                cnt += (mat[i][j] == 1);

            if (cnt > maxi)
            {
                maxi = cnt;
                rowInd = i;
            }
        }
        return {rowInd, maxi};
    }
};