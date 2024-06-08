#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;

// https://leetcode.cn/problems/minimum-window-substring/?utm_source=LCUS
// 滑动窗口练习，就看能不能答案与找到的有没有单调性

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.size() < t.size())
            return "";
        int cnts[256];
        for (auto c : t)
            cnts[c]--; // 该表是存放需要的
        int len = INT_MAX;
        int start = 0; // 记录开始的位置
        for (int l = 0, r = 0, debt = t.size(); r < s.size(); r++)
        {
            if (cnts[s[r]]++ < 0)
                debt--; // 找需要的字符
            // 找完后
            if (debt == 0)
            {
                while (cnts[s[l]] > 0)
                    cnts[s[l++]]--; // 看能不能缩进
                if (r - l + 1 < len)
                {
                    len = r - l + 1;
                    start = l;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}
