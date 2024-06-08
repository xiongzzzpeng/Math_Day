#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/sort-array-by-parity-ii/
class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &nums)
    {
        for (int even = 0, odd = 1; even < nums.size() && odd < nums.size();)
        {
            if ((nums[nums.size() - 1] & 1) == 1)
            {
                swap(nums[nums.size() - 1], nums[odd]);
                odd += 2;
            }
            else
            {
                swap(nums[nums.size() - 1], nums[even]);
                even += 2;
            }
        }
        return nums;
    }
};