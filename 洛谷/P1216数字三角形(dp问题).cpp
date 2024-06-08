#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1010;

// https://www.luogu.com.cn/problem/P1216

int n;
int tree[N][N];
int mem[N][N];

int dfs(int x, int y)
{
    for (int i = n; i > 0; i--)
        for (int j = i; j > 0; j--)
            mem[i][j] = max(mem[i + 1][j], mem[i + 1][j + 1]) + tree[i][j];
    return mem[1][1];
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            scanf("%d", &tree[i][j]);
    int res = dfs(1, 1);
    printf("%d", res);
    return 0;
}
