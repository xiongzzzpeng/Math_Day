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
    int n;
    cin >> n;
    vector<ll> f(n + 1), g(n + 1), l(n + 1), r(n + 1), x(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];

    f[0] = g[0] = 0;

    // 三个数求和的范围是 sum(l)~sum(r)
    // 每个范围递推回去就行
    for (int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1] + l[i];
        g[i] = g[i - 1] + r[i];
    }

    if (!(f[n] <= 0 && 0 <= g[n]))
    {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;

    ll goal = 0;
    for (int i = n; i >= 1; i--)
    {
        // x1 + ... + xi = goal
        // x1 + ... + xi - 1 = goal - xi
        // goal - xi in [f[i - 1], g[i - 1]]
        // -xi in [f[i - 1] - goal, g[i - 1] - goal]
        // xi in [goal - g[i - 1], goal - f[i - 1]]
        // xi in [l[i], r[i]]

        x[i] = max(goal - g[i - 1], l[i]);
        goal -= x[i];
    }

    for (int i = 1; i <= n; i++)
        cout << x[i] << " ";
    cout << endl;
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
