#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 20;

// https://www.acwing.com/problem/content/description/4960/

int a[N][N];
bool st[N];
int t, n;
bool flag;

void dfs(int x, int now_time)
{
    if (x >= n)
    {
        printf("YES\n");
        flag = true; // ��ɽ���
    }

    if (flag)
        return;

    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            if (a[i][1] < now_time) // a[i][1]�ǵ�i����ٽ���ʱ��
                return;
            st[i] = true;
            if (a[i][0] > now_time)
                dfs(x + 1, a[i][0] + a[i][2]); // ���ھ͵�һ���ٽ���
            else
                dfs(x + 1, now_time + a[i][2]);
            st[i] = false;
        }
    }
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        memset(st, 0, sizeof st);
        flag = false;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
            a[i][1] += a[i][0];
        }
        dfs(0, 0);
        if (!flag)
            printf("NO\n");
    }
    return 0;
}
