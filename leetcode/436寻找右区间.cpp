#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        vector<pair<int, int>> startInt;
        for (int i = 0; i < intervals.size(); i++)
        {
            startInt.emplace_back(intervals[i][0], i);
        }
        sort(startInt.begin(), startInt.end());
        vector<int> ans(intervals.size(), -1);
        for (int i = 0; i < intervals.size(); i++)
        {
            auto it = lower_bound(startInt.begin(), startInt.end(), make_pair(intervals[i][1], 0));
            if (it != startInt.end())
                ans[i] = it->second;
        }
        return ans;
    }
};