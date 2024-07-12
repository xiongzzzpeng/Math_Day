#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

// 01_bfs:用于图的边全是0或1,要找最短距离

int bfs_01(vector<vector<int>> &grid)
{
    int move[] = {-1, 0, 1, 0, -1};
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> distance(n, vector<int>(m, INT_MAX));

    // 双端队列用于01_bfs
    deque<PII> dq;
    dq.push_front({0, 0});
    distance[0][0] = 0;

    while (!dq.empty())
    {
        auto [x, y] = dq.front();
        dq.pop_front();

        // 到达终点就返回
        if (x == n - 1 && y == m - 1)
            return distance[x][y];

        for (int i = 0; i < 4; i++)
        {
            int nx = x + move[i], ny = y + move[i + 1];

            // 看新坐标的举例是否需要更新，比他小就更新
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && distance[x][y] + grid[nx][ny] < distance[nx][ny])
            {
                distance[nx][ny] = distance[x][y] + grid[nx][ny];

                // 判断是0还是1， 0队首
                if (grid[nx][ny] == 0)
                    dq.push_front({nx, ny});
                else
                    dq.push_back({nx, ny});
            }
        }
    }
    return -1;
}

void issue()
{
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
    cin >> T;
    while (T--)
    {
        issue();
    }
    return 0;
}
