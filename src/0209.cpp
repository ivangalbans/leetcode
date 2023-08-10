// https://leetcode.com/problems/minimum-size-subarray-sum/description/

// O(n * log(n))

class Solution
{
public:
    int sum(vector<int> &preSum, int l, int r)
    {
        return l == 0 ? preSum[r] : preSum[r] - preSum[l - 1];
    }

    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        vector<int> preSum(n);
        preSum[0] = nums[0];

        for (int i = 1; i < n; ++i)
            preSum[i] = preSum[i - 1] + nums[i];

        int ans = INT_MAX;
        for (int i = 0; i < n; ++i)
        {
            int lo = 0, hi = i;
            while (lo <= hi)
            {
                int mid = (lo + hi) / 2;

                if (i == 1)
                    cout << lo << " " << hi << endl;

                if (sum(preSum, mid, i) >= target)
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
            --lo;

            if (lo >= 0 && sum(preSum, lo, i) >= target)
                ans = min(ans, i - lo + 1);
        }

        return ans != INT_MAX ? ans : 0;
    }
};

// O(n) - Sliding Window

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int ans = INT_MAX, sum = 0;
        deque<int> window;

        for (int i = 0; i < n; ++i)
        {
            while (sum + nums[i] >= target)
            {
                if (window.empty())
                    return 1;
                ans = min(ans, (int)window.size() + 1);
                sum = sum - window.front();
                window.pop_front();
            }
            window.push_back(nums[i]);
            sum += nums[i];
        }

        return ans != INT_MAX ? ans : 0;
    }
};