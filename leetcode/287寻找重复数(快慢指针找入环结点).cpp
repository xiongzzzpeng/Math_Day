#include <bits/stdc++.h>
using namespace std;
#define ll long long

// 快慢指针找入环结点
// slow跳一步，fast跳两步，相遇fast到开头
// slow一步，fast一步相遇就是答案

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0];       // 慢指针移动一步
        int fast = nums[nums[0]]; // 快指针移动两步
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        // 第二部分
        fast = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};