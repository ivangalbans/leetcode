// https://leetcode.com/problems/merge-strings-alternately/description/

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();
        string ans = "";

        for (int i = 0; i < min(n, m); ++i)
            ans += word1[i], ans += word2[i];

        for (int i = min(n, m); i < max(n, m); ++i)
            ans += n > m ? word1[i] : word2[i];

        return ans;
    }
};