#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 10;

// https://www.luogu.com.cn/problem/P1678

int m, n;
int main()
{
    int sc[N] = {0};
    int stu[N] = {0};
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++)
        scanf("%d", &sc[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &stu[i]);
    sort(sc, sc + m);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int big = lower_bound(sc, sc + m, stu[i]) - sc;
        res += min(abs(sc[big] - stu[i]), abs(sc[big - 1] - stu[i]));
    }
    cout << res;
    return 0;
}
