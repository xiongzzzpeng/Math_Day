#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 40;
typedef pair<int, int> PII;

// https://www.luogu.com.cn/problem/P1162

int n;
int maze[N][N];
bool st[N][N];
PII q[N * N];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int x, int y)
{
    q[0] = {x, y};
    st[x][y] = true;
    int hh = 0, tt = 0;

    while (hh <= tt)
    {
        auto t = q[hh++];
        for (int i = 0; i < 4; i++)
        {
            int a = t.first + dx[i], b = t.second + dy[i];
            if (a < 0 || a > n + 1 || b < 0 || b > n + 1)
                continue;
            if (st[a][b])
                continue;
            if (maze[a][b] == 1)
                continue;
            st[a][b] = true;
            q[++tt] = {a, b};
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &maze[i][j]);
    bfs(0, 0); // 最外圈要有一圈0，能把边界判断清楚
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (maze[i][j] == 0 && !st[i][j])
                maze[i][j] = 2;
            printf("%d ", maze[i][j]);
        }
        puts("");
    }

    return 0;
}
