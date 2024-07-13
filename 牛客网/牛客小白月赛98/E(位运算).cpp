#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

// https://ac.nowcoder.com/acm/contest/85598/E
// 位运算的题就看每个数位的变化,位运算好题
void issue()
{
    ll n, k1, k2;
    cin >> n >> k1 >> k2;
    vector<ll> a(n + 1), l(500010), mxl(500010);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    if (k1 >= 61)
    {
        cout << "0" << endl;
        return;
    }

    k2 = min(k2, 62ll);
    l[0] = -1;
    ll ans = 0;

    for (int bit = 60; bit >= 0; bit--)
    {
        for (int i = 1; i <= n; i++)
        {
            // 比较数位的方法
            if (i == 1 || ((a[i] & (1ll << bit)) == (a[i - 1] & (1ll << bit))))
                l[i] = l[i - 1];
            else
                l[i] = i - 1;
            if (k1 <= bit && bit < k2)
                ans = ans + max(0ll, l[i] - mxl[i]);
            mxl[i] = max(mxl[i], l[i]);
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

    int T = 1;
    // cin >> T;
    while (T--)
    {
        issue();
    }
    return 0;
}
