#include <bits/stdc++.h>
using namespace std;
#define ll long long

// https://leetcode.cn/problems/minimum-cost-for-tickets/description/
// 记忆化模板
int durations[3] = {1, 7, 30};
class Solution
{
public:
    int mem[366] = {0};
    int dfs(vector<int> &days, vector<int> &costs, int i)
    {
        if (mem[i])
            return mem[i];
        if (i == days.size())
            return 0;
        int ans = INT_MAX;
        for (int k = 0, j = i; k < 3; k++)
        {
            // 好多天过期，不大于的时候就是过期，从这里开始
            while (j < days.size() && days[i] + durations[k] > days[j])
                j++;
            ans = min(ans, costs[k] + dfs(days, costs, j));
        }
        mem[i] = ans;
        return ans;
    }
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        return dfs(days, costs, 0);
    }
};

// dp模板
class Solution
{
public:
    int durations[3] = {1, 7, 30};
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int dp[366];
        int n = days.size();
        fill(dp, dp + n + 1, INT_MAX);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) // 用越界的倒推整个
        {
            for (int k = 0, j = i; k < 3; k++)
            {
                while (j < days.size() && days[i] + durations[k] > days[j])
                    j++;
                dp[i] = min(dp[i], costs[k] + dp[j]);
            }
        }
        return dp[0];
    }
};
