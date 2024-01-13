// https://leetcode.com/problems/sequentially-ordinal-rank-tracker/description/

class SORTracker
{
private:
    set<pair<int, string>> s;
    set<pair<int, string>>::iterator best;

public:
    SORTracker()
    {
        best = end(s);
    }

    void add(string name, int score)
    {
        auto new_score = s.insert({-score, name}).first;
        if (best == end(s) || *new_score < *best)
            --best;
    }

    string get()
    {
        string name = best->second;
        best++;
        return name;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */

// Using two heaps
class min_priority
{
public:
    bool operator()(const auto &a, const auto &b) const
    {
        return a.first != b.first ? a.first < b.first : a.second > b.second;
    }
};

class max_priority
{
public:
    bool operator()(const auto &a, const auto &b) const
    {
        return a.first != b.first ? a.first > b.first : a.second < b.second;
    }
};

class SORTracker
{
private:
    priority_queue<pair<int, string>, vector<pair<int, string>>, max_priority> left;
    priority_queue<pair<int, string>, vector<pair<int, string>>, min_priority> right;
    int k = 0;

public:
    SORTracker()
    {
    }

    void add(string name, int score)
    {
        left.push({score, name});
        if (left.size() == k + 2)
        {
            right.push(left.top());
            left.pop();
        }
    }

    string get()
    {
        string name = left.top().second;
        k++;
        if (!right.empty())
        {
            left.push(right.top());
            right.pop();
        }
        return name;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */