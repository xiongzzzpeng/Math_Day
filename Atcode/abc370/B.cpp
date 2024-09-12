#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

void Solve() {
    int n;
    cin >> n;

    // 补全,相当于一张表
    vector<vector<int>> A(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> A[i][j];
            A[i][j]--;
            A[j][i] = A[i][j];
        }
    }

    // i是第几个
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = A[ans][i];
    }

    cout << ans + 1 << endl;
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
