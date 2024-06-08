#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fs first
#define sc second
typedef pair<int, int> PII;
const int N = 1e6 + 10;

// // https://www.luogu.com.cn/problem/P5788

// tt是栈尾
int stk[N], tt;

// 单调栈
int mo_stack()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        // 找左边离他最近的且比他小的数
        int x;
        cin >> x;
        while (tt != 0 && stk[tt] >= x)
            tt--;
        if (tt != 0)
            cout << stk[tt];
        stk[++tt] = x;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("xzp.in", "r", stdin);
    freopen("xzp.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> sta, a(n + 1, 0), f(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // 从右看就倒序
    for (int i = n; i >= 1; i--)
    {
        while (!sta.empty() && a[sta.back()] <= a[i])
            sta.pop_back();
        f[i] = sta.empty() ? 0 : sta.back();
        sta.push_back(i);
    }
    for (int i = 1; i <= n; i++)
        cout << f[i] << " ";
    return 0;
}
