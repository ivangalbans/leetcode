// https://leetcode.com/problems/count-beautiful-substrings-ii/

class Solution
{
public:
    bool is_vowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    long long beautifulSubstrings(string s, int k)
    {
        int n = s.length();

        int l;
        for (l = 1; l * l % (k * 4) > 0; ++l)
            ;

        vector<unordered_map<int, int>> dp(l);
        dp[l - 1][0] = 1;

        long long ans = 0, v = 0;
        for (int i = 0; i < n; ++i)
        {
            v += is_vowel(s[i]) ? 1 : -1;
            ans += dp[i % l][v]++;
        }

        return ans;
    }
};