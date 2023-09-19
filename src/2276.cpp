// https://leetcode.com/problems/count-integers-in-intervals/description/

// Merge Intervals

class CountIntervals
{
private:
    set<pair<int, int>> intervals;
    int nums;

    int count(pair<int, int> interval)
    {
        return interval.second - interval.first + 1;
    }

public:
    CountIntervals()
    {
        nums = 0;
    }

    void add(int left, int right)
    {
        auto it = intervals.upper_bound({left, right});
        if (it != begin(intervals) && prev(it)->second >= left)
            it = prev(it);
        while (it != end(intervals) && it->first <= right)
        {
            left = min(left, it->first);
            right = max(right, it->second);
            nums -= count(*it);
            it = intervals.erase(it);
        }
        intervals.insert({left, right});
        nums += count({left, right});
    }

    int count()
    {
        return nums;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */