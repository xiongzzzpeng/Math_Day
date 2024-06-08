#include <bits/stdc++.h>
using namespace std;
#define ll long long

// https://leetcode.cn/problems/trapping-rain-water/
//  看整体，有人给兜底
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> lmax(n, 0);
        vector<int> rmax(n, 0);
        lmax[0] = height[0];
        rmax[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++)
            lmax[i] = max(lmax[i - 1], height[i]); // 求0—i的左最大值
        for (int i = n - 2; i >= 0; i--)
            rmax[i] = max(rmax[i + 1], height[i]); // 求n-0右的最大值
        int ans = 0;
        for (int i = 1; i < n - 1; i++)
            ans += max(min(lmax[i - 1], rmax[i + 1]) - height[i], 0);
        return ans;
    }
};

// 双指针解法
class Solution
{
public:
    int trap(vector<int> &nums)
    {
        int n = nums.size();
        int l = 1, r = n - 2, lmax = nums[0], rmax = nums[n - 1];
        int ans = 0;
        while (l <= r)
        {
            if (lmax <= rmax)
            {
                ans += max(0, lmax - nums[l]);
                lmax = max(lmax, nums[l++]);
            }
            else
            {
                ans += max(0, rmax - nums[r]);
                rmax = max(rmax, nums[r--]);
            }
        }
        return ans;
    }
};
