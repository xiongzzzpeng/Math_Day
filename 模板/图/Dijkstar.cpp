#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

// Dijkstra
// ʹ�÷�Χ:����ͼ�����޸���
// ��Դ�㵽ÿ��������·


// ��ά���
int dijkstar_tow(vector<vector<int>> &grid)
{
    int move[] = {-1, 0, 1, 0, -1};
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> distance(n, vector<int>(m, INT32_MAX));
    distance[0][0] = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    auto cmp = [](vector<int> &a, vector<int> &b)
    {
        return a[2] > b[2];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> heap(cmp);
    heap.push({0, 0, grid[0][0]});

    while (!heap.empty())
    {
        auto u = heap.top();
        heap.pop();

        int x = u[0], y = u[1], w = u[2];
        if (visited[x][y])
            continue;

        if (x == n - 1 && y == m - 1)
            return w;
        visited[x][y] = true;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + move[i], ny = y + move[i + 1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny])
            {
                int nw = max(w, grid[nx][ny]); // һ������
                if (nw < distance[nx][ny])
                {
                    distance[nx][ny] = nw;
                    heap.push({nx, ny, nw});
                }
            }
        }
    }

    return -1;
}

int dijkstar(vector<vector<int>> &times, int n, int s)
{
    // nͼ�е��������s��Դ��
    vector<vector<PII>> graph(n + 1);
    for (auto &edge : times)
        graph[edge[0]].emplace_back(edge[1], edge[2]);

    // ��¼Դ�㵽ÿ����ľ���,���ҳ�ʼ��
    vector<int> distance(n + 1, INT_MAX);
    distance[s] = 0;
    // ÿ�����Ƿ���ʹ�
    vector<bool> visited(n + 1, false);
    // С����,ǰ�㣬�����
    auto cmp = [](PII &a, PII &b)
    {
        return a.sc > b.sc;
    };
    priority_queue<PII, vector<PII>, decltype(cmp)> heap(cmp);
    // Դ�����
    heap.emplace(s, 0);

    while (!heap.empty())
    {
        int u = heap.top().fs;
        heap.pop();

        if (visited[u])
            continue;
        visited[u] = true;

        for (auto &edge : graph[u])
        {
            int v = edge.fs;
            int w = edge.sc;
            if (!visited[v] && distance[u] + w < distance[v])
            {
                distance[v] = distance[u] + w;
                heap.emplace(v, distance[v]);
            }
        }
    }

    int ans = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        if (distance[i] == INT_MAX)
            return -1;
        ans = max(ans, distance[i]);
    }
    return ans;
}

void issue()
{
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<PII>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }

    // ��¼Դ�㵽ÿ����ľ���,���ҳ�ʼ��
    vector<int> distance(n + 1, INT_MAX);
    distance[s] = 0;
    // ÿ�����Ƿ���ʹ�
    vector<bool> visited(n + 1, false);
    // С����,ǰ�㣬�����
    auto cmp = [](PII &a, PII &b)
    {
        return a.sc > b.sc;
    };
    priority_queue<PII, vector<PII>, decltype(cmp)> heap(cmp);
    // Դ�����
    heap.emplace(s, 0);

    while (!heap.empty())
    {
        int u = heap.top().fs;
        heap.pop();

        if (visited[u])
            continue;
        visited[u] = true;

        for (auto &edge : graph[u])
        {
            int v = edge.fs;
            int w = edge.sc;
            if (!visited[v] && distance[u] + w < distance[v])
            {
                distance[v] = distance[u] + w;
                heap.emplace(v, distance[v]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << distance[i] << " ";
    cout << endl;
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
