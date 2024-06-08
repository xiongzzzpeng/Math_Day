#include <bits/stdc++.h>
using namespace std;
#define ll long long

// https://www.acwing.com/problem/content/4408/
const int N = 510;
int s[N][N];
int n, m, k;
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &s[i][j]);
            s[i][j] += s[i - 1][j]; // 只用预处理列的和
        }
    }
    ll res = 0;
    for (int i = 1; i <= n; i++)     // 枚举上边界
        for (int j = i; j <= n; j++) // 枚举下边界
            for (int l = 1, r = 1, sum = 0; r <= m; r++)
            {
                sum += s[j][r] - s[i - 1][r];
                while (sum > k)
                {
                    sum -= s[j][l] - s[i - 1][l]; // 把l列删掉
                    l++;
                }
                res += r - l + 1;
            }
    printf("%lld", res);
    return 0;
}
