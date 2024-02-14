// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/description/

class Solution
{
public:
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        int n = s.length();
        vector<int> freq(256);

        int ans = 0, diff = 0;
        for (int l = 0, r = 0; l < n; ++l)
        {
            while (r < n && diff < k)
                diff += freq[s[r++]]++ == 0;

            while (r < n && freq[s[r]])
                freq[s[r++]]++;

            ans = max(ans, r - l);
            diff -= --freq[s[l]] == 0;
        }

        return ans;
    }
};