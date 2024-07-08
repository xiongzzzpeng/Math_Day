#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

set<int> graph[100010];

// https://www.luogu.com.cn/problem/P5318

void dfs(vector<int> &vis, int x)
{
    if (vis[x])
        return;
    vis[x] = 1;
    cout << x << " ";
    for (auto a : graph[x])
        dfs(vis, a);
}

void bfs(vector<int> &vis)
{
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int cut = q.front();
        q.pop();
        if (vis[cut])
            continue;
        vis[cut] = 1;
        cout << cut << " ";
        for (auto a : graph[cut])
            q.push(a);
    }
}

void issue()
{
    int n, m;
    cin >> n >> m;
    // vector<vector<int>> graph(n + 1);
    vector<int> flag(n + 1, 0);

    while (m--)
    {
        int from, to;
        cin >> from >> to;
        graph[from].insert(to);
    }

    dfs(flag, 1);
    cout << endl;
    fill(flag.begin(), flag.end(), 0);
    bfs(flag);
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
