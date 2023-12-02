// https://leetcode.com/problems/accounts-merge/

struct disjoint_set
{
    vector<int> parent, count;

    disjoint_set(int n)
    {
        parent = vector<int>(n);
        count = vector<int>(n);

        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            count[i] = 1;
        }
    }

    int set_of(int x)
    {
        return x == parent[x] ? x : parent[x] = set_of(parent[x]);
    }

    void merge(int x, int y)
    {
        x = set_of(x);
        y = set_of(y);

        if (x == y)
            return;

        if (count[x] < count[y])
            swap(x, y);

        parent[y] = x;
        count[x] += count[y];
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        int n_acccounts = 0, n_emails = 0;

        unordered_map<string, int> hash_email;
        unordered_map<string, string> email_owner_name;
        for (auto ac : accounts)
            for (int i = 1; i < ac.size(); ++i)
                if (!hash_email.count(ac[i]))
                {
                    hash_email.insert({ac[i], n_emails++});
                    email_owner_name.insert({ac[i], ac[0]});
                }

        disjoint_set ds_emails(n_emails);
        for (auto ac : accounts)
            for (int i = 2; i < ac.size(); ++i)
                ds_emails.merge(hash_email[ac[i - 1]], hash_email[ac[i]]);

        vector<set<string>> acc_emails(n_emails);
        for (auto ac : accounts)
            for (int i = 1; i < ac.size(); ++i)
                acc_emails[ds_emails.set_of(hash_email[ac[i]])].insert(ac[i]);

        vector<vector<string>> ans;
        for (auto emails : acc_emails)
            if (!emails.empty())
            {
                ans.push_back(vector<string>(1, email_owner_name[*emails.begin()]));
                copy(begin(emails), end(emails), back_inserter(ans.back()));
            }

        return ans;
    }
};