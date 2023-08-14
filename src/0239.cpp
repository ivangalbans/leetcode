// https://leetcode.com/problems/sliding-window-maximum/description/

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        deque<int> q;
        vector<int> ans;

        for (int i = 0; i < k; ++i)
        {
            while (!q.empty() && nums[q.back()] <= nums[i])
                q.pop_back();
            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);

        for (int i = k; i < n; ++i)
        {
            while (!q.empty() && nums[q.back()] <= nums[i])
                q.pop_back();

            if (!q.empty() && q.front() + k == i)
                q.pop_front();
            q.push_back(i);
            ans.push_back(nums[q.front()]);
        }

        return ans;
    }
};