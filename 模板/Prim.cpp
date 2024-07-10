#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

// 最小生成树_p算法

// 比较函数
struct compare
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second > b.second;
    }
};

void issue()
{
    int n, m;
    cin >> n >> m;
    vector<vector<PII>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    // 用优先队列
    priority_queue<PII, vector<PII>, compare> q;
    for (auto &edge : graph[1])
    {
        q.push(edge);
    }

    vector<bool> flag(n + 1);
    flag[1] = true;
    int num_edge = 1;
    int ans = 0;

    while (!q.empty())
    {
        PII edge = q.top();
        q.pop();
        int next = edge.fs;
        int cost = edge.sc;

        if (!flag[next])
        {
            num_edge++;
            flag[next] = true;
            ans += cost;
            for (auto &e : graph[next])
                q.push(e);
        }
    }

    if (num_edge == n)
        cout << ans << endl;
    else
        cout << "orz" << endl;
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
