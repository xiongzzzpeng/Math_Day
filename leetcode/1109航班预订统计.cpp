#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/corporate-flight-bookings/description/
class Solution
{
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {
        // 建立差分数组，l-r范围上+n，l + n， r + 1 - n
        vector<int> cnt(n + 2);
        for (auto &book : bookings) // 遍历数组的值只能用auto&
        {
            cnt[book[0]] += book[2];
            cnt[book[1] + 1] -= book[2];
        }
        // 前缀和，自己的值加前面的一个值
        for (int i = 1; i < cnt.size(); i++)
        {
            cnt[i] += cnt[i - 1];
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = cnt[i + 1];
        }
        return ans;
    }
};