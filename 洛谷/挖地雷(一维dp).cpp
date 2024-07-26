#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

// 最长连通子序列
// 找dp路径和前驱结点
// https://www.luogu.com.cn/problem/P2196

void dfs(int x, vector<int> &p) {
    if (p[x] != -1)
        dfs(p[x], p);
    cout << x << ' ';
}

void Solve() {
    int n, ans = 0, pos;
    cin >> n;
    vector<int> num(n + 1), dp(n + 1), p(n + 1, -1);
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }

    dp[1] = num[1];
    for (int i = 1; i <= n; i++) {
        dp[i] = num[i];
        for (int j = i - 1; j > 0; j--) {
            if (graph[j][i] && dp[i] < dp[j] + num[i]) {
                dp[i] = dp[j] + num[i];
                p[i] = j;
            }
        }
        if (ans < dp[i]) {
            ans = dp[i];
            pos = i;
        }
    }

    dfs(pos, p);
    cout << endl
         << ans;
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
