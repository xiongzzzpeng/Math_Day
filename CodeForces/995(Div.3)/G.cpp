#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void Solve() {
    int n, q;
    cin >> n >> q;

    vector<vector<vector<int>>> adj(n, vector<vector<int>>(n, vector<int>(2, 0)));
    while (q--) {
        int s;
        char t;
        cin >> s >> t;
        s--;
        if (t == '+') {
            for (int j = 0; j < n; j++) {
                if (adj[s][j][1])
                    adj[s][j][1]--;
                else
                    adj[s][j][0]++;
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (i != s) adj[i][s][1]++;
            }
        }
    }
    vector<vector<int>> f(1 << n, vector<int>(n, 1e9));
    for (int i = 1; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                int m = i ^ (1 << j);
                if (!m) {
                    f[i][j] = 0;
                    continue;
                }
                int mn = 1e9;
                for (int k = 0; k < n; k++) mn = min(mn, f[m][k] + max(0, adj[k][j][0]));
                f[i][j] = mn;
            }
        }
    }

    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        ans = min(ans, f[(1 << n) - 1][i] + n + adj[i][i][0]);
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
