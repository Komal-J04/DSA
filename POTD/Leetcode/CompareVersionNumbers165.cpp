// https://leetcode.com/problems/compare-version-numbers/description/?envType=daily-question&envId=2024-05-03

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        int i = 0, j = 0;
        while (i < version1.length() && j < version2.length())
        {
            long long int temp1 = 0, temp2 = 0;
            while (i < version1.length() && version1[i] != '.')
            {
                temp1 = (temp1 * 10) + (version1[i] - '0');
                i++;
            }

            while (j < version2.length() && version2[j] != '.')
            {
                temp2 = (temp2 * 10) + (version2[j] - '0');
                j++;
            }

            i++;
            j++;

            if (temp1 < temp2)
                return -1;
            else if (temp1 > temp2)
                return 1;
        }

        while (i < version1.length())
        {
            long long int temp1 = 0;
            while (i < version1.length() && version1[i] != '.')
            {
                temp1 = (temp1 * 10) + (version1[i] - '0');
                i++;
            }
            if (temp1 != 0)
                return 1;

            i++;
        }

        while (j < version2.length())
        {
            long long int temp1 = 0;
            while (j < version2.length() && version2[j] != '.')
            {
                temp1 = (temp1 * 10) + (version2[j] - '0');
                j++;
            }
            if (temp1 != 0)
                return -1;

            j++;
        }

        return 0;
    }
};