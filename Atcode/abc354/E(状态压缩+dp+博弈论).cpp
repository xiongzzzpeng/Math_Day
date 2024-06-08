#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

// ��һ�����ذ�̬����ǰ���Ǳ�ʤ̬
// ����һ�����ذ�̬���Ǳذ�̬
void issue()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    // ״̬ѹ����0��ɾ1�ǲ�ɾ
    // �ö����Ʊ�ʾ״̬����0100���ǳ��˵�1�Ŷ�ɾ��
    // Ĭ�϶��Ǳذ�̬
    vector<ll> dp(1 << n);
    for (ll s = 0; s < (1 << n); s++)
    {
        // ö��״̬s����״̬����sѡ����ɾ��
        // iɾһ�ţ�jɾһ��
        for (ll i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                if (a[i] != a[j] && b[i] != b[j])
                    continue;
                if (((s >> i) & 1) && ((s >> j) & 1))
                    // ��λ������ʾ����һ��״̬һ���Ǳذܣ���ǰ�϶���ʤ
                    dp[s] |= (!dp[s - (1 << i) - (1 << j)]);
            }
        }
    }
    if (dp[(1 << n) - 1])
        cout << "Takahashi" << endl;
    else
        cout << "Aoki" << endl;
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
