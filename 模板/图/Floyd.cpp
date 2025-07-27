#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr i64 INF = 1E18;

// Floyd算法
// 得到任意两点的最短距离，无负环图适用
// O(n^3)
void floyed(vector<vector<int>> &dist, bool &negative_cycle) {
    int n = dist.size();
    negative_cycle = false;
    for (int k = 0; k < n; ++k) {
        for (int From = 0; From < n; ++From) {
            for (int To = 0; To < n; ++To) {
                if (dist[From][k] < INF && dist[k][To] < INF) {
                    dist[From][To] = min(dist[From][To], dist[From][k] + dist[k][To]);
                }
                if (From == To && dist[From][To] < 0) {
                    negative_cycle = true;
                }
            }
        }
    }
}

void Solve() {
    int n, m;
    cin >> n >> m;

    vector<int> path(m);
    for (int i = 0; i < m; i++) {
        cin >> path[i];
        path[i]--;
    }

    vector<vector<int>> distance(n, vector<int>(n, INT32_MAX));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> distance[i][j];
        }
    }

    bool negative_cycle;
    floyed(distance, negative_cycle);

    int ans = 0;
    for (int i = 1; i < m; i++) {
        ans += distance[path[i - 1]][path[i]];
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
