#include <bits/stdc++.h>
using namespace std;

const int N = 10;
bool st[N]; // 状态
int arr[N]; // 答案

int n;
// x表示当前枚举的位置
void dfs(int x)
{
    if (x > n)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%5d", arr[i]);
        }
        puts("");
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            st[i] = true;
            arr[x] = i;
            dfs(x + 1);
            st[i] = false; // 回溯
        }
    }
}

int main()
{
    scanf("%d", &n);
    dfs(1);

    return 0;
}