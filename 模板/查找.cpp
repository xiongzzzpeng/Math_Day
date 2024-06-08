#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;
const int N = 10;

int path[N], n, st[N];

// dfs:排序,带环要注意判断
void dfs(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; i++)
            cout << path[i];
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (st[i] == 0)
        {
            st[i] = 1;
            path[u] = i;
            dfs(u + 1);
            st[i] = 0;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("xzp.in", "r", stdin);
    freopen("xzp.out", "w", stdout);
    cin >> n;
    dfs(0);
    return 0;
}
