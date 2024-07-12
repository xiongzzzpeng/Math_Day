#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

// https://www.luogu.com.cn/problem/P4799
// 双向广搜+dfs,双向广搜的典
// 从i开始到e结束,s累加和，w背包容量,j是记录填的位置
ll f(vector<ll> &arr, int i, int e, ll s, ll w, vector<ll> &ans, ll j)
{
    if (s > w)
        return j;
    if (i == e)
        ans[j++] = s;
    else
    {
        // ans使用到了哪里
        j = f(arr, i + 1, e, s, w, ans, j);
        j = f(arr, i + 1, e, s + arr[i], w, ans, j);
    }

    return j;
}

ll two_way(vector<ll> &arr, ll n, ll w)
{
    vector<ll> lsum(1 << 20);
    vector<ll> rsum(1 << 20);

    ll lsize = f(arr, 0, n >> 1, 0, w, lsum, 0);
    ll rsize = f(arr, n >> 1, n, 0, w, rsum, 0);

    sort(lsum.begin(), lsum.begin() + lsize);
    sort(rsum.begin(), rsum.begin() + rsize);

    ll ans = 0;
    for (ll l = lsize - 1, r = 0; l >= 0; l--)
    {
        while (r < rsize && lsum[l] + rsum[r] <= w)
        {
            r++;
        }
        ans += r;
    }

    return ans;
}

void issue()
{
    ll n, w;
    cin >> n >> w;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << two_way(arr, n, w);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("xzp.in", "r", stdin);
    freopen("xzp.out", "w", stdout);
#endif

    int T = 1;
    // cin >> T;
    while (T--)
    {
        issue();
    }
    return 0;
}
