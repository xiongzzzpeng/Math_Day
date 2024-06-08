#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;
const int N = 10010, M = 100010;

int n, m;
char p[N], s[M];
int ne[N];

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("xzp.in", "r", stdin);
    freopen("xzp.out", "w", stdout);

    cin >> n >> p + 1 >> m >> s + 1;
    // 求next过程
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j != 0 && p[i] != p[j + 1])
            j = ne[j];
        if (p[i] == p[j + 1])
            j++;
        ne[i] = j;
    }

    for (int i = 1, j = 0; i <= m; i++)
    {
        // j = 0就重新匹配
        while (j != 0 && s[i] != p[j + 1])
            j = ne[j]; // 退一步
        if (s[i] == p[j + 1])
            j++;
        if (j == n)
        {
            // 匹配成功
            cout << i - n + 1 << " ";
            j = ne[j];
        }
    }
    return 0;
}
