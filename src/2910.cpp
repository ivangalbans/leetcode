// https://leetcode.com/problems/minimum-number-of-groups-to-create-a-valid-assignment/description/

class Solution
{
public:
    int minGroupsForValidAssignment(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
        {
            return 1;
        }

        sort(begin(nums), end(nums));
        priority_queue<int> pq;

        nums.push_back(-1);
        int c = 1, m = 1e9 + 1;
        for (int i = 1; i <= n; ++i)
        {
            if (nums[i] == nums[i - 1])
                c++;
            else
            {
                pq.push(c);
                m = min(m, c);
                c = 1;
            }
        }

        while (abs(pq.top() - m) > 1)
        {
            int val = pq.top();
            pq.pop();
            int x = val / 2, y = val - x;
            m = min({m, x, y});
            pq.push(x);
            pq.push(y);
        }

        return pq.size();
    }
};