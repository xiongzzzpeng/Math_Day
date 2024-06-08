#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 200010;

// https://www.luogu.com.cn/problem/P1102
// 将 A - B = C 变成 A = B + C 再用二分找A就行

int n, c;
int q[N];

int bSearch1(int q[], int n, int A) // 找左边的点
{
    int l = 0, r = n + 1;
    while (l + 1 < r)
    {
        int mid = l + r >> 1;
        if (q[mid] < A)
            l = mid;
        else
            r = mid;
    }
    if (q[r] == A)
        return r;
    else
        return -1;
}

void bsearch3()
{ // 用函数实现
    int q[N] = {0};
    scanf("%d%d", &n, &c);
    ll ans = 0;
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);
    sort(q, q + n);
    for (int b = 0; b < n; b++)
    {
        int a = q[b] + c;
        int res1 = lower_bound(q, q + n, a) - q;
        int res2 = upper_bound(q, q + n, a) - q;
        ans += res2 - res1;
    }
    cout << ans;
}

int bSearch2(int q[], int n, int A) // 找右边点
{
    int l = 0, r = n + 1;
    while (l + 1 < r)
    {
        int mid = l + r >> 1;
        if (q[mid] <= A)
            l = mid;
        else
            r = mid;
    }
    if (q[l] == A)
        return l;
    else
        return -1;
}

int main()
{
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= n; i++)
        scanf("%d", &q[i]);
    sort(q + 1, q + 1 + n);
    ll ans = 0;
    for (int B = 1; B <= n; B++)
    {
        int A = q[B] + c;
        int res = bSearch1(q, n, A);
        if (res == -1)
            continue;
        else
        {
            int res2 = bSearch2(q, n, A);
            ans += res2 - res + 1;
        }
    }
    cout << ans;
    return 0;
}
