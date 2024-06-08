#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1010;

// 可以重复的选
int n, m;
int w[N], v[N];
int f[N][N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &v[i], &w[i]);
    for (int i = n; i >= 1; i--)
        for (int j = 0; j <= m; j++)
        {
            if (j < v[i])
                f[i][j] = f[i + 1][j];
            else
                f[i][j] = max(f[i + 1][j], f[i][j - v[i]] + w[i]);
        }
    printf("%d", f[1][m]);
    return 0;
}