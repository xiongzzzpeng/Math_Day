#include <bits/stdc++.h>
using namespace std;
#define ll long long

// https://leetcode.cn/problems/heaters/
// 双指针解法，看见好像还有二分的解法，没有双指针直观
class Solution
{
public:
    bool best(vector<int> &houses, vector<int> &heaters, int i, int j)
    {
        return j == heaters.size() - 1 || abs(heaters[j] - houses[i]) < abs(heaters[j + 1] - houses[i]);
    }
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int res = 0;
        for (int i = 0, j = 0; i < houses.size(); i++)
        {
            // i控制的是房间，j是供暖器
            while (!best(houses, heaters, i, j))
            {
                j++;
            }
            res = max(res, abs(heaters[j] - houses[i]));
        }
        return res;
    }
};