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
    vector<vector<int>> graph1; // �ڽӾ���
    vector<vector<PII>> graph2; // �ڽӱ�
    // ��ʽǰ����
    vector<int> head;   // ͷָ��,ͷ�ߵı��
    vector<int> nxt;    // �õ���һ���ƶ��ĵ�
    vector<int> to;     // Ŀ���
    vector<int> weigth; // �ߵ�Ȩֵ
    int cnt;            // ����,���Ŀ�ʼ

    // 11��10����1~11
    Use_map() : graph1(11, vector<int>(11, 0)), head(11), nxt(11), to(11), weigth(11)
    {
    }

    void build(int n)
    {
        // ��ʼ���ڽӾ���
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                graph1[i][j] = 0;
            }
        }

        // ��ʼ���ڽӱ�
        graph2.clear();
        graph2.resize(n + 1); // ׼���ڽӱ�

        // ��ʼ����ʽǰ����
        cnt = 1; // �ӽ��1��ʼ
        fill(head.begin(), head.end(), 0);
    }

    // ��ʽǰ���Ǽӱ�
    void addEdge(int u, int v, int w)
    {
        nxt[cnt] = head[u];
        to[cnt] = v;
        weigth[cnt] = w;
        head[u] = cnt++;
    }

    // ������ͼ��edges�Ǳ�
    void directGraph(vector<vector<int>> &edges)
    {
        // ���ڽӾ���
        for (auto &edge : edges)
        {
            graph1[edge[0]][edge[1]] = edge[2]; // from:0 to:1 Ȩֵ:2
        }

        // ���ڽӱ�
        for (auto &edge : edges)
        {
            graph2[edge[0]].push_back({edge[1], edge[2]}); // from:0 to:1 Ȩֵ:2
        }

        // ����ʽǰ����
        for (auto &edge : edges)
        {
            addEdge(edge[0], edge[1], edge[2]); // from:0 to:1 ��Ȩ:2
        }
    }

    // ������ͼ��edges�Ǳ�
    void undirectGraph(vector<vector<int>> &edges)
    {
        // ���ڽӾ���
        for (auto &edge : edges)
        {
            graph1[edge[0]][edge[1]] = edge[2]; // from:0 to:1 Ȩֵ:2
            graph1[edge[1]][edge[0]] = edge[2];
        }

        // ���ڽӱ�
        for (auto &edge : edges)
        {
            graph2[edge[0]].push_back({edge[1], edge[2]}); // from:0 to:1 Ȩֵ:2
            graph2[edge[1]].push_back({edge[0], edge[2]});
        }

        // ����ʽǰ����
        for (auto &edge : edges)
        {
            addEdge(edge[0], edge[1], edge[2]); // from:0 to:1 ��Ȩ:2
            addEdge(edge[1], edge[0], edge[2]);
        }
    }

    // ����ͼ
    void traversal(int n)
    {
        // �����ڽӾ���
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                cout << graph1[i][j] << " ";
            cout << endl;
        }

        // �����ڽӱ�
        for (int i = 1; i <= n; i++)
        {
            for (auto &edge : graph2[i])
                cout << edge.fs << "," << edge.sc << " "; // to:fs �߳�:sc
            cout << endl;
        }

        // ������ʽǰ����
        for (int i = 1; i <= n; i++)
        {
            for (int ei = head[i]; ei > 0; ei = nxt[ei])
                cout << to[ei] << "," << weigth[ei] << " "; // ��Ȩ
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
