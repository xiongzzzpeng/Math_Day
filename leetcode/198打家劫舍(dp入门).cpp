#include <bits/stdc++.h>
using namespace std;
#define ll long long

// dp»Î√≈ https://leetcode.cn/problems/house-robber/description/
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n + 2, 0);
        for (int i = n - 1; i >= 0; i--)
            ans[i] = max(ans[i + 1], ans[i + 2] + nums[i]);
        return ans[0];
    }
};

int main()
{

    return 0;
}
