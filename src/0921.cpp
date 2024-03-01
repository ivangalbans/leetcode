// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int n = s.length();
        int opened = 0, closed = 0;
        for (auto ch : s)
        {
            if (ch == '(')
                ++opened;
            else
            {
                if (opened)
                    --opened;
                else
                    ++closed;
            }
        }

        return opened + closed;
    }
};