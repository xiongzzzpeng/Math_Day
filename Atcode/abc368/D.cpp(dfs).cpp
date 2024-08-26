#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

// 不说树，本质上还是dfs找经过的点

void Solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> A(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v), A[v].push_back(u);
    }

    vector<int> ver(k + 1), st(n + 1);
    for (int i = 0; i < k; i++) {
        cin >> ver[i];
        st[ver[i]] |= 1;
    }

    auto dfs = [&](auto self, int u, int end) -> void {
        for (auto v : A[u]) {
            if (v == end) {
                continue;
            }
            self(self, v, u), st[u] |= st[v]; // 必须经过的点
        }
    };

    dfs(dfs, ver[0], -1);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += st[i];
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