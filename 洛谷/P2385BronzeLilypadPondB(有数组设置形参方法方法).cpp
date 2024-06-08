#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 40;
typedef pair<int, int> PII;

// https://www.luogu.com.cn/problem/P2385

int dist[N][N];
int m, n, m1, m2;
int g[N][N];
PII q[N * N];

int bfs(int x, int y, int x2, int y2, int dx[], int dy[]) // 不是全局变量和vector的数组设置方法
{
    memset(dist, -1, sizeof dist);
    q[0] = {x, y};
    dist[x][y] = 0;
    int hh = 0, tt = 0;

    while (hh <= tt)
    {
        auto t = q[hh++];
        for (int i = 0; i < 8; i++)
        {
            int a = t.first + dx[i], b = t.second + dy[i];
            if (a < 1 || a > m || b < 1 || b > n)
                continue;
            if (g[a][b] == 2 || g[a][b] == 3 || g[a][b] == 0)
                continue;
            if (dist[a][b] > 0)
                continue;

            dist[a][b] = dist[t.first][t.second] + 1;
            q[++tt] = {a, b};
        }
    }
    return dist[x2][y2];
}

int main()
{
    int x, y, x2, y2;
    scanf("%d%d%d%d", &m, &n, &m1, &m2);
    int dx[] = {m1, m1, -m1, -m1, m2, m2, -m2, -m2}; // 这种不能开全局变量
    int dy[] = {m2, -m2, m2, -m2, m1, -m1, m1, -m1};
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &g[i][j]);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            if (g[i][j] == 3)
                x = i, y = j;
            if (g[i][j] == 4)
            {
                x2 = i, y2 = j;
                break;
            }
        }
    int res = bfs(x, y, x2, y2, dx, dy);
    printf("%d %d", res);

    return 0;
}
