// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/

class Solution
{
public:
    int minimumPushes(string word)
    {
        vector<int> ac(26);
        for (auto ch : word)
            ac[ch - 'a']++;

        sort(begin(ac), end(ac), greater<int>());
        int ans = 0;
        for (int i = 0; i < 26; ++i)
            ans += ac[i] * (i / 8 + 1);

        return ans;
    }
};