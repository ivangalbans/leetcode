// https://leetcode.com/problems/word-break/

class Solution
{
public:
    bool solve(string &s, unordered_map<string, bool> &memo)
    {
        if (memo.count(s) == 1)
            return memo[s];

        bool ans = false;
        for (int i = 1; i < s.length(); ++i)
        {
            int len1 = i, len2 = s.length() - i;
            string s1 = s.substr(0, len1);
            string s2 = s.substr(i, len2);
            ans |= (solve(s1, memo) && solve(s2, memo));
        }

        return memo[s] = ans;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_map<string, bool> memo;
        for (auto w : wordDict)
            memo[w] = true;
        return solve(s, memo);
    }
};