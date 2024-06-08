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
    ll n;
    cin >> n;
    struct card
    {
        ll a, c, id;
    };
    vector<card> a(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i].a >> a[i].c;
        a[i].id = i;
    }
    // 结构体按照a的升序排序，默认的就是按照a的大小排，a一样看c
    sort(a.begin() + 1, a.end(), [&](card x, card y)
         { return x.a > y.a; });
    vector<ll> vis(n + 1);
    ll mn = INT_MAX;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        // 已知当前的a比前的卡都要小
        // 所以当前的c比前面最小的c都要大的话就删除
        if (a[i].c <= mn)
        {
            ans++;
            vis[a[i].id] = 1;
        }
        mn = min(mn, a[i].c);
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
        if (vis[i])
            cout << i << " ";
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
