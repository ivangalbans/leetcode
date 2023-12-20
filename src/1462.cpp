// https://leetcode.com/problems/course-schedule-iv/description/

// Topological Sort

class Solution
{
public:
    void dfs(vector<int> g[100], int u, vector<bool> &visited, vector<int> &rtop_sort)
    {
        visited[u] = true;
        for (auto v : g[u])
            if (!visited[v])
                dfs(g, v, visited, rtop_sort);
        rtop_sort.push_back(u);
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
    {
        vector<int> g[100];
        for (auto edge : prerequisites)
            g[edge[0]].push_back(edge[1]);

        vector<int> rtop_sort;
        vector<bool> visited(numCourses);
        for (int i = 0; i < numCourses; ++i)
            if (!visited[i])
                dfs(g, i, visited, rtop_sort);

        vector<unordered_set<int>> pre(numCourses);
        for (int i = numCourses - 1; i >= 0; --i)
        {
            int u = rtop_sort[i];
            for (auto v : g[u])
            {
                pre[v].insert(u);
                for (auto x : pre[u])
                    pre[v].insert(x);
            }
        }

        int nq = queries.size();
        vector<bool> answer(nq);
        for (int i = 0; i < nq; ++i)
        {
            int u = queries[i][0], v = queries[i][1];
            answer[i] = pre[v].contains(u);
        }

        return answer;
    }
};

// Closure (Floyd-Wharshall)

class Solution
{
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
    {
        vector<vector<bool>> matrix(n, vector<bool>(n));
        for (auto edge : prerequisites)
            matrix[edge[0]][edge[1]] = true;

        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    matrix[i][j] = matrix[i][j] || (matrix[i][k] && matrix[k][j]);

        vector<bool> answer;
        for (auto q : queries)
            answer.push_back(matrix[q[0]][q[1]]);

        return answer;
    }
};