#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

// https://leetcode.cn/problems/longest-subsequence-with-limited-sum/description/

class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        vector<int> sum(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++)
            sum[i + 1] = sum[i] + nums[i];
        for (auto a : queries)
        {
            // leetcodeÖÐupper_boundÓÃ·¨
            int temp = upper_bound(sum.begin(), sum.end(), a) - sum.begin();
            ans.push_back(temp - 1);
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

    return 0;
}
