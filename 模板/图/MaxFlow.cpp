#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using i64 = long long;
using PII = pair<int, int>;
using PLL = pair<i64, i64>;
using u64 = unsigned long long;
using u32 = unsigned;

/*
最大流算法(O(n * m^2) n是边m是点)
也叫dinic算法
*/

template <typename T>
class MaxFlow {
   public:
    MaxFlow(int _n) {
        init(_n);
    }

    // 添加一条u -> v容量为c的边
    void addEdge(int u, int v, T c) {
        g[u].push_back(e.size());
        e.emplace_back(v, c);
        g[v].push_back(e.size());
        e.emplace_back(u, 0);
    }

    // 计算[s, t]最大流
    T flow(int s, int t) {
        T ans = 0;
        while (bfs(s, t)) {
            cur.assign(n, 0);
            ans += dfs(s, t, numeric_limits<T>::max());
        }
        return ans;
    }

    // 获取最小割
    vector<bool> minCut() {
        vector<bool> cut(n);
        for (int i = 0; i < n; ++i) {
            cut[i] = (h[i] != -1);
        }
        return cut;
    }

    struct EdgeInfo {
        int u, v;
        T cap, flow;
    };
    // 获取边的信息
    vector<EdgeInfo> getEdges() {
        vector<EdgeInfo> edgeList;
        for (int i = 0; i < e.size(); i += 2) {
            edgeList.push_back({e[i + 1].v, e[i].v, e[i].cap + e[i + 1].cap, e[i + 1].cap});
        }
        return edgeList;
    }

   private:
    struct Edge {
        int v;
        T cap;
        Edge(int _v, T _cap) : v(_v), cap(_cap) {}
    };

    int n;                  // 节点数量
    vector<Edge> e;         // 边的列表
    vector<vector<int>> g;  // 邻接表
    vector<int> cur, h;     // 当前边索引和高度

    void init(int _n) {
        n = _n;
        e.clear();
        g.assign(n, {});
        cur.resize(n);
        h.resize(n);
    }

    // 构建分层图
    bool bfs(int s, int t) {
        h.assign(n, -1);
        std::queue<int> q;
        h[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i : g[u]) {
                const auto& edge = e[i];
                if (edge.cap > 0 && h[edge.v] == -1) {
                    h[edge.v] = h[u] + 1;
                    if (edge.v == t) return true;
                    q.push(edge.v);
                }
            }
        }
        return false;
    }

    // 寻找增广路
    T dfs(int u, int t, T flow) {
        if (u == t) return flow;
        T remaining = flow;
        for (int& i = cur[u]; i < g[u].size(); ++i) {
            int j = g[u][i];
            auto& edge = e[j];
            if (edge.cap > 0 && h[edge.v] == h[u] + 1) {
                T pushed = dfs(edge.v, t, std::min(remaining, edge.cap));
                edge.cap -= pushed;
                e[j ^ 1].cap += pushed;
                remaining -= pushed;
                if (remaining == 0) return flow;
            }
        }
        return flow - remaining;
    }
};

void Solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    int N = 2 * n + 2;
    int s = 2 * n, t = 2 * n + 1;
    MaxFlow<int> g(N);

    const int B = __lg(n) + 1;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        const int b = __lg(a[i]) + 1;
        for (int j = 0, ed = min(b, B); j < ed; ++j) {
            int x = a[i] >> (b - j - 1);
            if (1 <= x && x <= n) {
                g.addEdge(x - 1, i + n, 1);
            }
        }
        g.addEdge(s, i, 1);
        g.addEdge(i + n, t, 1);
    }

    cout << (g.flow(s, t) == n ? "YES\n" : "NO\n");
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

#ifdef LOCAL
    freopen("zcy.in", "r", stdin);
    freopen("zcy.out", "w", stdout);
#endif

    int T = 1;
    cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
