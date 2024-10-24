#include <bits/stdc++.h>
using namespace std;

// 看最小环的路，就是最短路 + 1

void Solve() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }

    vector<int> dis(n, -1);
    queue<int> q;
    dis[0] = 0;
    q.push(0);

    int ans = n + 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (auto y : adj[x]) {
            if (y == 0) {
                ans = min(ans, dis[x] + 1);
            }
            if (dis[y] == -1) {
                dis[y] = dis[x] + 1;
                q.push(y);
            }
        }
    }
    if (ans > n) {
        ans = -1;
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
