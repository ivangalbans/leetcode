// https://leetcode.com/problems/exclusive-time-of-functions/description/

class Solution
{
private:
    struct Log
    {
        int id;
        string op;
        int t;
    };

public:
    Log parse_log(string &log_str)
    {
        Log log;
        int i = 0;

        int id = 0;
        while (log_str[i] != ':')
        {
            id = id * 10 + (log_str[i] - '0');
            ++i;
        }
        ++i;
        log.id = id;

        string op = "";
        while (log_str[i] != ':')
        {
            op += log_str[i];
            ++i;
        }
        ++i;
        log.op = op;

        int t = 0;
        while (i < log_str.length())
        {
            t = t * 10 + (log_str[i] - '0');
            ++i;
        }
        log.t = t;

        return log;
    }

    vector<int> exclusiveTime(int n, vector<string> &logs)
    {

        vector<Log> parsed_logs;
        for (auto &log : logs)
            parsed_logs.push_back(parse_log(log));

        vector<int> exclusive_time(n);
        stack<Log> st;
        int elapsed = 0;
        for (auto &log : parsed_logs)
        {
            if (log.op == "start")
            {
                st.push(log);
            }
            else
            {
                Log top = st.top();
                st.pop();
                int elapsed = log.t - top.t + 1;
                exclusive_time[log.id] += elapsed;
                if (!st.empty())
                    exclusive_time[st.top().id] -= elapsed;
            }
        }

        return exclusive_time;
    }
};