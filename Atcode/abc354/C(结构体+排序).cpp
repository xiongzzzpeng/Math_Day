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
    // �ṹ�尴��a����������Ĭ�ϵľ��ǰ���a�Ĵ�С�ţ�aһ����c
    sort(a.begin() + 1, a.end(), [&](card x, card y)
         { return x.a > y.a; });
    vector<ll> vis(n + 1);
    ll mn = INT_MAX;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        // ��֪��ǰ��a��ǰ�Ŀ���ҪС
        // ���Ե�ǰ��c��ǰ����С��c��Ҫ��Ļ���ɾ��
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
