// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/description/

class Solution
{
public:
    int minSwaps(string s)
    {
        int n = s.length();
        stack<char> st;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '[')
                st.push(s[i]);
            else if (!st.empty())
                st.pop();
        }

        return ceil(st.size() / 2.0);
    }
};