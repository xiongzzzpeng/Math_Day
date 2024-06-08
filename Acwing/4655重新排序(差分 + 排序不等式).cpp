#include <bits/stdc++.h>
using namespace std;
#define ll long long

// https://www.acwing.com/problem/content/4658/
//  1、用差分求每个位置被+了多少次
//  2、c1*a1.....cn*an。就是排序不等式，当c是正序，a是逆序和最小。都是正序就是最大

const int N = 1e5 + 10;
ll s[N], w[N];
int n, m;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    scanf("%d", &m);
    while (m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        s[l]++;
        s[r + 1]--;
    }
    for (int i = 1; i <= n; i++)
        s[i] += s[i - 1]; // 计算差分数组
    ll sum1 = 0;
    for (int i = 1; i <= n; i++)
    {
        sum1 += (ll)w[i] * s[i];
    }
    sort(s + 1, s + n + 1); // 因为0的位置是0，差分用到了n+1
    sort(w + 1, w + n + 1);
    ll sum2 = 0; // 最大值
    for (int i = 1; i <= n; i++)
        sum2 += (ll)w[i] * s[i];
    printf("%lld", sum2 - sum1);
    return 0;
}
