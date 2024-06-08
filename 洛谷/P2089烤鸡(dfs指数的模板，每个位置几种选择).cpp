#include <bits/stdc++.h>
using namespace std;
#define ll long long

// https://www.luogu.com.cn/problem/P2089
const int N = 20;
int arr[N]; // �淽��
int n, res = 0;
int mem[59055][N];

// x��ʾ��ǰö�ٵ�λ�ã�sum�Ѿ�ѡ�õ�������
void dfs(int x, int sum)
{
    if (sum > n)
        return;
    if (x > 10)
    {
        if (sum == n)
        {
            res++;
            for (int i = 1; i <= 10; i++)
                mem[res][i] = arr[i];
        }
        return;
    }
    for (int i = 1; i <= 3; i++) // ÿ��λ�ö���3��ѡ��
    {
        arr[x] = i;
        dfs(x + 1, sum + i);
        arr[x] = 0;
    }
}

int main()
{
    scanf("%d", &n);
    dfs(1, 0);
    printf("%d\n", res);
    for (int i = 1; i <= res; i++)
    {
        for (int j = 1; j <= 10; j++)
            printf("%d ", mem[i][j]);
        puts("");
    }
    return 0;
}
