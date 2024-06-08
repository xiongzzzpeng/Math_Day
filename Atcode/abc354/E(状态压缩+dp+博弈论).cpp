#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

// 能一步到必败态，当前就是必胜态
// 不能一步到必败态就是必败态
void issue()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    // 状态压缩：0是删1是不删
    // 用二进制表示状态，如0100就是除了第1张都删了
    // 默认都是必败态
    vector<ll> dp(1 << n);
    for (ll s = 0; s < (1 << n); s++)
    {
        // 枚举状态s，子状态就是s选两张删掉
        // i删一张，j删一张
        for (ll i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                if (a[i] != a[j] && b[i] != b[j])
                    continue;
                if (((s >> i) & 1) && ((s >> j) & 1))
                    // 按位或来表示，下一个状态一定是必败，当前肯定必胜
                    dp[s] |= (!dp[s - (1 << i) - (1 << j)]);
            }
        }
    }
    if (dp[(1 << n) - 1])
        cout << "Takahashi" << endl;
    else
        cout << "Aoki" << endl;
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
