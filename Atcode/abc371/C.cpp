#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
using i64 = long long;
using PII = pair<int, int>;
using PLL = pair<i64, i64>;
using u64 = unsigned long long;
using u32 = unsigned;

// iota 和 next_permutation的学习
// next_permutation(a.begin(), a.end())

void Solve() {
    int n;
    cin >> n;

    int MG;
    cin >> MG;

    vector G(n, vector(n, 0));
    for (int i = 0; i < MG; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u][v] = 1;
        G[v][u] = 1;
    }

    int MH;
    cin >> MH;

    vector H(n, vector(n, 0));
    for (int i = 0; i < MH; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        H[u][v] = 1;
        H[v][u] = 1;
    }

    vector A(n, std::vector(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            std::cin >> A[i][j];
        }
    }

    vector<int> p(n);
    iota(p.begin(), p.end(), 0);  // 从0开始 0 ~ n - 1

    int ans = INT_MAX;
    do {
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (H[i][j] != G[p[i]][p[j]]) {
                    res += A[i][j];
                }
            }
        }
        ans = min(ans, res);
    } while (next_permutation(p.begin(), p.end()));  // 生成所有的排列组合

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
