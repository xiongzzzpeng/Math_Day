#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/reverse-pairs/
class Solution
{
public:
    int help[500010];
    int reversePairs(vector<int> &nums)
    {
        return const1(nums, 0, nums.size() - 1);
    }
    int const1(vector<int> &nums, int l, int r)
    {
        if (l == r)
            return 0;
        int mid = l + ((r - l) >> 1);
        return const1(nums, l, mid) + const1(nums, mid + 1, r) + merge(nums, l, mid, r);
    }
    int merge(vector<int> &nums, int l, int mid, int r)
    {
        int ans = 0;
        for (int i = l, j = mid + 1; i <= mid; i++)
        {
            while (j <= r && (long)nums[i] > 2 * (long)nums[j])
            {
                j++;
            }
            ans += j - mid - 1; // 将i的位置记录到ans里
        }
        int i = l, a = l, b = mid + 1;
        while (a <= mid && b <= r)
        {
            help[i++] = nums[a] <= nums[b] ? nums[a++] : nums[b++];
        }
        while (a <= mid)
            help[i++] = nums[a++];
        while (b <= r)
            help[i++] = nums[b++];
        for (i = l; i <= r; i++)
            nums[i] = help[i];
        return ans;
    }
};