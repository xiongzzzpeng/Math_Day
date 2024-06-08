#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
typedef pair<int, int> PII;

class Solution
{
public:
    long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        unordered_map<int, int> cnt;
        for (auto x : nums1)
        {
            if (x % k != 0)
                continue;
            x /= k;
            // 找出相关因子模板
            for (int d = 1; d * d <= x; d++)
            {
                if (x % d != 0)
                    continue;
                cnt[d]++;

                if (d * d < x)
                    cnt[x / d]++;
            }
        }
        long long ans = 0;
        // 在c++17后可以这样写
        // for(auto num : nums2)
        // ans += cnt.contains(num) ? cnt[num] : 0;
        for (auto num : nums2)
        {
            auto it = cnt.find(num);
            if (it != cnt.end())
                ans += it->second;
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
