#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/maximum-difference-score-in-a-grid/description/
// ÄÔ½î¼±×ªÍä

class Solution
{
public:
    int maxScore(vector<vector<int>> &grid)
    {
        int ans = INT_MIN;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1, INT_MAX));
        // Enumerate (i,j) as the end point
        // f[i][j] is the minimum starting point
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                int mn = min(f[i + 1][j], f[i][j + 1]);
                ans = max(ans, grid[i][j] - mn);
                f[i + 1][j + 1] = min(mn, grid[i][j]);
            }
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> grid = {
        {9, 5, 7, 3},
        {8, 9, 6, 1},
        {6, 7, 14, 3},
        {2, 5, 3, 1}};
    int maxScore = solution.maxScore(grid);
    cout << "Maximum score: " << maxScore << endl;
    return 0;
}
