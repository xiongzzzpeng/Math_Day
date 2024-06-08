#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7, N = 2e5;

// https//ac.nowcoder.com/acm/contest/78807/D

char s[N];

int main()
{
    int n;
    cin >> n;
    cin >> (s + 1);
    ll ans = 0, cnt = 0; // ans是答案，cnt是当前有好多字符串，一个串肯定能与一个偶数组合成偶数
    for (int i = 1; i <= n; i++)
    {
        if (s[i] - '0' == 0)
        {
            ans = (ans + cnt + 1) % mod;
            cnt = cnt * 2 % mod; // 放头与尾不要自身
        }
        else if ((s[i] - '0') & 1)     // 奇数的时候，不结算
            cnt = (cnt * 2 + 1) % mod; // 放头与尾 + 自身
        else
        {
            ans = (ans + cnt + 1) % mod;
            cnt = (cnt * 2 + 1) % mod;
        }
    }
    cout << ans;
    return 0;
}
