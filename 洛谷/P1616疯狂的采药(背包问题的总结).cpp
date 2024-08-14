#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

// 背包问题的总结

// 01背包：dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + val[i])
// 完全背包: dp[i][j] = max(dp[i][j], dp[i][j - cost[i]] + val[i])
// 分组背包: dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[k]] + val[k])
// 有依赖背包: 记录附属情况 看p1064

// 01背白：dp[j] = max(dp[j], dp[j - cost[i]] + val[i]) j: [t, cost[i]] j--
// 完全背包: dp[j] = max(dp[j], dp[j - cost[i]] + val[i]) j: [cost[i], t] j++

void Solve() {
    int n, m;
    cin >> m >> n;

    vector<ll> cost(n + 1), val(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> cost[i] >> val[i];
    }

    vector<ll> dp(m + 1);
    for (ll i = 1; i <= n; i++) {
        for (ll j = cost[i]; j <= m; j++) {
            dp[j] = max(dp[j], dp[j - cost[i]] + val[i]);
        }
    }

    cout << dp[m] << endl;
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
