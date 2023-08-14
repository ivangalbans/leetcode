// https://leetcode.com/problems/maximal-rectangle/

class Solution
{
public:
    int histogram_area(vector<int> &h)
    {
        int n = h.size();
        vector<int> l(n), r(n);
        deque<int> q;
        for (int i = 0; i < n; ++i)
        {
            while (!q.empty() && h[q.back()] >= h[i])
                q.pop_back();
            l[i] = q.empty() ? 0 : q.back() + 1;
            q.push_back(i);
        }

        q.clear();
        for (int i = n - 1; i >= 0; --i)
        {
            while (!q.empty() && h[q.back()] >= h[i])
                q.pop_back();
            r[i] = q.empty() ? n - 1 : q.back() - 1;
            q.push_back(i);
        }

        int area = 0;
        for (int i = 0; i < n; ++i)
            area = max(area, (r[i] - l[i] + 1) * h[i]);

        return area;
    }

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> histogram(m);

        int area = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (matrix[i][j] == '1')
                    ++histogram[j];
                else
                    histogram[j] = 0;
            }
            area = max(area, histogram_area(histogram));
        }

        return area;
    }
};