#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1010;

// 可以重复的选
int n, m;
int w[N], v[N];
int mem[N][N];

int dfs(int x, int spv)
{
    if (mem[x][spv] != -1)
        return mem[x][spv];
    if (x > n)
        return 0;
    int sum = 0;
    if (spv < v[x])
        sum = dfs(x + 1, spv);
    else
        sum = max(dfs(x + 1, spv), dfs(x, spv - v[x]) + w[x]); // 可以重复的选择，所以选的时候不+1
    mem[x][spv] = sum;
    return sum;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &v[i], &w[i]);
    memset(mem, -1, sizeof mem);
    int res = dfs(1, m);
    printf("%d", res);
    return 0;
}