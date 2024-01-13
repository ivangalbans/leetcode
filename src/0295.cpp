// https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder
{
private:
    priority_queue<int> minor;
    priority_queue<int, vector<int>, greater<int>> larger;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        larger.push(num);
        minor.push(larger.top());
        larger.pop();
        if (minor.size() > larger.size())
        {
            larger.push(minor.top());
            minor.pop();
        }
    }

    double findMedian()
    {
        return larger.size() > minor.size() ? larger.top() : (minor.top() + larger.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */