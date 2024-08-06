#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

// 异或区间内的值的典题
// 拆位操作

void Solve() {
    int n;
    cin >> n;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<ll> f(n + 2);
    ll ans = 0;

    // i是拆位，j是当前位结束, 2^i * f(i )
    for (int i = 0; i < 30; i++) {
        for (int j = 1; j <= n; j++) {
            int b = (a[j] >> i) & 1;
            f[j] = b == 1 ? (j - 1 - f[j - 1]) : f[j - 1];
            ans += (1 << i) * f[j];
            f[j] += b;
        }
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
