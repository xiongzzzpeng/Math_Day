#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1000010;

int n, m;

int l[N], r[N], d[N], w[N];
ll b[N];

bool check(int mid)
{
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= mid; i++)
    {
        b[l[i]] += d[i];
        b[r[i] + 1] -= d[i];
    }

    for (int i = 1; i <= n; i++)
    {
        b[i] += b[i - 1];
        if (b[i] > w[i])
            return false;
    }
    return true;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &d[i], &l[i], &r[i]);
    int l = 0, r = m;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    if (r == m)
        puts("0");
    else
        printf("-1\n%d", r + 1);
    return 0;
}
