// https://leetcode.com/problems/sliding-window-median/description/

class Solution
{
private:
    multiset<long long> minor, larger;

    void balance()
    {
        if (minor.size() - 1 == larger.size())
        {
            auto it = prev(end(minor));
            larger.insert(*it);
            minor.erase(it);
        }

        if (larger.size() - 2 == minor.size())
        {
            auto it = begin(larger);
            minor.insert(*it);
            larger.erase(it);
        }
    }

    void add(int num)
    {
        if (num < get_median())
            minor.insert(num);
        else
            larger.insert(num);
        balance();
    }

    void remove(int num)
    {
        if (num < get_median())
            minor.erase(minor.find(num));
        else
            larger.erase(larger.find(num));
        balance();
    }

    double get_median()
    {
        if (minor.empty() && larger.empty())
            return 0;
        if (minor.size() == larger.size())
            return (*rbegin(minor) + *begin(larger)) / 2.0;
        return *begin(larger);
    }

public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<double> ans;

        for (int i = 0; i < k - 1; ++i)
            add(nums[i]);
        for (int i = k - 1; i < n; ++i)
        {
            add(nums[i]);
            ans.push_back(get_median());
            remove(nums[i - (k - 1)]);
        }

        return ans;
    }
};