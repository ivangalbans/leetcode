// https://leetcode.com/problems/falling-squares/description/

// Map with rectangles

class Solution
{
public:
    const int N = 100000000;
    vector<int> fallingSquares(vector<vector<int>> &p)
    {
        int n = p.size();
        map<pair<int, int>, int> rects;
        rects[{0, N}] = 0;
        vector<int> ans(n);

        int best = 0;
        for (int i = 0; i < n; ++i)
        {
            vector<vector<int>> newRects;
            int a = p[i][0], b = p[i][0] + p[i][1], h = p[i][1];
            int prevH = 0;
            auto it = rects.upper_bound({a, a});
            if (it != begin(rects) && (--it)->first.second <= a)
                ++it;
            while (it != end(rects) && it->first.first < b)
            {
                if (a > it->first.first)
                    newRects.push_back({it->first.first, a, it->second});
                if (b < it->first.second)
                    newRects.push_back({b, it->first.second, it->second});
                prevH = max(prevH, it->second);
                it = rects.erase(it);
            }
            for (auto &r : newRects)
                rects[{r[0], r[1]}] = r[2];

            rects[{a, b}] = prevH + h;
            best = max(best, prevH + h);
            ans[i] = best;
        }

        return ans;
    }
};

// Brute Force O(n^2)

struct rect
{
    int a, b, h;
    rect(int a, int b, int h) : a(a), b(b), h(h) {}
};

class Solution
{
public:
    int solveHeight(vector<rect> &rects, rect &current)
    {
        int h = 0;
        for (auto rect : rects)
        {
            if (rect.b <= current.a)
                continue;
            if (rect.a >= current.b)
                continue;
            h = max(h, rect.h);
        }
        return h + current.h;
    }
    vector<int> fallingSquares(vector<vector<int>> &p)
    {
        int n = p.size();
        vector<rect> rects;
        vector<int> ans(n);

        int best = 0;
        for (int i = 0; i < n; ++i)
        {
            rect current(p[i][0], p[i][0] + p[i][1], p[i][1]);
            int newH = max(current.h, solveHeight(rects, current));
            ans[i] = best = max(best, newH);
            rects.push_back(rect(current.a, current.b, newH));
        }

        return ans;
    }
};