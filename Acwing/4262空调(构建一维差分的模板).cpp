#include <bits/stdc++.h>
using namespace std;
#define ll long long

// https://www.acwing.com/solution/content/65561/
const int M = 1e5 + 10;

int w[M], diff[M];
int N, p;
int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &w[i]);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &p);
        w[i] -= p;
    }
    for (int i = 1; i <= N + 1; i++)
        diff[i] = w[i] - w[i - 1]; // 建立差分数组
    int res = 0;
    for (int i = 1; i <= N + 1; i++)
        if (diff[i] > 0)
            res += diff[i];
    printf("%d", res);
    return 0;
}
