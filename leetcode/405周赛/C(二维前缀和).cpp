#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

class Solution
{
public:
    int numberOfSubmatrices(vector<vector<char>> &grid)
    {
        int ans = 0, m = grid.size(), n = grid[0].size();
        vector<vector<array<int, 2>>> sum(m + 1, vector<array<int, 2>>(n + 1));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sum[i + 1][j + 1][0] =
                    sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0];
                sum[i + 1][j + 1][1] =
                    sum[i + 1][j][1] + sum[i][j + 1][1] - sum[i][j][1];
                if (grid[i][j] != '.')
                {
                    sum[i + 1][j + 1][grid[i][j] & 1]++;
                }
                if (sum[i + 1][j + 1][0] &&
                    sum[i + 1][j + 1][0] == sum[i + 1][j + 1][1])
                {
                    ans++;
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
    cin >> T;
    while (T--)
    {
        issue();
    }
    return 0;
}
