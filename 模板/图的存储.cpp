#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
typedef pair<int, int> PII;
const int N = 1e6 + 10;

int w[N][N];           // ��ͼ[a, b]�ı�=x
int vis[N], idx, h[N]; // �ж��ظ�,idx�Ǳߵı�ţ�h[u]��u�����ĵ�һ�����ߵı��

// ��ʽǰ����
struct edge_3
{
    int v, w, ne; // ne����һ���ߵı��
};
edge_3 e3[N]; // e[i]�ǵ�i����

// ��ѯ
void dfs_chia_start(int u, int fa)
{
    for (int i = h[u]; ~i; i = e3[i].ne) // ~i����Ƿ���-1
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
        cin >> a >> b >> c; // ��㣬�յ㣬Ȩֵ
        add(a, b, c);
        add(b, a, c);
    }
}

// �ڽ�ͼ
struct edge
{
    int v, w; // v���յ㣬w��ֵ
};
vector<edge> e2[N]; // e[i]�Ǵ�i������ÿ����ı߼�

// ����ͼ
// u�Ǵ��ĸ��㿪ʼ�ѣ�fa�Ǹ��ڵ�
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

// �߼�����
struct Edge
{
    int u, v, w; // ��㡣�յ㣬Ȩֵ
} e[N];
// ����
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
    { // ��0��ʼ����Ϊ��������ͨ���Ǵ�0��ʼ��
        int a, b, c;
        cin >> a >> b >> c;
        e[i] = {a, b, c};
    }
}

// �ڽӾ���
// ���Ҹ�ͼ
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
        w[a][b] = c; // a��b�ı�=c
        // w[b][a] = c; ����ͼ�ټ�һ�����
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
