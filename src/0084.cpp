// https://leetcode.com/problems/largest-rectangle-in-histogram/description/

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> l(n), r(n);

        for (int i = 0; i < n; ++i)
        {
            int j = i;
            while (j - 1 >= 0 && heights[j - 1] >= heights[i])
                j = l[j - 1];
            l[i] = j;
        }
        i

            for (int i = n - 1; i >= 0; --i)
        {
            int j = i;
            while (j + 1 < n && heights[j + 1] >= heights[i])
                j = r[j + 1];
            r[i] = j;
        }

        int area = 0;
        for (int i = 0; i < n; ++i)
            area = max(area, (r[i] - l[i] + 1) * heights[i]);

        return area;
    }
};