#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

// https://leetcode.cn/problems/path-with-minimum-effort/description/
// dijkstar¡∑œ∞

class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &h)
    {
        int move[] = {-1, 0, 1, 0, -1};
        int n = h.size(), m = h[0].size();

        vector<vector<int>> distance(n, vector<int>(m, INT32_MAX));
        distance[0][0] = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        auto cmp = [](vector<int> &a, vector<int> &b)
        {
            return a[2] > b[2];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> heap(cmp);
        heap.push({0, 0, 0});

        while (!heap.empty())
        {
            auto u = heap.top();
            heap.pop();

            int x = u[0];
            int y = u[1];
            int z = u[2];

            if (visited[x][y])
                continue;

            if (x == n - 1 && y == m - 1)
                return z;
            visited[x][y] = true;

            for (int i = 0; i < 4; i++)
            {
                int nx = x + move[i], ny = y + move[i + 1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny])
                {
                    int nc = max(z, abs(h[nx][ny] - h[x][y]));
                    if (nc < distance[nx][ny])
                    {
                        distance[nx][ny] = nc;
                        heap.push({nx, ny, nc});
                    }
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
    cin >> T;
    while (T--)
    {
        issue();
    }
    return 0;
}
