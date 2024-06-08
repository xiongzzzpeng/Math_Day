#include <bits/stdc++.h>
using namespace std;
#define ll long long

// https://leetcode.cn/problems/longest-increasing-subsequence/

class Solution
{
public:
    int mem[100010];
    int dfs(vector<int> &nums, int x)
    {
        if (mem[x])
            return mem[x];
        int res = 1;
        for (int i = 0; i < x; i++) // 结束的那个位置
        {
            if (nums[i] < nums[x])
                res = max(res, dfs(nums, i) + 1);
        }
        mem[x] = res;
        return res;
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        int dp[10010] = {0};
        for (int i = 0; i < n; i++) // 结束的位置
        {
            dp[i] = 1;
            for (int j = 0; j < i; j++) // 当前的数
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
        }
        int res = INT_MIN;
        for (int i = 0; i < n; i++)
            res = max(res, dp[i]);
        return res;
    }
};

int main()
{

    return 0;
}
