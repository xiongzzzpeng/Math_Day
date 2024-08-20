#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

void Solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> cnt;
    ll ans = 0;
    vector<ll> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    ll L = pre[n];

    for (int i = 0; i < n; i++) {
        ans += cnt[(pre[i] - L % m + m) % m];
        ans += cnt[(pre[i] % m)]++;
    }

    cout << ans << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
