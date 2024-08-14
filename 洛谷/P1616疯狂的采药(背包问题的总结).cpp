#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

// ����������ܽ�

// 01������dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + val[i])
// ��ȫ����: dp[i][j] = max(dp[i][j], dp[i][j - cost[i]] + val[i])
// ���鱳��: dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[k]] + val[k])
// ����������: ��¼������� ��p1064

// 01���ף�dp[j] = max(dp[j], dp[j - cost[i]] + val[i]) j: [t, cost[i]] j--
// ��ȫ����: dp[j] = max(dp[j], dp[j - cost[i]] + val[i]) j: [cost[i], t] j++

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
