#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

// 动态规划
// 数的映射

void Solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;
    s = " " + s;

    vector<vector<int>> f(n + 1, vector<int>(3));
    f[0][0] = f[0][1] = f[0][2] = 0;

    map<char, int> mp;
    mp['R'] = 0, mp['P'] = 1, mp['S'] = 2;

    auto check = [&](int x, int y) {
        if (y == ((x + 1) % 3))
            return 1;
        else
            return 0;
    };

    // i当前的，j上一步的，k是现在可以出的
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j != k) {
                    if (!check(k, mp[s[i]])) {
                        f[i][k] = max(f[i][k], f[i - 1][j] + check(mp[s[i]], k));
                    }
                }
            }
        }
    }

    int ans = max({f[n][0], f[n][1], f[n][2]});
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
