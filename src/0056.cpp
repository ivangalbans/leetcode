// https://leetcode.com/problems/merge-intervals/description/

class LUPrefix
{
private:
    int prefix;
    int n;
    vector<bool> videos;

public:
    LUPrefix(int n) : n(n), videos(n + 1), prefix(0)
    {
    }

    void upload(int video)
    {
        videos[video] = true;
    }

    int longest()
    {
        while (prefix + 1 <= n && videos[prefix + 1])
            ++prefix;
        return prefix;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */

// Fenwick Tree + Binary Search

class Solution
{
private:
    bool overlap(vector<int> &v1, vector<int> &v2)
    {
        return v2[0] >= v1[0] && v2[0] <= v1[1];
    }

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        sort(begin(intervals), end(intervals), [&](auto v1, auto v2)
             { return make_pair(v1[0], v1[1]) < make_pair(v2[0], v2[1]); });

        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (overlap(ans[ans.size() - 1], intervals[i]))
            {
                ans[ans.size() - 1][0] = min(ans[ans.size() - 1][0], intervals[i][0]);
                ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1], intervals[i][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};