#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumIndicesWithKSetBits(vector<int> &nums, int k)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int x = i, res = 0;
            while (x)
            {
                res = res + (x % 2);
                x /= 2;
            }
            if (res == k)
                ans += nums[i];
        }
        return ans;
    }
};