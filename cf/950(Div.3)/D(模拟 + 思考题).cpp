#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

// 最大公约数
int gcd(int a, int b)
{
    return __gcd(a, b);
}

// 删除一个数，就看删除后还有没有序
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

    // pre从左往右看有没有序，suf从右往左看有没有序
    vector<ll> pre(n + 1), suf(n + 1);
    pre[1] = suf[n - 1] = 1;
    for (int i = 2; i < n; i++)
        pre[i] = pre[i - 1] & (b[i] >= b[i - 1]);
    for (int i = n - 2; i >= 1; i--)
        suf[i] = suf[i + 1] & (b[i] <= b[i + 1]);

    int ans = 0;
    for (int i = 3; i <= n - 2; i++)
    {
        // 看删除哪个位置，从第三个到倒数第三个
        // 删除一个a要少原来的2个b插入一个新的b
        // 前三个删除有可能变成第一个，后面同理
        // 比如删除3的a，b2与b3都要被删所以直接与b1与b4比较
        if (pre[i - 2] && suf[i + 1] && gcd(a[i - 1], a[i + 1]) >= b[i - 2] && gcd(a[i - 1], a[i + 1]) <= b[i + 1])
        {
            ans = 1;
            break;
        }
    }

    // 删除前面的数新数变成第一个的时候，后面是变成最后一个的时候
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
