#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 100010;
int sum[N], a[N], res[N];
int n, k;
ll ans = 0;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        sum[i] = (sum[i - 1] + a[i]) % k;
        ans += res[sum[i]];
        res[sum[i]]++;
    }
    printf("%lld", ans + res[0]);

    return 0;
}
