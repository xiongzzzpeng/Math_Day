#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

int minimumDifference(vector<int> &nums, int k)
{
    int ans = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        // 按位与的关系：只能变小或者不变
        int x = nums[i];
        ans = min(ans, abs(x - k));
        // 从后往前跟着与如果与前一个就相同了，那后面一定是不变
        for (int j = i - 1; j >= 0 && (nums[j] & x) != nums[j]; j--)
        {
            nums[j] &= x;
            ans = min(ans, abs(nums[j] - k));
        }
    }
    return ans;
}

void issue()
{
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("xzp.in", "r", stdin);
    freopen("xzp.out", "w", stdout);
#endif

    issue();
    return 0;
}
