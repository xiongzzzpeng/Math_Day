#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

// 小根堆存放数据
// 二维带路径dp
// https://www.luogu.com.cn/problem/P1434

void Solve() {
    struct node {
        int i, j, num;
    };
    auto cmp = [](node &a, node &b) {
        return a.num > b.num;
    };

    priority_queue<node, vector<node>, decltype(cmp)> q(cmp);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 2, vector<int>(m + 2));
    vector<vector<int>> dp(n + 2, vector<int>(m + 2, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = 1;
            cin >> graph[i][j];
            node a;
            a.i = i, a.j = j, a.num = graph[i][j];
            q.push(a);
        }
    }

    int ans = INT32_MIN;

    while (!q.empty()) {
        auto nowl = q.top();
        q.pop();
        int i = nowl.i, j = nowl.j, now = nowl.num;

        if (graph[i - 1][j] < now)
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
        if (graph[i + 1][j] < now)
            dp[i][j] = max(dp[i][j], dp[i + 1][j] + 1);
        if (graph[i][j - 1] < now)
            dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
        if (graph[i][j + 1] < now)
            dp[i][j] = max(dp[i][j], dp[i][j + 1] + 1);

        ans = max(ans, dp[i][j]);
    }

    cout << ans << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("xzp.in", "r", stdin);
    freopen("xzp.out", "w", stdout);
#endif

    int T = 1;
    // cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
