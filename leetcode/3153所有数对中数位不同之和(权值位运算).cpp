#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

// https://leetcode.cn/problems/sum-of-digit-differences-of-all-pairs/description/
// 转换为有每个位上有多少不一样的数对
// 如各位是3 3 2就有两对
class Solution
{
public:
    long long sumDigitDifferences(vector<int> &nums)
    {
        long long ans = 0;
        vector<array<int, 10>> cnt(to_string(nums[0]).size()); // 语法
        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            for (int j = 0; x; x /= 10, j++)
            {
                int d = x % 10;
                // 当前i - cnt[i]就是存在有多少不一样的
                ans += i - cnt[j][d]++; // j是个位还是十位...d是值
            }
        }
        return ans;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("xzp.in", "r", stdin);
    freopen("xzp.out", "w", stdout);
    vector<int> nums = {13, 23, 12}; // 示例数字数组，可以根据需要修改
    Solution solution;
    long long result = solution.sumDigitDifferences(nums);
    cout << result << endl;
    return 0;
}
