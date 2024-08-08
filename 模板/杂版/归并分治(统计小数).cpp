#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

ll merge(int l, int m, int r, vector<int> &num) {
    ll ans = 0;
    int L = l, R = m + 1;
    vector<int> temp(r - l + 1);
    int index = 0;

    // 根据题意修改
    /*
   while (L <= m && R <= r) {
       if (num[L] <= num[R]) {
           ans += (r - R + 1) * num[L];
           temp[index++] = num[L++];
       } else {
           ans += (m - L + 1)
           temp[index++] = num[R++];
       }
   }
    */

    // 归并排序模板
    while (L <= m) {
        temp[index++] = num[L++];
    }
    while (R <= r) {
        temp[index++] = num[R++];
    }
    for (int i = 0; i < index; i++) {
        num[l + i] = temp[i];
    }

    return ans;
}

ll sum(int l, int r, vector<int> &num) {
    if (l == r)
        return 0;
    int m = (l + r) / 2;
    return sum(l, m, num) + sum(m + 1, r, num) + merge(l, m, r, num);
}

void Solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << sum(0, n - 1, a) << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("xzp.in", "r", stdin);
    freopen("xzp.out", "w", stdout);
#endif

    int T = 1;
    // cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
