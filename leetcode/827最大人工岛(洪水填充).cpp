#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

// ��ˮ���(��Ⱦ)
void dfs_flood(vector<vector<int>> &grid, int i, int j, int n, int m, int id)
{
    // i, j�ǵ�ǰ����  n, m���з�Χ �з�Χ
    if (i < 0 || i == n || j < 0 || j == m || grid[i][j] != 1)
        return;

    grid[i][j] = id; // F, O���ж�����
    dfs_flood(grid, i - 1, j, n, m, id);
    dfs_flood(grid, i + 1, j, n, m, id);
    dfs_flood(grid, i, j - 1, n, m, id);
    dfs_flood(grid, i, j + 1, n, m, id);
}

class Solution
{
public:
    void dfs_flood(vector<vector<int>> &grid, int i, int j, int n, int m, int id)
    {
        // i, j�ǵ�ǰ����  n, m���з�Χ �з�Χ
        if (i < 0 || i == n || j < 0 || j == m || grid[i][j] != 1)
            return;

        grid[i][j] = id; // F, O���ж�����
        dfs_flood(grid, i - 1, j, n, m, id);
        dfs_flood(grid, i + 1, j, n, m, id);
        dfs_flood(grid, i, j - 1, n, m, id);
        dfs_flood(grid, i, j + 1, n, m, id);
    }

    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int id = 2;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    dfs_flood(grid, i, j, n, m, id++);
            }
        }

        vector<int> sizes(id + 1, 0);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] > 1)
                    ans = max(ans, ++sizes[grid[i][j]]); // ͳ��ÿ��������Ŀ
            }
        }

        // �������е�0���1���������
        vector<bool> mark(id + 1); // ȥ��
        int up, down, left, right, merge;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    up = i > 0 ? grid[i - 1][j] : 0;
                    down = i + 1 < n ? grid[i + 1][j] : 0;
                    left = j > 0 ? grid[i][j - 1] : 0;
                    right = j + 1 < m ? grid[i][j + 1] : 0;
                    mark[up] = true;
                    merge = 1 + sizes[up];

                    if (!mark[down])
                    {
                        merge += sizes[down];
                        mark[down] = true;
                    }

                    if (!mark[left])
                    {
                        merge += sizes[left];
                        mark[left] = true;
                    }

                    if (!mark[right])
                    {
                        merge += sizes[right];
                        mark[right] = true;
                    }

                    ans = max(ans, merge);
                    mark[up] = false;
                    mark[down] = false;
                    mark[left] = false;
                    mark[right] = false;
                }
            }
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
