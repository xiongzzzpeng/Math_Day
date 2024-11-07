#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

// hypot + INFINITY
// coutÊä³öÐ¡Êý

void Solve() {
    int N, S, T;
    cin >> N >> S >> T;

    vector<int> A(N), B(N), C(N), D(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    double ans = INFINITY;
    vector<bool> vis(N);
    auto dfs = [&](auto &self, int x, int y, double sum = 0.0, int c = 0) {
        if (c == N) {
            ans = min(ans, sum);
            return;
        }
        for (int i = 0; i < N; i++) {
            if (vis[i]) {
                continue;
            }
            double d1 = hypot(A[i] - x, B[i] - y);
            double d2 = hypot(C[i] - x, D[i] - y);
            double d0 = hypot(A[i] - C[i], B[i] - D[i]);
            vis[i] = true;
            self(self, C[i], D[i], sum + d1 / S + d0 / T, c + 1);
            self(self, A[i], B[i], sum + d2 / S + d0 / T, c + 1);
            vis[i] = false;
        }
    };

    dfs(dfs, 0, 0);
    cout << fixed << setprecision(20) << ans << "\n";
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
