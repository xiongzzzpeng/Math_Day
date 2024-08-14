#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

// Ç°×ººÍ

void Solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    string s;
    cin >> s;

    vector<ll> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    vector<int> l, r;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L')
            l.push_back(i);
        else
            r.push_back(i);
    }

    reverse(r.begin(), r.end());

    ll ans = 0;
    for (int i = 0; i < min(l.size(), r.size()); i++) {
        if (l[i] < r[i]) {
            ans += pre[r[i] + 1] - pre[l[i]];
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
    cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
