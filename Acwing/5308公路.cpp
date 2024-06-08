#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 100010;

ll n, d;
ll v[N], a[N];

int main()
{
    scanf("%lld%lld", &n, &d);
    for (int i = 1; i < n; i++)
        scanf("%lld", &v[i]);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]); // 油价
    ll ans = 0, oil = 0, dist = 0;
    int p = a[1];
    for (int i = 2; i <= n; i++)
    {
        dist += v[i - 1];                // 到下一个点的距离
        ll t = (dist + d - 1) / d - oil; // 需要的油量，向上取整
        ans += t * p;                    // 更新需要的价格
        oil += t;                        // 更新剩余的油量
        p = min((ll)p, a[i]);            // 最小的价格
    }
    printf("%lld\n", ans);
    return 0;
}
/*
    先不加油，看需要多少油到下一个点
    从上一个可以补油的地方加，选择价格最低的
    如：2到3，1加油是最便宜的地方，就在1加到可以跑到3的点
*/