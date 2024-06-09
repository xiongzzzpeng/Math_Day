#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;
const ll mod = 998244353;

// ������(a��b����)
ll qpow(ll a, ll b)
{
    ll ans = 1;
    while (b > 0)
    {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

void issue()
{
    ll n;
    cin >> n;

    // b��λ����a������
    ll a = n % mod, b = 1, x = n;
    while (x)
    {
        b *= 10;
        x /= 10;
    }

    // qpow((b - 1) % mod, mod - 2)��Ԫ�������ȱ����еķ�ĸ����(1 - q)
    ll ans = a * (qpow(b % mod, n) - 1) % mod * qpow((b - 1) % mod, mod - 2) % mod;
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

    int T = 1;
    // cin >> T;
    while (T--)
    {
        issue();
    }
    return 0;
}
