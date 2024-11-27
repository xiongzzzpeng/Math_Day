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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        for (ll i = 0; i < n; i++)
            cin >> b[i];
        ll m;
        cin >> m;
        vector<ll> d(m);
        for (ll i = 0; i < m; i++)
            cin >> d[i];
        ll flag = 1;

        // 如果最后一个不合法就一定不存在
        if (find(b.begin(), b.end(), d.back()) == b.end())
        {
            flag = 0;
        }
        multiset<ll> s(d.begin(), d.end());
        for (ll i = 0; i < n; i++)
        {
            if (b[i] != a[i])
            {
                if (s.find(b[i]) == s.end())
                    flag = 0;
                s.extract(b[i]);
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
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
