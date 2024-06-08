#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

// https://leetcode.cn/problems/minimum-size-subarray-sum/
// 简单滑动窗口模板

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int ans = INT_MAX;
        // 滑动窗口模板
        for (int l = 0, r = 0, sum = 0; r < nums.size(); r++)
        {
            sum += nums[r];
            while (sum - nums[l] >= target)
                sum -= nums[l++]; // l从窗口出去，达标就一直出去，l向左移动
            if (sum >= target)
                ans = min(ans, r - l + 1);
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}
