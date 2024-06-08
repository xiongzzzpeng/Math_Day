#include <bits/stdc++.h>
using namespace std;
#define ll long long

// https://leetcode.cn/problems/heaters/
// ˫ָ��ⷨ�����������ж��ֵĽⷨ��û��˫ָ��ֱ��
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
            // i���Ƶ��Ƿ��䣬j�ǹ�ů��
            while (!best(houses, heaters, i, j))
            {
                j++;
            }
            res = max(res, abs(heaters[j] - houses[i]));
        }
        return res;
    }
};