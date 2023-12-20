// https://leetcode.com/problems/course-schedule/

class Solution
{
public:
    bool topological_sort(vector<int> g[2000], int u, int colors[])
    {

        colors[u] = 1;
        bool ans = true;
        for (auto v : g[u])
        {
            if (colors[v] == 1)
                return false;
            else if (colors[v] == 0)
                ans &= topological_sort(g, v, colors);
        }

        colors[u] = 2;
        return ans;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> g[2000];
        for (auto edge : prerequisites)
            g[edge[0]].push_back(edge[1]);

        int colors[2000] = {0};
        for (int i = 0; i < numCourses; i++)
            if (colors[i] == 0 && !topological_sort(g, i, colors))
                return false;

        return true;
    }
};