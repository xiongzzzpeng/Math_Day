#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

// 二分答案法，第二种形式

void Solve() {
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll l = 0, r = m + 1;
    // ranges::sort(a);

    ll ans = 0;
    while (l <= r) {
        ll mid = (l + r) >> 1, tot = 0;
        for (int i = 0; i < n; i++) {
            tot += min(mid, a[i]);
        }
        if (tot <= m) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    if (ans > m) {
        cout << "infinite" << endl;
        return;
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
