#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 510;
typedef pair<int, int> PII;

// ��ʼ֮ǰ�Ͱ����������ӣ���������ͬʱ����
int n, m, a, b;
PII q[N * N];
int dist[N][N];
int hh = 0, tt = -1; // ��ǰ���һ���㣬����tt��-1
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs()
{
    while (hh <= tt)
    {
        auto t = q[hh++];
        for (int i = 0; i < 4; i++)
        {
            int a = t.first + dx[i], b = t.second + dy[i];
            if (a < 1 || a > n || b < 1 || b > m)
                continue;
            if (dist[a][b] >= 0)
                continue;
            dist[a][b] = dist[t.first][t.second] + 1;
            q[++tt] = {a, b};
        }
    }
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &a, &b);
    memset(dist, -1, sizeof dist);
    while (a--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        q[++tt] = {x, y};
        dist[x][y] = 0;
    }
    bfs();

    // ֱ������������λ�ã����
    while (b--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", dist[x][y]);
    }
    return 0;
}
