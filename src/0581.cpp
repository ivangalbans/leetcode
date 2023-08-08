// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int l = n - 1, r = 0;
        deque<int> q1, q2;

        for (int i = 0; i < nums.size(); ++i)
        {
            while (!q1.empty() && nums[i] < nums[q1.back()])
            {
                l = min(l, q1.back());
                q1.pop_back();
            }
            q1.push_back(i);
        }

        for (int i = n - 1; i >= 0; --i)
        {
            while (!q2.empty() && nums[i] > nums[q2.back()])
            {
                r = max(r, q2.back());
                q2.pop_back();
            }
            q2.push_back(i);
        }

        return l < r ? r - l + 1 : 0;
    }
};