#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

// 关键是记录附件的情况
// 有依赖背包

void Solve2() {
    int m, n;
    cin >> m >> n;

    vector<ll> cost(n + 1), val(n + 1), king(n + 1), fans(n + 1);
    vector<vector<ll>> follow(n + 1, vector<ll>(2, -1));
    for (ll i = 1; i <= n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        cost[i] = a, val[i] = a * b;
        king[i] = (c == 0);
        if (c != 0) {
            follow[c][fans[c]++] = i;
        }
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
    ll p = 0;
    for (ll i = 1; i <= n; i++) {
        if (king[i]) {
            for (ll j = 0; j <= m; j++) {
                dp[i][j] = dp[p][j];
                if (j >= cost[i]) {
                    dp[i][j] = max(dp[i][j], dp[p][j - cost[i]] + val[i]);
                }
                ll fan1 = (fans[i] >= 1) ? follow[i][0] : -1;
                ll fan2 = (fans[i] >= 2) ? follow[i][1] : -1;
                if (fan1 != -1 && j >= cost[i] + cost[fan1]) {
                    dp[i][j] = max(dp[i][j], dp[p][j - cost[i] - cost[fan1]] + val[i] + val[fan1]);
                }
                if (fan2 != -1 && j >= cost[i] + cost[fan2]) {
                    dp[i][j] = max(dp[i][j], dp[p][j - cost[i] - cost[fan2]] + val[i] + val[fan2]);
                }
                if (fan1 != -1 && fan2 != -1 && j >= cost[i] + cost[fan1] + cost[fan2]) {
                    dp[i][j] = max(dp[i][j], dp[p][j - cost[i] - cost[fan1] - cost[fan2]] + val[i] + val[fan1] + val[fan2]);
                }
            }
            p = i;
        }
    }

    cout << dp[p][m] << endl;
}

void Solve() {
    int m, n;
    cin >> m >> n;

    vector<ll> cost(n + 1), val(n + 1), king(n + 1), fans(n + 1);
    vector<vector<ll>> follow(n + 1, vector<ll>(2, -1));
    for (ll i = 1; i <= n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        cost[i] = a, val[i] = a * b;
        king[i] = (c == 0);
        if (c != 0) {
            follow[c][fans[c]++] = i; // 记录有多少附属物 如c==4 [4][0] = i
        }
    }

    int p = 0;
    vector<ll> dp(m + 1);
    for (int i = 1; i <= n; i++) {
        if (king[i]) {
            for (int j = m; j >= cost[i]; j--) {
                dp[j] = max(dp[j], dp[j - cost[i]] + val[i]);
                int fan1 = fans[i] >= 1 ? follow[i][0] : -1;
                int fan2 = fans[i] >= 2 ? follow[i][1] : -1;
                if (fan1 != -1 && j - cost[i] - cost[fan1] >= 0) {
                    dp[j] = max(dp[j], dp[j - cost[i] - cost[fan1]] + val[i] + val[fan1]);
                }
                if (fan2 != -1 && j - cost[i] - cost[fan2] >= 0) {
                    dp[j] = max(dp[j], dp[j - cost[i] - cost[fan2]] + val[i] + val[fan2]);
                }
                if (fan1 != -1 && fan2 != -1 && j - cost[i] - cost[fan1] - cost[fan2] >= 0) {
                    dp[j] = max(dp[j],
                                dp[j - cost[i] - cost[fan1] - cost[fan2]] + val[i] + val[fan1] + val[fan2]);
                }
            }
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
