// https://leetcode.com/problems/the-skyline-problem/description/

struct Points
{
    int x, y;
    bool isStart;

    Points() {}
    Points(int x, int y, bool isStart) : x(x), y(y), isStart(isStart) {}
};

bool cmp_points(const Points &p1, const Points &p2)
{
    if (p1.x != p2.x)
        return p1.x < p2.x;
    if (p1.isStart && p2.isStart)
        return p1.y > p2.y;
    if (!p1.isStart && !p2.isStart)
        return p1.y < p2.y;
    return p1.isStart ? true : false;
}

class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        int n = buildings.size();
        vector<Points> points(2 * n);
        vector<vector<int>> keyPoints;

        for (int i = 0; i < n; ++i)
        {
            points[2 * i] = Points(buildings[i][0], buildings[i][2], true);
            points[2 * i + 1] = Points(buildings[i][1], buildings[i][2], false);
        }

        sort(begin(points), end(points), cmp_points);

        multiset<int> pq{0};
        int prevMax = 0;

        for (auto &p : points)
        {
            if (p.isStart)
            {
                pq.insert(p.y);
            }
            else
            {
                pq.erase(pq.find(p.y));
            }
            int currentMax = *pq.rbegin();
            if (prevMax != currentMax)
            {
                keyPoints.push_back({p.x, currentMax});
                prevMax = currentMax;
            }
        }

        return keyPoints;
    }
};