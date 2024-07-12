#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

// https://leetcode.cn/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/
// 01_bfs练习，关键就是找路径

class Solution
{
public:
    int minCost(vector<vector<int>> &grid)
    {
        vector<vector<int>> move = {{}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));

        deque<pair<int, int>> dq;
        dq.push_front({0, 0});
        distance[0][0] = 0;

        while (!dq.empty())
        {
            auto [x, y] = dq.front();
            dq.pop_front();

            if (x == n - 1 && y == m - 1)
                return distance[x][y];

            for (int i = 1; i <= 4; i++)
            {
                int nx = x + move[i][0], ny = y + move[i][1];
                int w = grid[x][y] != i ? 1 : 0;

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && distance[x][y] + w < distance[nx][ny])
                {
                    distance[nx][ny] = distance[x][y] + w;

                    if (w == 0)
                        dq.push_front({nx, ny});
                    else
                        dq.push_back({nx, ny});
                }
            }
        }
        return -1;
    }
};

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
    // cin >> T;
    while (T--)
    {
        issue();
    }
    return 0;
}
