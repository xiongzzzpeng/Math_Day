#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
int m, n;
int g[N][N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &g[i][j]); // ����������������
    for (int i = 1; i <= n; i++)
    {
        int ans = 0;
        for (int j = 1; j <= n; j++)
        {
            if (j == i)
                continue;
            bool flag = true;
            for (int k = 1; k <= m; k++)
            {
                if (g[j][k] <= g[i][k])
                    flag = false;
            }
            if (flag)
            {
                ans = j;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
} // ����ѭ��������ö�٣�ÿ��ö�ٶ����Լ���©�����о����﷨û����