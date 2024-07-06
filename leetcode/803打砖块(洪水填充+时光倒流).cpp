#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

// 洪水填充(感染)
int dfs_flood(vector<vector<int>> &grid, int i, int j, int n, int m)
{
    // i, j是当前坐标  n, m是行范围 列范围
    if (i < 0 || i == n || j < 0 || j == m || grid[i][j] != 1)
        return 0;

    grid[i][j] = 2; // F, O是判断条件
    return 1 + dfs_flood(grid, i + 1, j, n, m) + dfs_flood(grid, i - 1, j, n, m) + dfs_flood(grid, i, j + 1, n, m) + dfs_flood(grid, i, j - 1, n, m);
}

bool worth(vector<vector<int>> &grid, int i, int j, int n, int m)
{
    return grid[i][j] == 1 &&
           (i == 0 || (i > 0 && grid[i - 1][j] == 2) || (i < n - 1 && grid[i + 1][j] == 2) || (j > 0 && grid[i][j - 1] == 2) || (j < m - 1 && grid[i][j + 1] == 2));
}

class Solution
{
public:
    // 洪水填充(感染)
    int dfs_flood(vector<vector<int>> &grid, int i, int j, int n, int m)
    {
        // i, j是当前坐标  n, m是行范围 列范围
        if (i < 0 || i == n || j < 0 || j == m || grid[i][j] != 1)
            return 0;

        grid[i][j] = 2; // F, O是判断条件
        return 1 + dfs_flood(grid, i + 1, j, n, m) + dfs_flood(grid, i - 1, j, n, m) + dfs_flood(grid, i, j + 1, n, m) + dfs_flood(grid, i, j - 1, n, m);
    }

    bool worth(vector<vector<int>> &grid, int i, int j, int n, int m)
    {
        return grid[i][j] == 1 &&
               (i == 0 || (i > 0 && grid[i - 1][j] == 2) || (i < n - 1 && grid[i + 1][j] == 2) || (j > 0 && grid[i][j - 1] == 2) || (j < m - 1 && grid[i][j + 1] == 2));
    }

    vector<int> hitBricks(vector<vector<int>> &g, vector<vector<int>> &h)
    {
        int n = g.size();
        int m = g[0].size();
        vector<int> ans(h.size());

        if (n == 1)
            return ans;
        for (auto c : h)
        {
            g[c[0]][c[1]]--;
        }
        for (int i = 0; i < m; i++)
            dfs_flood(g, 0, i, n, m);
        // 时光倒流，就是再倒着处理
        for (int i = h.size() - 1; i >= 0; i--)
        {
            int row = h[i][0];
            int col = h[i][1];
            g[row][col]++;
            if (worth(g, row, col, n, m))
                ans[i] = dfs_flood(g, row, col, n, m) - 1;
        }
        return ans;
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
