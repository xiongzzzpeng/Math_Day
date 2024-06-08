#include <bits/stdc++.h>
using namespace std;
#define ll long long

// https://www.luogu.com.cn/problem/P1088

const int N = 10010;

int n, m;
int mars[N], arr[N]; // arr�Ǽ�¼������mars����ָ
bool st[N];          // ѡûѡ��
int res = 0;
bool yes = false;

void dfs(int x)
{
    if (yes) // ��֦
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
    for (int i = 1; i <= n; i++) // ȫ����ģ��
    {
        if (res == 0)
            i = mars[x]; // ������
        if (!st[i])
        {
            st[i] = true; // ��ʾ��ѡ
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
