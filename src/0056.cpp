// https://leetcode.com/problems/merge-intervals/description/

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        sort(begin(intervals), end(intervals), [](auto interval1, auto interval2)
             { return make_pair(interval1[0], interval1[1]) < make_pair(interval2[0], interval2[1]); });

        vector<vector<int>> ans = {intervals[0]};
        for (int i = 1; i < n; ++i)
        {
            if (intervals[i][0] <= ans.back()[1])
                ans.back() = {ans.back()[0], max(ans.back()[1], intervals[i][1])};
            else
                ans.push_back(intervals[i]);
        }

        return ans;
    }
};