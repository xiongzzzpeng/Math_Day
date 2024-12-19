#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

/**
 * SPFA(O(n * m))
 * 可以处理负边的最短路 dis[i]是最短路
 */

struct SPFA {
    vector<vector<PII>> graph;
    vector<int> distance, update;
    vector<bool> enter;

    SPFA(int node) {
        graph.resize(node + 1);
        distance.resize(node + 1, INT32_MAX);
        update.resize(node + 1, 0);
        enter.resize(node + 1, false);
    }

    void build(int n) {
        for (int i = 0; i <= n; i++) {
            graph[i].clear();
        }
        fill(enter.begin(), enter.begin() + n + 1, false);
        fill(distance.begin(), distance.begin() + n + 1, INT32_MAX);
        fill(update.begin(), update.begin() + n + 1, 0);
    }

    void addEdge(int u, int v, int w) {
        graph[u].emplace_back(v, w);
    }

    bool spfa(int n) {
        queue<int> q;
        distance[1] = 0;
        update[1]++;
        q.push(1);
        enter[1] = true;

        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            enter[u] = false;

            for (auto &edge : graph[u]) {
                int v = edge.fs;
                int w = edge.sc;

                if (distance[u] + w < distance[v]) {
                    distance[v] = distance[u] + w;
                    if (!enter[v]) {
                        // 一般改这个
                        if (update[v]++ == n) return true;
                        q.push(v);
                        enter[v] = true;
                    }
                }
            }
        }
        return false;
    }
};

void Solve() {
    int n, m;
    cin >> n >> m;

    SPFA sf(n);
    sf.build(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        if (w >= 0) {
            sf.addEdge(u, v, w);
            sf.addEdge(v, u, w);
        } else {
            sf.addEdge(u, v, w);
        }
    }

    cout << (sf.spfa(n) ? "YES" : "NO") << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("xzp.in", "r", stdin);
    freopen("xzp.out", "w", stdout);
#endif

    int T = 1;
    cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
