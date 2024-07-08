#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

class Solution
{
public:
    vector<string> ans;

    bool check(string s)
    {
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i - 1] == '0' && s[i] == '0')
                return false;
        }
        return true;
    }

    void dfs(int n, string path, int x)
    {
        if (x == n)
        {
            if (check(path))
                ans.push_back(path);
            return;
        }

        path[x] = '1';
        dfs(n, path, x + 1);

        path[x] = '0';
        if (x == 0 || path[x - 1] == '1') // 看当前这个0是不是合法的
            dfs(n, path, x + 1);
    }

    vector<string> validStrings(int n)
    {
        string path(n, '0');
        dfs(n, path, 0);
        return ans;
    }
};

void issue()
{
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("xzp.in", "r", stdin);
    freopen("xzp.out", "w", stdout);
#endif

    int T = 1;
    cin >> T;
    while (T--)
    {
        issue();
    }
    return 0;
}
