// https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/

class Solution
{
public:
    int len;
    long long sum = 0;

    void balance(multiset<int> &m1, multiset<int> &m2)
    {
        if (m1.size() < len && !m2.empty())
        {
            auto it = begin(m2);
            m1.insert(*it);
            sum += *it;
            m2.erase(it);
        }

        if (m1.size() > len)
        {
            auto it = prev(end(m1));
            m2.insert(*it);
            m1.erase(it);
            sum -= *it;
        }

        if (!m2.empty() && *begin(m2) < *prev(end(m1)))
        {
            auto it1 = prev(end(m1));
            int val1 = *it1;
            auto it2 = begin(m2);
            int val2 = *it2;
            m1.erase(it1);
            m1.insert(val2);
            m2.erase(it2);
            m2.insert(val1);
            sum += (-val1 + val2);
        }
    }

    void insert(int x, multiset<int> &m1, multiset<int> &m2)
    {
        m2.insert(x);
        balance(m1, m2);
    }

    void remove(int x, multiset<int> &m1, multiset<int> &m2)
    {
        if (m2.find(x) != end(m2))
            m2.erase(m2.find(x));
        else
        {
            m1.erase(m1.find(x));
            sum -= x;
        }
        balance(m1, m2);
    }

    long long minimumCost(vector<int> &nums, int k, int dist)
    {
        int n = nums.size();
        long long ans = LONG_MAX;
        multiset<int> m1, m2;

        len = k - 1;
        for (int l = 1, r = 1; l + dist < n; ++l)
        {
            while (r < n && r - l <= dist)
            {
                insert(nums[r], m1, m2);
                ++r;
            }

            if (r - l == dist + 1)
                ans = min(ans, sum);

            remove(nums[l], m1, m2);
        }

        return nums[0] + ans;
    }
};