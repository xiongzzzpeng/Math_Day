#include <bits/stdc++.h>
using namespace std;

// 不会tle但还没学会
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;
        vector<int> dp(amount + 1, 999999999);
        dp[0] = 0;
        for (auto coin : coins)
        {
            if (coin <= amount)
            {
                dp[coin] = 1;
            }
        }
        int n = coins.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        return dp[amount] == 999999999 ? -1 : dp[amount];
    }
};

// 会tle
class Solution
{
public:
    void dfs(vector<int> &coins, int amount, int c_index, int count, int &ans)
    {
        if (amount == 0)
        {
            ans = min(ans, count);
            return;
        }
        if (c_index == coins.size()) // 找完没有合适的就剪支
            return;
        // k是硬币数目，c_index是位置，count是总数
        for (int k = amount / coins[c_index]; k >= 0 && k + count < ans; k--)
        {
            dfs(coins, amount - k * coins[c_index], c_index + 1, count + k, ans);
        }
    }

    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;
        sort(coins.rbegin(), coins.rend()); // 倒序
        int ans = INT_MAX;
        dfs(coins, amount, 0, 0, ans);
        return ans == INT_MAX ? -1 : ans;
    }
};