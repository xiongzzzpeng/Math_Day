#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

void findOrder(vector<vector<int>> &graph, vector<int> &indegree, vector<int> &ans, int n)
{
    priority_queue<int, std::vector<int>, std::greater<int>> q; // 字典序最小
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int cur = q.top();
        q.pop();
        ans.push_back(cur);

        for (auto next : graph[cur])
        {
            if (--indegree[next] == 0)
                q.push(next);
        }
    }
}

void issue()
{
    int n, m; // n个点，m条边
    cin >> n >> m;
    vector<vector<int>> graph(n + 1); // 图
    vector<int> indegree(n + 1, 0);   // 入度

    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        indegree[to]++;
    }

    vector<int> ans;
    findOrder(graph, indegree, ans, n);

    if (ans.size() == n)
    {
        for (int i = 0; i < n - 1; i++)
            cout << ans[i] << " ";
        cout << ans[n - 1] << endl;
    }
    else
        cout << "-1" << endl;
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
