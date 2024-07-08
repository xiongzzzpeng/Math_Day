#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

void dfs(int x, int d, vector<int> &ans, vector<vector<int>> &graph)
{
    if (ans[x])
        return;
    ans[x] = d;
    for (int i = 0; i < graph[x].size(); i++)
        dfs(graph[x][i], d, ans, graph);
}

void issue()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> ans(n + 1, 0);

    while (m--)
    {
        int from, to;
        cin >> from >> to;
        graph[to].push_back(from);
    }

    for (int i = n; i > 0; i--)
        dfs(i, i, ans, graph);

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
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
