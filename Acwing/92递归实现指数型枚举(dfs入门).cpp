#include <bits/stdc++.h>
using namespace std;
#define ll long long

// https://www.acwing.com/problem/content/94/
// dfs入门
int n;
bool st[20];

void dfs(int x)
{
    if (x > n)
    {
        for (int i = 1; i <= n; i++)
        {
            if (st[i])
                printf("%d ", i);
        }
        puts("");
        return; // 相当于回溯，跳回到上一步
    }
    else
    {
        st[x] = true;
        dfs(x + 1);

        st[x] = false;
        dfs(x + 1);
    }
}

int main()
{

    scanf("%d", &n);
    dfs(1);
    return 0;
}
