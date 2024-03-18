// https://leetcode.com/problems/add-strings/

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        vector<char> result;
        for (int i = num1.length() - 1, j = num2.length() - 1, carry = 0; i >= 0 || j >= 0 || carry; --i, --j)
        {
            int d1 = i < 0 ? 0 : num1[i] - '0';
            int d2 = j < 0 ? 0 : num2[j] - '0';
            result.push_back((d1 + d2 + carry) % 10 + '0');
            carry = (d1 + d2 + carry) / 10;
        }
        return string(rbegin(result), rend(result));
    }
};