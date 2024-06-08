#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 150;

ll q[N][N], prefix[N][N];
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            scanf("%lld", &q[i][j]);
            // 输入
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + q[i][j];
            // O(1)递推出s[i][j]，二维前缀和
        }
    ll ans = INT_MIN;
    for (int x1 = 1; x1 <= n; x1++)
        for (int y1 = 1; y1 <= n; y1++)
            for (int x2 = x1; x2 <= n; x2++)
                for (int y2 = y1; y2 <= n; y2++)
                    // 算一个矩阵的和的值公式
                    ans = max(ans, prefix[x2][y2] - prefix[x2][y1 - 1] - prefix[x1 - 1][y2] + prefix[x1 - 1][y1 - 1]);
    printf("%lld", ans);
    return 0;
}
