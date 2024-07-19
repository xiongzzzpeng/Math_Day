#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

// sc_distance就是次短路
// 用第二个数组维护就行

void Solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<PII>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    // 记录源点到每个点的距离,并且初始化
    vector<int> distance(n + 1, INT_MAX);
    vector<int> sc_distance(n + 1, INT_MAX);
    distance[1] = 0;
    // 每个点是否访问过
    vector<bool> visited(n + 1, false);
    // 小根堆,前点，后距离
    auto cmp = [](PII &a, PII &b) {
        return a.sc > b.sc;
    };
    priority_queue<PII, vector<PII>, decltype(cmp)> heap(cmp);
    // 源点添加
    heap.emplace(1, 0);

    while (!heap.empty()) {
        int u = heap.top().fs;
        int d = heap.top().sc;
        heap.pop();

        for (auto &edge : graph[u]) {
            int v = edge.fs;
            int w = edge.sc;
            int new_dist = d + w;
            if (new_dist < distance[v]) {
                sc_distance[v] = distance[v];
                distance[v] = new_dist;
                heap.emplace(v, new_dist);
            } else if (new_dist > distance[v] && new_dist < sc_distance[v]) {
                sc_distance[v] = new_dist;
                heap.emplace(v, new_dist);
            }
        }
    }

    cout << sc_distance[n] << endl;
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