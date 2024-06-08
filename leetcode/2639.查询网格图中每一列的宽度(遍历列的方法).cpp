#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

// https://leetcode.cn/problems/find-the-width-of-columns-of-a-grid/description/

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<int>> grid{{-15, 1, 3}, {15, 7, 12}, {5, 6, -2}};
    int n = grid[0].size();
    vector<int> ans(n);
    // 遍历列的方式
    for (int i = 0; i < n; i++)
    {
        for (auto row : grid)                                    // 假如i == 0，遍历的是第一行的第0个，第二行的第0个...
            ans[i] = max(ans[i], (int)to_string(row[i]).size()); // 求长度方法
    }
    return 0;
}
