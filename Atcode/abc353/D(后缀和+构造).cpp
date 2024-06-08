#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;
const ll mod = 998244353;

// 算多少位
ll get_len(ll x)
{
    ll ans = 1;
    while (x)
        x = x / 10, ans *= 10;
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("xzp.in", "r", stdin);
    freopen("xzp.out", "w", stdout);
    ll n;
    cin >> n;
    vector<ll> num(n + 1, 0);
    vector<ll> suffix(n + 2, 0);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    // 后缀和
    for (int i = n; i >= 1; i--)
        suffix[i] = (suffix[i + 1] + get_len(num[i])) % mod;
    for (int i = 1; i <= n; i++)
    {
        ans += (i - 1) * num[i] % mod;
        ans %= mod;
        ans += num[i] * suffix[i + 1] % mod;
        ans %= mod;
    }
    cout << ans;
    return 0;
}
