#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int alternatingSubarray(vector<int> &nums)
    {
        int m = nums.size();
        int ans = -1;
        for (int i = 0; i < m; i++)
        {
            int j = i;
            int k = 1;
            for (; j + 1 < m && nums[j + 1] - nums[j] == k; j++)
            {
                k = k * -1;
            }
            if (j - i + 1 > 1)
                ans = max(ans, j - i + 1);
        }
        return ans;
    }
};