// https://leetcode.com/problems/maximum-swap/description/

class Solution
{
public:
    int maximumSwap(int num)
    {
        string s = to_string(num);
        int n = s.length();
        for (int i = 0; i < n; ++i)
        {
            int pos = n - 1 - (max_element(s.rbegin(), s.rend() - i) - s.rbegin());
            if (s[pos] != s[i])
            {
                swap(s[i], s[pos]);
                break;
            }
        }
        return stoi(s);
    }
};