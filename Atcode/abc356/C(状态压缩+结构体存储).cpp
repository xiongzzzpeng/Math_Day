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

    // ö��Կ�׵Ķ�����״̬,״̬ѹ��
    // 1ѡ��0��ѡ
    for (ll s = 0; s < (1 << n); s++)
    {
        ll flag = 1; // ��¼��ǰ������״̬�Ƿ���������

        for (ll i = 1; i <= m; i++)
        {
            // cnt�Ǽ�¼��ǰ�¼������õ�key����
            ll cnt = 0;

            // ö�ٵ�i���¼������Կ�ױ��
            for (ll x : a[i].id)
            {
                // ��ǰ�����ƴ���Կ�ױ��
                if ((s >> x) & 1)
                    cnt++;
            }

            if ((cnt >= k) != a[i].tag) // ��0���棬0�Ǽ�
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
