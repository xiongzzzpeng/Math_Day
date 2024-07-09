#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;
const int mod = 80112002;

// https://www.luogu.com.cn/problem/P4017
// 统计起点到终点有多少种路径

void issue()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> in(n + 1);
    vector<int> out(n + 1);
    vector<int> num(n + 1);
    int ans = 0;

    for (int i = 1; i <= m; i++)
    {
        int from, to;
        cin >> from >> to;
        in[to]++, out[from]++;
        graph[from].push_back(to);
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
            q.push(i), num[i] = 1;
    }

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (auto next : graph[temp])
        {
            --in[next];
            num[next] = (num[next] + num[temp]) % mod;
            if (in[next] == 0)
                q.push(next);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (out[i] == 0)
            ans = (ans + num[i]) % mod;
    }

    cout << ans << endl;
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
    // cin >> T;
    while (T--)
    {
        issue();
    }
    return 0;
}
