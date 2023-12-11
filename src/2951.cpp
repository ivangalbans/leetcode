// https://leetcode.com/problems/find-the-peaks/

class Solution
{
public:
    vector<int> findPeaks(vector<int> &m)
    {
        vector<int> ans;
        for (int i = 1; i < m.size() - 1; ++i)
            if (m[i] > m[i - 1] && m[i] > m[i + 1])
                ans.push_back(i);
        return ans;
    }
};