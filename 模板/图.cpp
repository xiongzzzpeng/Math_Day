#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

struct Use_map
{
    vector<vector<int>> graph1; // 邻接矩阵
    vector<vector<PII>> graph2; // 邻接表

    // 11是10个点1~11
    Use_map() : graph1(11, vector<int>(11, 0))
    {
    }

    void build(int n)
    {
        // 初始化邻接矩阵
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                graph1[i][j] = 0;
            }
        }

        // 初始化邻接表
        graph2.clear();
        graph2.resize(n + 1); // 准备邻接表
    }

    // 建有向图，edges是边
    void directGraph(vector<vector<int>> &edges)
    {
        // 建邻接矩阵
        for (auto &edge : edges)
        {
            graph1[edge[0]][edge[1]] = edge[2]; // from:0 to:1 权值:2
        }

        // 建邻接表
        for (auto &edge : edges)
        {
            graph2[edge[0]].push_back({edge[1], edge[2]}); // from:0 to:1 权值:2
        }
    }

    // 建无向图，edges是边
    void undirectGraph(vector<vector<int>> &edges)
    {
        // 建邻接矩阵
        for (auto &edge : edges)
        {
            graph1[edge[0]][edge[1]] = edge[2]; // from:0 to:1 权值:2
            graph1[edge[1]][edge[0]] = edge[2];
        }

        // 建邻接表
        for (auto &edge : edges)
        {
            graph2[edge[0]].push_back({edge[1], edge[2]}); // from:0 to:1 权值:2
            graph2[edge[1]].push_back({edge[0], edge[2]});
        }
    }

    // 遍历图
    void traversal(int n)
    {
        // 遍历邻接矩阵
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                cout << graph1[i][j] << " ";
            cout << endl;
        }

        // 遍历邻接表
        for (int i = 1; i <= n; i++)
        {
            for (auto &edge : graph2[i])
                cout << edge.fs << "," << edge.sc << " "; // to:fs 边长:sc
            cout << endl;
        }
    }
};

void issue()
{
    Use_map g;

    int n1 = 4;
    vector<vector<int>> edges1 = {{1, 3, 6}, {4, 3, 4}, {2, 4, 2}, {1, 2, 7}, {2, 3, 5}, {3, 1, 1}};
    g.build(n1);
    g.directGraph(edges1);
    g.traversal(n1);
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
    cin >> T;
    while (T--)
    {
        issue();
    }
    return 0;
}
