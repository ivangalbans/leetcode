// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/

class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<long long> acc(n + 1);

        for (int i = 0; i < n; ++i)
            acc[i + 1] = acc[i] + (long long)nums[i];

        int ans = n + 1;
        deque<int> q;
        for (int i = 0; i < n + 1; ++i)
        {
            while (!q.empty() && acc[i] <= acc[q.back()])
            {
                q.pop_back();
            }
            while (!q.empty() && acc[q.front()] + k <= acc[i])
            {
                ans = min(ans, i - q.front());
                q.pop_front();
            }
            q.push_back(i);
        }

        return ans < n + 1 ? ans : -1;
    }
};