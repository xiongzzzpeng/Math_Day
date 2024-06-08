#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 10;

// https://www.luogu.com.cn/problem/P1605

bool st[N][N];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int maze[N][N];
int res = 0;
int n, m, t;

void dfs(int sx, int sy, int fx, int fy)
{
    if (sx == fx && sy == fy)
    {
        res++;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int a = sx + dx[i], b = sy + dy[i];
        if (a < 1 || a > n || b < 1 || b > m)
            continue;
        if (maze[a][b] != 0)
            continue;
        if (st[a][b])
            continue;
        st[a][b] = true;
        dfs(a, b, fx, fy);
        st[a][b] = false;
    }
    return;
}

int main()
{
    scanf("%d%d%d", &n, &m, &t);
    int sx, sy, fx, fy;
    scanf("%d%d%d%d", &sx, &sy, &fx, &fy);
    while (t--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        maze[a][b] = 1;
    }
    st[sx][sy] = true; // ¹Ø¼ü£¬²»Ð´ÈÝÒ×´í
    dfs(sx, sy, fx, fy);
    cout << res;
    return 0;
}
