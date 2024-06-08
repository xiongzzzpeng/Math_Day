#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

class Solution
{
public:
    string clearStars(string s)
    {
        stack<int> stk[26]; // 二维的栈
        vector<int> del(s.size());
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '*')
            {
                stk[s[i] - 'a'].push(i); // 将坐标入栈
                continue;
            }
            for (auto &p : stk) // 必须加引用,才能修改stk
            {
                if (!p.empty())
                {
                    del[p.top()] = true; // 记录不要的
                    p.pop();             // 就弹出最小的最后一个
                    break;
                }
            }
        }
        string ans;
        for (int i = 0; i < s.size(); i++)
            if (!del[i] && s[i] != '*')
                ans += s[i];
        return ans;
    }
};

void issue()
{
    Solution sol;
    string ans = sol.clearStars("aaba*");

    cout << ans << endl; // Output: "aab"
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
