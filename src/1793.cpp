// https://leetcode.com/problems/maximum-score-of-a-good-subarray/description/

class Solution
{
public:
    int maximumScore(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> l(n), r(n);

        deque<int> q;
        for (int i = 0; i < n; ++i)
        {
            while (!q.empty() && nums[q.back()] >= nums[i])
                q.pop_back();
            l[i] = q.empty() ? 0 : q.back() + 1;
            q.push_back(i);
        }

        q.clear();
        for (int i = n - 1; i >= 0; --i)
        {
            while (!q.empty() && nums[q.back()] >= nums[i])
                q.pop_back();
            r[i] = q.empty() ? n - 1 : q.back() - 1;
            q.push_back(i);
        }

        int area = 0;
        for (int i = 0; i < n; ++i)
            if (l[i] <= k && k <= r[i])
                area = max(area, (r[i] - l[i] + 1) * nums[i]);

        return area;
    }
};