#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

// 背包问题求最小值
// 最小是可能超出的范围的，要在超出里面比较
// 最小记得把第一个位置设为0

void Solve() {
    int n, h;
    cin >> n >> h;

    int maxv = 0;
    vector<int> cost(n + 1), val(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> val[i] >> cost[i];
        maxv = max(maxv, val[i]);
    }

    int m = h + maxv;
    vector<int> dp(m + 2, INT32_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = val[i]; j <= m; j++) {
            if (dp[j - val[i]] != INT32_MAX)
                dp[j] = min(dp[j], dp[j - val[i]] + cost[i]);
        }
    }

    int ans = INT32_MAX;
    for (int i = h; i <= m; i++) {
        ans = min(ans, dp[i]);
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
