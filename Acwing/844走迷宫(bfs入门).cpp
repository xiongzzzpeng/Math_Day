#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> PII; // 存坐标

//

const int N = 110;
int g[N][N];    // 存地图
int dist[N][N]; // 存距离
queue<PII> q;
int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int bfs(int x1, int y1)
{
    memset(dist, -1, sizeof dist);
    q.push({x1, y1});
    dist[x1][y1] = 0;

    while (!q.empty())
    {
        auto t = q.front(); // 取出队头
        q.pop();

        // 遍历四个方向
        for (int i = 0; i < 4; i++)
        {
            int a = t.first + dx[i], b = t.second + dy[i];

            if (a > n || a < 1 || b > m || b < 1)
                continue;
            if (g[a][b] != 0)
                continue;
            if (dist[a][b] > 0)
                continue;

            q.push({a, b});
            dist[a][b] = dist[t.first][t.second] + 1;
        }
    }
    return dist[n][m];
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &g[i][j]);
    int res = bfs(1, 1);
    printf("%d\n", res);
    return 0;
}
