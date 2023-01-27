// https://leetcode.com/problems/thousand-separator/description/

class Solution
{
public:
    string thousandSeparator(int n)
    {
        string num = to_string(n);
        string ans = "";

        for (int i = 0; i < num.length(); ++i)
        {
            if (i && i >= (num.length() % 3) && (i - (num.length() % 3)) % 3 == 0)
                ans += ".";
            ans += num[i];
        }

        return ans;
    }
};