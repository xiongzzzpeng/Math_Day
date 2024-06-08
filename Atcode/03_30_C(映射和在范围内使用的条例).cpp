#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 200010;

ll pl[N];
ll a, b, n, max1;

int main()
{
    scanf("%lld%lld%lld", &n, &a, &b);
    int r = a + b;
    for (ll i = 1; i <= n; i++)
    {
        scanf("%lld", &pl[i]);
        pl[i] = (pl[i] - 1) % r + 1; // 求余，+1是为了映射在1-a的范围内
    }
    sort(pl + 1, pl + 1 + n);
    if (pl[n] - pl[1] + 1 <= a) // 意味着所有的日期都可以安排在一个长度为a的连续星期内。
    {
        printf("Yes");
        return 0;
    }
    for (ll i = 2; i <= n; i++)
        max1 = max(max1, pl[i] - pl[i - 1] + 1); // 最多缺多少
    if (r - max1 <= a)                           // 可以用的是a天，不可以用的是b
        return printf("Yes"), 0;
    printf("No");
    return 0;
}
