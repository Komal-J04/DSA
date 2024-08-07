// https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/description/

class Solution
{
public:
    int minMovesToSeat(vector<int> &seats, vector<int> &students)
    {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int ans = 0;
        int n = seats.size();

        for (int i = 0; i < n; i++)
            ans = ans + (abs(students[i] - seats[i]));

        return ans;
    }
};