#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

// ���Լ��
int gcd(int a, int b)
{
    return __gcd(a, b);
}

// ɾ��һ�������Ϳ�ɾ������û����
void issue()
{
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<ll> b(n + 1);
    for (int i = 1; i < n; i++)
        b[i] = gcd(a[i], a[i + 1]);

    // pre�������ҿ���û����suf����������û����
    vector<ll> pre(n + 1), suf(n + 1);
    pre[1] = suf[n - 1] = 1;
    for (int i = 2; i < n; i++)
        pre[i] = pre[i - 1] & (b[i] >= b[i - 1]);
    for (int i = n - 2; i >= 1; i--)
        suf[i] = suf[i + 1] & (b[i] <= b[i + 1]);

    int ans = 0;
    for (int i = 3; i <= n - 2; i++)
    {
        // ��ɾ���ĸ�λ�ã��ӵ�����������������
        // ɾ��һ��aҪ��ԭ����2��b����һ���µ�b
        // ǰ����ɾ���п��ܱ�ɵ�һ��������ͬ��
        // ����ɾ��3��a��b2��b3��Ҫ��ɾ����ֱ����b1��b4�Ƚ�
        if (pre[i - 2] && suf[i + 1] && gcd(a[i - 1], a[i + 1]) >= b[i - 2] && gcd(a[i - 1], a[i + 1]) <= b[i + 1])
        {
            ans = 1;
            break;
        }
    }

    // ɾ��ǰ�����������ɵ�һ����ʱ�򣬺����Ǳ�����һ����ʱ��
    if (suf[2] || suf[3] && gcd(a[1], a[3]) <= b[3] || pre[n - 2] || pre[n - 3] && gcd(a[n], a[n - 2]) >= b[n - 3] || ans)
        cout << "YES\n";
    else
        cout << "NO\n";
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
    cin >> T;
    while (T--)
    {
        issue();
    }
    return 0;
}
