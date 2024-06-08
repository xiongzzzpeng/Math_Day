#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
typedef pair<int, int> PII;

int main()
{
    // 幂运算的逆运算的对数运算
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("xzp.in", "r", stdin);
    freopen("xzp.out", "w", stdout);
    ll n;
    cin >> n;
    int i = 0, sum = 0;
    for (i; sum <= n; i++)
        sum += pow(2, i);
    cout << i << endl;
    // 数学写法，上取整
    // cout << __lg(n + 1) + 1 << endl;
    return 0;
}
