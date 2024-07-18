#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

// Floyd算法
// 得到任意两点的最短距离，无负环图适用
// O(n^3)

void floyd(vector<vector<int>> &distance, int n) {
    // 找一个跳点,看路劲是不是能变小
    // 转移方程就是:dist[i][j] = min(dist[i][j], dist[i][mid]+dist[mid][j])

    for (int mid = 0; mid < n; mid++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (distance[i][mid] != INT32_MAX && distance[mid][j] != INT32_MAX && distance[i][j] > distance[i][mid] + distance[mid][j])
                    distance[i][j] = distance[i][mid] + distance[mid][j];
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

    floyd(distance, n);

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
