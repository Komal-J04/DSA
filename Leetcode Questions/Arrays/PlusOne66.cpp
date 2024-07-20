class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();
        if (digits[n - 1] < 9)
            digits[n - 1]++;
        else
        {
            int carry = 1;
            for (int i = n - 1; i >= 0 && carry > 0; i--)
            {
                int s = digits[i] + carry;
                digits[i] = s % 10;
                carry = s / 10;
            }
            reverse(digits.begin(), digits.end());
            while (carry > 0)
            {
                digits.push_back(carry % 10);
                carry = carry / 10;
            }
            reverse(digits.begin() + n, digits.end());
            reverse(digits.begin(), digits.end());
        }
        return digits;
    }
};