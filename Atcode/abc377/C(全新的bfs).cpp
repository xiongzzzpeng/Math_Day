#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void Solve() {
    int dx[] = {0, 2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};

    int n, m;
    cin >> n >> m;

    set<array<int, 2>> s;
    i64 ans = 1LL * n * n;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        for (int k = 0; k < 9; k++) {
            int x = a + dx[k];
            int y = b + dy[k];
            if (x >= 1 && x <= n && y >= 1 && y <= n && (s.find({x, y}) == s.end())) {
                ans--;
                s.insert({x, y});
            }
        }
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
