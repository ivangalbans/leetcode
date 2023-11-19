// https://leetcode.com/problems/separate-black-and-white-balls/

class Solution
{
public:
    long long minimumSteps(string s)
    {
        int n = s.length();
        long long c = 0, ans = 0;

        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '1')
                c++;
            else
                ans += c;
        }
        return ans;
    }
};