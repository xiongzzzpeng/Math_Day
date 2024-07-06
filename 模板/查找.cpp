#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;
const int N = 10;

int path[N], n, st[N];

// dfs:排序,带环要注意判断
void dfs(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; i++)
            cout << path[i];
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (st[i] == 0)
        {
            st[i] = 1;
            path[u] = i;
            dfs(u + 1);
            st[i] = 0;
        }
    }
}

// 洪水填充(感染) 岛屿问题
void dfs_flood(vector<vector<char>> &grid, int i, int j, int n, int m)
{
    // i, j是当前坐标  n, m是行范围 列范围
    if (i < 0 || i == n || j < 0 || j == m || grid[i][j] != 'O')
        return;

    grid[i][j] = 'F'; // F, O是判断条件
    dfs_flood(grid, i - 1, j, n, m);
    dfs_flood(grid, i + 1, j, n, m);
    dfs_flood(grid, i, j - 1, n, m);
    dfs_flood(grid, i, j + 1, n, m);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("xzp.in", "r", stdin);
    freopen("xzp.out", "w", stdout);
    cin >> n;
    dfs(0);
    return 0;
}
