#include <bits/stdc++.h>
using namespace std;

const int N = 2010;

int n, m;
int b[N][N];

int main()
{
    scanf("%d%d", &n, &m);
    while (m--)
    {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

        b[x1][y1]++;
        b[x1][y2 + 1]--;
        b[x2 + 1][y1]--;
        b[x2 + 1][y2 + 1]++;
    } // 模板题，二维差分，就是有添加有翻转，奇变偶不变

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1]; // 求前缀和
            printf("%d", b[i][j] & 1);                              //&1跟%2一样，%2有负数
        }
        puts(""); // 换行
    }

    return 0;
}