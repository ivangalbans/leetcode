// https://leetcode.com/problems/next-greater-element-ii/description/

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> nums2(2 * n);
        deque<int> q;

        for (int i = 0; i < n; ++i)
            nums2[i] = nums2[i + n] = i;

        vector<int> ans(n, -1);
        for (int i = 0; i < 2 * n; ++i)
        {
            while (!q.empty() && nums[nums2[i]] > nums[q.back()])
            {
                if (q.back() < n)
                    ans[q.back()] = nums[nums2[i]];
                q.pop_back();
            }
            q.push_back(nums2[i]);
        }

        return ans;
    }
};