#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> PII;
const int N = 1010;

// https://www.acwing.com/problem/content/description/175/

int dist[N][N];
int n, m;
PII q[N * N];
int hh = 0, tt = -1;
int g[N][N];
int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};

void bfs()
{
    while (hh <= tt)
    {
        auto t = q[hh++];
        for (int i = 0; i < 4; i++)
        {
            int a = t.first + dx[i], b = t.second + dy[i];
            if (a > n || a < 1 || b > m || b < 1)
                continue;
            if (dist[a][b] >= 0)
                continue;
            if (g[a][b] == 1)
                continue;
            dist[a][b] = dist[t.first][t.second] + 1;
            q[++tt] = {a, b};
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(dist, -1, sizeof dist);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            g[i][j] = ch - '0';
            if (ch == '1')
            {
                q[++tt] = {i, j};
                dist[i][j] = 0;
            }
        }
    bfs();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            printf("%d ", dist[i][j]);
        }
        puts("");
    }

    return 0;
}
