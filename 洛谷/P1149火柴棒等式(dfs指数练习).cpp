#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 10010;
int arr[N];
int n, res = 0;
int hot[N] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

// https://www.luogu.com.cn/problem/P1149
int sumFire(int i) // ¼ÆËã»ğ²ñ¹÷ºÍ
{
    if (hot[i] > 0)
        return hot[i];
    int sum = 0;
    while (i)
    {
        sum += hot[i % 10];
        i = i / 10;
    }
    return sum;
}

void dfs(int x, int cnt)
{
    if (cnt > n)
        return; // ¼ôÖ¦
    if (x > 3)
    {
        if (arr[1] + arr[2] == arr[3] && cnt == n)
            res++;
        return;
    }

    for (int i = 0; i <= 1000; i++)
    {
        arr[x] = i;
        dfs(x + 1, cnt + sumFire(i));
    }
}

int main()
{
    scanf("%d", &n);
    n -= 4; // Ô¤´¦Àí
    dfs(1, 0);
    cout << res;
    return 0;
}
