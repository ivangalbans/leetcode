class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> prev = {{s[0], 0}};
        int l = 0;
        int ans = min(1, (int)s.length());

        for (int r = l + 1; r < s.length(); ++r)
        {
            if (prev.count(s[r]) == 1 && l <= prev[s[r]])
                l = prev[s[r]] + 1;
            else
                ans = max(ans, r - l + 1);

            prev[s[r]] = r;
        }

        return ans;
    }
};