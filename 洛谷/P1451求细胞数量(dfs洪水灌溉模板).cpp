#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 110;

// https://www.luogu.com.cn/problem/P1451

char cell[N][N];
int n, m;
int st[N][N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y)
{
    st[x][y] = 1; // 这个点用过了，就不要判断了
    for (int i = 0; i < 4; i++)
    {
        int a = x + dx[i], b = y + dy[i];
        if (a < 1 || a > n || b < 1 || b > m)
            continue;
        if (st[a][b] == 1)
            continue;
        if (cell[a][b] == '0')
            continue;
        dfs(a, b);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s", cell[i] + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (st[i][j] == 0 && cell[i][j] != '0')
            {
                dfs(i, j);
                ans++;
            }
    printf("%d", ans);
    return 0;
}