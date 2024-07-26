#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

// ±³°üÎÊÌâ
// https://www.luogu.com.cn/problem/P1802

void Solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 2, vector<int>(m + 2, 0));
    vector<int> lose(n + 1), win(n + 1), use(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> lose[i] >> win[i] >> use[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (j >= use[i])
                dp[i][j] = max(dp[i - 1][j] + lose[i], dp[i - 1][j - use[i]] + win[i]);
            else
                dp[i][j] = dp[i - 1][j] + lose[i];
        }
    }

    cout << 5ll * dp[n][m] << endl;
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
