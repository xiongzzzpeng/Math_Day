#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

// https://leetcode.cn/problems/longest-substring-without-repeating-characters/
// 滑动窗口，在连续字符串中找左边界一般是看上一次出现的位置
// 滑动窗口，找最大字符串模板

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        int ans = 0;
        int last[256];
        fill(last, last + 256, -1);
        for (int l = 0, r = 0; r < n; r++)
        {
            // 上一次出现的位置和左边界比较
            l = max(l, last[s[r]] + 1);
            ans = max(ans, r - l + 1);
            last[s[r]] = r;
        }
        return ans;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}
