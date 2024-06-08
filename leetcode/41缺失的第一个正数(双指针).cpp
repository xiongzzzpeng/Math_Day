#include <bits/stdc++.h>
using namespace std;
#define ll long long

// https://leetcode.cn/problems/first-missing-positive/
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int l = 0, r = nums.size();
        // l左边都是左到i+1的区域，永远盯着l位置的数看，看能不能l++
        // 从r一直往右就一直是垃圾区，最好的期望就是1-r是可以收集全的，每个数字收集一个
        // 如果有垃圾，预期变差r--
        while (l < r)
        {
            if (nums[l] == l + 1)
                l++;
            else if (nums[l] <= l || nums[l] > r || nums[nums[l] - 1] == nums[l]) // 几种垃圾情况
                                                                                  // 第三种是下标是6的值跟7的位置的值一样，那么就是垃圾，因为有重复的
                swap(nums[l], nums[--r]);
            else
                swap(nums[l], nums[nums[l] - 1]);
        }
        return l + 1;
    }
};