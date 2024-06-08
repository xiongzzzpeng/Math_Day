#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 30;

int a[N];
int n, k;
int arr[N];
int res;

bool is_prim(int sum) // 判断素数模板
{
    if (sum <= 1)
        return false;
    for (int i = 2; i * i <= sum; i++)
        if (sum % i == 0)
            return false;
    return true;
}

void dfs(int x, int start)
{
    if (x > k)
    {
        int sum = 0;
        for (int i = 1; i <= k; i++)
            sum += arr[i];
        if (is_prim(sum))
            res++;
        return;
    }
    for (int i = start; i <= n; i++)
    {
        arr[x] = a[i];
        dfs(x + 1, i + 1);
        arr[x] = 0;
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    dfs(1, 1); // 选的个数,开始的位置
    printf("%d", res);
    return 0;
}
