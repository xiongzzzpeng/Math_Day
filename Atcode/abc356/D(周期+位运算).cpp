#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;
const ll mod = 998244353;

void issue()
{
    ll n, m;
    cin >> n >> m;
    n++;
    ll ans = 0;
    for (ll i = 0; i < 60; i++)
    {
        // 当m的二进制位是1的时候才对答案有贡献
        if ((m >> i) & 1)
        {
            // 周期长度是2^(i + 1)，计算周期的个数
            ll cnt = n / (1ll << (i + 1));

            // 在一个周期里面，1的个数占一半
            // 长度是2^(i + 1)，1的个数就是2^i
            ans += cnt * (1ll << i) % mod;

            // 计算不完整的周期
            ans += max(0ll, n % (1ll << (i + 1)) - (1ll << i)) % mod;
            ans %= mod;
        }
    }
    cout << ans << endl;
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
