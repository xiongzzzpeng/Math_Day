#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
typedef pair<int, int> PII;
const int N = 1e6 + 10;

int w[N][N];           // 存图[a, b]的边=x
int vis[N], idx, h[N]; // 判断重复,idx是边的编号，h[u]从u出发的第一条出边的编号

// 链式前向星
struct edge_3
{
    int v, w, ne; // ne是下一条边的编号
};
edge_3 e3[N]; // e[i]是第i个边

// 查询
void dfs_chia_start(int u, int fa)
{
    for (int i = h[u]; ~i; i = e3[i].ne) // ~i检查是否是-1
    {
        int v = e3[i].v, w = e3[i].w;
        if (v == fa)
            continue;
        dfs_chia_start(fa, u);
    }
}

void add(int a, int b, int c)
{
    e[idx] = {a, b, h[a]};
    h[a] = idx++;
}

void chia_start(int m)
{
    memset(h, -1, sizeof h);
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c; // 起点，终点，权值
        add(a, b, c);
        add(b, a, c);
    }
}

// 邻接图
struct edge
{
    int v, w; // v是终点，w是值
};
vector<edge> e2[N]; // e[i]是从i出发到每个点的边集

// 查找图
// u是从哪个点开始搜，fa是父节点
void dfs_adj_map(int u, int fa)
{
    for (auto ed : e2[u])
    {
        int v = ed.v, w = ed.w;
        if (v == fa)
            continue;
        cout << u << v << w << endl;
        dfs_adj_map(v, u);
    }
}

void adj_map(int m)
{
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        e2[a].push_back({b, c});
        e2[b].push_back({a, c});
    }
}

// 边集数组
struct Edge
{
    int u, v, w; // 起点。终点，权值
} e[N];
// 查找
void dfs_edge(int m, int u)
{
    vis[u] = true;
    for (int i = 1; i <= m; i++)
    {
        if (e[i].u == u)
        {
            int v = e[i].v, w = e[i].w;
            cout << u << v << w;
            if (vis[v])
                continue;
            dfs_edge(m, e[i].v);
        }
    }
}

void edge_map(int m)
{
    for (int i = 1; i <= m; i++)
    { // 从0开始，因为数组索引通常是从0开始的
        int a, b, c;
        cin >> a >> b >> c;
        e[i] = {a, b, c};
    }
}

// 邻接矩阵
// 查找该图
void dfs_adj(int u, int m)
{
    vis[u] = true;
    for (int v = 0; v <= m; v++)
    {
        if (w[u][v])
        {
            cout << u << v << w[u][v];
            if (vis[v])
                continue;
            dfs_adj(v, m);
        }
    }
}

void adj_mat(int m)
{
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        w[a][b] = c; // a到b的边=c
        // w[b][a] = c; 无向图再加一个这个
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("xzp.in", "r", stdin);
    freopen("xzp.out", "w", stdout);

    return 0;
}
