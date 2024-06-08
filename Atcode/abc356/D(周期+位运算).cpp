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
        // ��m�Ķ�����λ��1��ʱ��ŶԴ��й���
        if ((m >> i) & 1)
        {
            // ���ڳ�����2^(i + 1)���������ڵĸ���
            ll cnt = n / (1ll << (i + 1));

            // ��һ���������棬1�ĸ���ռһ��
            // ������2^(i + 1)��1�ĸ�������2^i
            ans += cnt * (1ll << i) % mod;

            // ���㲻����������
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
