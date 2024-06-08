#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1100;

int n, v;
int volume[N];
int val[N];
bool st[N];
int sum_vol;
int sum_val;
int mem[N][N]; // 有几个变量就是几维
int f[N][N];

// 记忆化模板
int dfs1(int x, int sp_vol)
{
    if (mem[x][sp_vol] != -1)
        return mem[x][sp_vol];
    int sum = 0;
    if (x > n)
        return 0;
    else if (sp_vol < volume[x])
        sum = dfs1(x + 1, sp_vol);
    else if (sp_vol >= volume[x])
        sum = max(dfs1(x + 1, sp_vol), dfs1(x + 1, sp_vol - volume[x]) + val[x]);
    mem[x][sp_vol] = sum;
    return sum;
}

int main()
{
    scanf("%d%d", &n, &v);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &volume[i], &val[i]);
    memset(mem, -1, sizeof mem);
    int res = dfs1(1, v);
    // 递推推到，根据上面dfs可得
    for (int i = n; i > 0; i--)
        for (int j = 0; j <= v; j++)
        {
            if (j < volume[i])
                f[i][j] = f[i + 1][j];
            else if (j >= volume[i])
                f[i][j] = max(f[i + 1][j], f[i + 1][j - volume[i]] + val[i]);
        }
    printf("%d", f[1][v]);
    return 0;
}
