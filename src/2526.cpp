// https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/description/

class DataStream
{
private:
    int value, k;
    int offset, last_offset;

public:
    DataStream(int value, int k) : value(value), k(k)
    {
        last_offset = offset = -1;
    }

    bool consec(int num)
    {
        offset++;
        if (num != value)
            last_offset = offset;

        return offset - last_offset >= k;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */