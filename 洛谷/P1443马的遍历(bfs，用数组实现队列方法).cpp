#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> PII;

// https://www.luogu.com.cn/problem/P1443
const int N = 410;
int n, m;
int g[N][N];
PII q[N * N]; // �ö���ģ������
int dist[N][N];
int dx[] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};

void bfs(int x, int y)
{
    memset(dist, -1, sizeof dist);
    q[0] = {x, y}; // ���
    dist[x][y] = 0;
    int hh = 0, tt = 0; // ��ͷ����β�� ��hh <= ttʱ���ǿ�

    while (hh <= tt)
    {
        auto t = q[hh++]; // ȡ����ͷ,���ҳ���
        for (int i = 0; i < 8; i++)
        {
            int a = t.first + dx[i], b = t.second + dy[i];
            if (a < 1 || a > n || b < 1 || b > m)
                continue;
            if (dist[a][b] >= 0)
                continue;

            dist[a][b] = dist[t.first][t.second] + 1;
            q[++tt] = {a, b}; // ����Ԫ��
        }
    }
}

int main()
{
    int x2, y2;
    scanf("%d%d%d%d", &n, &m, &x2, &y2);
    bfs(x2, y2);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            printf("%-5d", dist[i][j]);
        puts("");
    }

    return 0;
}
