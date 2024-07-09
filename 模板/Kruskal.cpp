#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

// ��С������_k�㷨
struct UnionFind
{
    vector<int> father;
    int set;

    // ��ʼ��
    UnionFind(int n) : father(n + 2, 0), set(n + 1)
    {
        for (int i = 0; i <= n; i++)
            father[i] = i;
    }

    // �ݹ���ð汾find
    int find(int i)
    {
        if (i != father[i])
            father[i] = find(father[i]);
        return father[i];
    }

    // �ж��ǲ���ͬһ���ϴ�
    bool isSameSet(int x, int y)
    {
        return find(x) == find(y);
    }

    // �ϲ�x��y
    bool unionSets(int x, int y)
    {
        int fx = find(x);
        int fy = find(y);
        if (fx != fy)
        {
            father[fx] = fy;
            return true;
        }
        else
            return false;
    }
};

struct Edge
{
    int u, v, w;
};

void issue()
{
    int n, m;
    cin >> n >> m;
    UnionFind ui(n);
    vector<Edge> graph(n + 1);

    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph.push_back({u, v, w});
    }

    // ����Ȩֵ����
    sort(graph.begin(), graph.end(), [](const Edge &a, const Edge &b)
         { return a.w < b.w; });

    int ans = 0;
    int num_edge = 0;
    for (auto &edge : graph)
    {
        if (ui.unionSets(edge.u, edge.v))
        {
            num_edge++;
            ans += edge.w;
        }
    }

    if (num_edge == n - 1)
        cout << ans << endl;
    else
        cout << "orz" << endl;
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
