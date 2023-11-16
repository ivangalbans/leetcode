// https://leetcode.com/problems/word-break-ii/description/

class Solution
{
public:
    vector<string> solve(string s, unordered_set<string> &dict, unordered_map<string, vector<string>> &memo)
    {
        if (memo.count(s) == 1)
            return memo[s];

        vector<string> ans;
        if (dict.count(s))
            ans.push_back(s);

        for (auto w1 : dict)
        {
            int len1 = w1.length();
            if (s.substr(0, len1) == w1)
            {
                string s2 = s.substr(len1, s.length() - len1);
                auto comb = solve(s2, dict, memo);
                for (auto rest : comb)
                    ans.push_back(w1 + " " + rest);
            }
        }

        return memo[s] = ans;
    }

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict(begin(wordDict), end(wordDict));
        unordered_map<string, vector<string>> memo;

        return solve(s, dict, memo);
    }
};