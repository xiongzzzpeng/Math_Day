#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 10;

int a[N], a2[N];
int n;
bool st[N], st2[N];
int num[N];

void dfs(int x) // 1 - n�ķ�Χ
{
    if (x > n)
    {
        for (int i = 1; i <= n; i++)
            printf("%d ", a[i]);
        puts("");
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            st[i] = true;
            a[x] = i;
            dfs(x + 1);
            st[i] = false;
        }
    }
}

void dfs2(int x) // �Լ�ѡ���ķ�Χ
{
    for (int i = 1; i <= n; i++)
    {
        if (x > n)
        {
            for (int i = 1; i <= n; i++)
                printf("%d ", a2[i]);
            puts(" ");
            return;
        }
        if (!st2[num[i]])
        {
            st2[num[i]] = true;
            a2[x] = num[i];
            st2[num[i]] = false;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &num[i]);
    dfs2(1);
    dfs(1);
    return 0;
}
