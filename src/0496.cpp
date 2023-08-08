// https://leetcode.com/problems/next-greater-element-i/description/

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();
        vector<int> ansIndex(10000 + 1, -1);
        deque<int> q;

        for (int i = 0; i < m; ++i)
        {
            while (!q.empty() && nums2[i] > q.back())
            {
                ansIndex[q.back()] = nums2[i];
                q.pop_back();
            }
            q.push_back(nums2[i]);
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
            ans[i] = ansIndex[nums1[i]];

        return ans;
    }
};