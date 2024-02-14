// https://leetcode.com/problems/custom-sort-string/description/

class Solution
{
public:
    string customSortString(string order, string s)
    {
        vector<int> idx(26);
        for (int i = 0; i < order.size(); ++i)
            idx[order[i] - 'a'] = i + 1;

        sort(begin(s), end(s), [&](char c1, char c2)
             { return idx[c1 - 'a'] < idx[c2 - 'a']; });

        return s;
    }
};