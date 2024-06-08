#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;
const int mod = 1e8;

// https://atcoder.jp/contests/abc353/tasks/abc353_c
// 求余可以转换成减去好多mod
// 一直wa不知道为什么
// 5月29日知道wa的原因了,int n暴int了

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll ans = 0, num = 0;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans += (n - 1) * a[i];
    }
    sort(a.begin(), a.end());
    int j = n;
    for (int i = 1; i <= n; i++)
    {
        while (a[i] + a[j] >= mod)
            j--;
        num += min(n - i, n - j);
    }
    cout << ans - (num * mod);
    return 0;
}
