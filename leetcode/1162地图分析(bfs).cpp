#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

// https : // leetcode.cn/problems/as-far-from-land-as-possible/description/

class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> flag(n, vector<int>(m, 0));
        int ans = 0, seas = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    flag[i][j] = 1;
                    q.push({i, j});
                }
                else
                    seas++;
            }
        }

        if (seas == 0 || seas == m * n)
            return -1;
        int move[] = {-1, 0, 1, 0, -1}; // 查找四边的方法

        while (!q.empty())
        {
            ans++;
            int size = q.size();
            for (int k = 0; k < size; k++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int nx = x + move[i];
                    int ny = y + move[i + 1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && !flag[nx][ny])
                    {
                        flag[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return ans - 1;
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
