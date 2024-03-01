// https://leetcode.com/problems/moving-average-from-data-stream/description/

class MovingAverage
{
private:
    vector<int> nums;
    int size;
    int index = 0;
    int sum;

public:
    MovingAverage(int size) : size(size), sum(0), index(0)
    {
        nums = vector<int>(size);
    }

    double next(int val)
    {
        sum -= nums[index % size];
        nums[index % size] = val;
        sum += val;
        ++index;
        return (double)sum / min(index, size);
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */