#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

// P1002 过河卒
// https://www.luogu.com.cn/problem/P1002

void Solve() {
    // 马移动距离
    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    int bx, by, mx, my;
    cin >> bx >> by >> mx >> my;
    bx += 2, by += 2, mx += 2, my += 2;
    vector<vector<bool>> visited(bx + 3, vector<bool>(by + 3, false));
    vector<vector<ll>> dp(bx + 3, vector<ll>(by + 3));

    dp[2][1] = 1;
    visited[mx][my] = true;
    for (ll i = 0; i < 8; i++)
        visited[mx + dx[i]][my + dy[i]] = true;
    for (ll i = 2; i <= bx; i++) {
        for (ll j = 2; j <= by; j++) {
            if (visited[i][j])
                continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    cout << dp[bx][by] << endl;
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
