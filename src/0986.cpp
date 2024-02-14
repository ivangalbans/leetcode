// https://leetcode.com/problems/interval-list-intersections/

class Solution
{
public:
    vector<int> intervalIntersection(vector<int> &interval1, vector<int> &interval2)
    {
        return {max(interval1[0], interval2[0]), min(interval1[1], interval2[1])};
    }

    bool overlap(vector<int> &interval1, vector<int> &interval2)
    {
        auto intersection = intervalIntersection(interval1, interval2);
        return intersection[0] <= intersection[1];
    }

    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
    {
        int n = firstList.size();
        int m = secondList.size();
        int i = 0, j = 0;

        vector<vector<int>> intersection;
        while (i < n && j < m)
        {
            if (overlap(firstList[i], secondList[j]))
                intersection.push_back(intervalIntersection(firstList[i], secondList[j]));

            if (firstList[i][1] < secondList[j][1])
                ++i;
            else
                ++j;
        }

        return intersection;
    }
};