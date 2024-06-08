#include <bits/stdc++.h>
using namespace std;
#define ll long long

// https://www.luogu.com.cn/problem/P1088

const int N = 10010;

int n, m;
int mars[N], arr[N]; // arr是记录方案，mars是手指
bool st[N];          // 选没选过
int res = 0;
bool yes = false;

void dfs(int x)
{
    if (yes) // 剪枝
        return;
    if (x > n)
    {
        res++;
        if (res == m + 1)
        {
            yes = true;
            for (int i = 1; i <= n; i++)
                printf("%d ", arr[i]);
        }
        return;
    }
    for (int i = 1; i <= n; i++) // 全排列模板
    {
        if (res == 0)
            i = mars[x]; // 灵魂该题
        if (!st[i])
        {
            st[i] = true; // 表示被选
            arr[x] = i;
            dfs(x + 1);
            st[i] = false;
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &mars[i]);
    dfs(1);
    return 0;
}
