#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>
#define fs first
#define sc second
using i64 = long long;

void Solve() {
    int n, m;
    cin >> n >> m;

    vector<PII> a;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        a.emplace_back(l, r);
    }

    sort(a.begin(), a.end());

    // 算单点贡献
    i64 ans = 0;       // (1 3) (2 4)
    int r_mn = m + 1;  // 如 4会贡献 (4 4) 3会贡献(3 4)所以从5开始算
    int len = a.size() - 1;
    for (int i = m; i >= 1; i--) {
        while (len >= 0 && a[len].fs >= i) {
            r_mn = min(r_mn, a[len].sc);
            len--;
        }
        ans += r_mn - i;
    }
    cout << ans << "\n";
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
