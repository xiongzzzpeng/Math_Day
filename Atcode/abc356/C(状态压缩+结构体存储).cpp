#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

void issue()
{
    ll n, m, k;
    cin >> n >> m >> k;

    struct test
    {
        vector<ll> id;
        ll tag;
    };
    vector<test> a(m + 1);

    for (int i = 1; i <= m; i++)
    {
        ll c;
        cin >> c;
        for (int j = 1; j <= c; j++)
        {
            ll x;
            cin >> x;
            a[i].id.push_back(x - 1);
        }
        char tag;
        cin >> tag;
        if (tag == 'o')
            a[i].tag = 1;
        else
            a[i].tag = 0;
    }

    ll ans = 0;

    // 枚举钥匙的二进制状态,状态压缩
    // 1选，0不选
    for (ll s = 0; s < (1 << n); s++)
    {
        ll flag = 1; // 记录当前二进制状态是否满足条件

        for (ll i = 1; i <= m; i++)
        {
            // cnt是记录当前事件下有用的key个数
            ll cnt = 0;

            // 枚举第i个事件所需的钥匙编号
            for (ll x : a[i].id)
            {
                // 当前二进制存在钥匙编号
                if ((s >> x) & 1)
                    cnt++;
            }

            if ((cnt >= k) != a[i].tag) // 非0是真，0是假
                flag = 0;
        }
        if (flag)
            ans++;
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
