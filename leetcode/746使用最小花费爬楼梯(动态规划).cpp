#include <bits/stdc++.h>
using namespace std;
#define ll long long

// 动态规划步骤：描述问题   找到最后一步    去掉最后一步问题变成什么
// https://leetcode.cn/problems/min-cost-climbing-stairs/description/

class Solution
{
public:
    int mem[10010];
    int dfs(vector<int> &cost, int x) // x = cost.size()
    {
        if (mem[x])
            return mem[x];
        int sum = 0;
        if (x == 0 || x == 1)
            return 0;
        else
        {
            sum = min(dfs(cost, x - 1) + cost[x - 1], dfs(cost, x - 2) + cost[x - 2]);
        }
        mem[x] = sum;
        return sum;
    }
    // 从上面推下来的
    int minCostClimbingStairs(vector<int> &cost)
    {
        int dp[10010] = {0};
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= cost.size(); i++)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[cost.size()];
    }
};

int main()
{

    return 0;
}
