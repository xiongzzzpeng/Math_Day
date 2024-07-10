#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

// 最小瓶颈树：最大的边尽量小
// 最小生成树 -> 最小瓶颈树 但不能反
// https://www.luogu.com.cn/problem/P2330

struct UnionFind
{
    vector<int> father;
    int set;

    // 初始化
    UnionFind(int n) : father(n + 2, 0), set(n)
    {
        for (int i = 0; i <= n; i++)
            father[i] = i;
    }

    // 递归调用版本find
    int find(int i)
    {
        if (i != father[i])
            father[i] = find(father[i]);
        return father[i];
    }

    // 判断是不是同一个老大
    bool isSameSet(int x, int y)
    {
        return find(x) == find(y);
    }

    // 合并x跟y
    bool unionSets(int x, int y)
    {
        int fx = find(x), fy = find(y);
        if (fx != fy)
        {
            father[fx] = fy;
            return true;
        }
        else
            return false;
    }
};

struct edges
{
    int u, v, w;
};

void issue()
{
    int n, m;
    cin >> n >> m;
    vector<edges> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph.push_back({u, v, w});
    }

    sort(graph.begin(), graph.end(), [](const edges &a, const edges &b)
         { return a.w < b.w; });

    UnionFind ui(n + 1);
    int ans = 0, num_edge = 0;

    for (auto &edge : graph)
    {
        if (ui.unionSets(edge.u, edge.v))
        {
            ans = max(edge.w, ans);
            num_edge++;
        }

        if (num_edge == n - 1)
            break;
    }

    cout << n - 1 << " " << ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("xzp.in", "r", stdin);
    freopen("xzp.out", "w", stdout);
#endif

    int T = 1;
    // cin >> T;
    while (T--)
    {
        issue();
    }
    return 0;
}
