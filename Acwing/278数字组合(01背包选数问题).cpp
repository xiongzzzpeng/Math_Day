#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 11000;

int n, m;
int f[110][N];

// https://www.acwing.com/problem/content/description/280/
//  01背包有几种可能的问题
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < 110; i++)
        f[i][0] = 1;
    for (int i = n; i >= 1; i--)
    {
        int v;
        scanf("%d", &v);
        for (int j = 0; j <= m; j++)
        {
            // buxuan
            f[i][j] = f[i + 1][j];
            // xuan
            if (j >= v)
                f[i][j] += f[i + 1][j - v];
        }
    }

    printf("%d", f[1][m]);
    return 0;
}
