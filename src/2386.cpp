// https://leetcode.com/problems/find-the-k-sum-of-an-array/description/

class Solution
{
public:
    long long kSum(vector<int> &nums, int k)
    {
        int n = nums.size();
        long long max_sum = 0;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] > 0)
                max_sum += nums[i];
            else
                nums[i] = abs(nums[i]);
        }

        sort(begin(nums), end(nums));

        vector<long long> ans;
        ans.push_back(max_sum);

        // <next_sum, index>
        priority_queue<pair<long long, int>> pq;
        pq.push({max_sum - nums[0], 0});
        while (ans.size() < k)
        {
            auto [next_sum, i] = pq.top();
            pq.pop();
            ans.push_back(next_sum);
            if (i + 1 < n)
            {
                pq.push({next_sum + nums[i] - nums[i + 1], i + 1});
                pq.push({next_sum - nums[i + 1], i + 1});
            }
        }

        return ans[k - 1];
    }
};