#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void Solve() {
    int n;
    cin >> n;

    i64 x, y;
    cin >> x >> y;

    vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ranges::sort(a);

    i64 sum = reduce(a.begin(), a.end());
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        i64 lo = sum - a[i] - y, hi = sum - a[i] - x;
        int mx = upper_bound(a.begin(), a.end(), hi) - a.begin();
        int mn = lower_bound(a.begin(), a.end(), lo) - a.begin();
        ans += max(0, mx - mn);
        if (i >= mn && i < mx) {
            ans--;
        }
    }

    cout << ans / 2 << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T = 1;
    cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
