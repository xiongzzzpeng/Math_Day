#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 60;
#define x first
#define y second
typedef pair<int, int> PII;

// 有点像灌溉问题
// https://www.acwing.com/problem/content/2062/

char speak[N][N];
int n, m;
vector<PII> points[2]; // 因为只有两个点
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int a, int b, vector<PII> &q)
{
    q.push_back({a, b});
    speak[a][b] = '.'; // 标记已使用
    for (int i = 0; i < 4; i++)
    {
        int x = a + dx[i], y = b + dy[i];
        if (x > 0 && x <= n && y > 0 && y <= m && speak[x][y] == 'X')
            dfs(x, y, q);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s", speak[i] + 1);
    int k = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (speak[i][j] == 'X')
                dfs(i, j, points[k++]);
    int res = 110;
    for (auto a : points[0])
        for (auto b : points[1])
            res = min(res, abs(a.x - b.x) + abs(a.y - b.y));
    printf("%d", res - 1);
    return 0;
}
