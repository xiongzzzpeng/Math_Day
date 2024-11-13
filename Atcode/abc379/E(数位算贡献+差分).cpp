#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using i64 = long long;
using PII = pair<int, int>;
using PLL = pair<i64, i64>;
using u64 = unsigned long long;
using u32 = unsigned;

/*

    算贡献一般是考虑这个数的贡献 or 个位答案有什么构成
    f(l, r) = sum(i * a[i] * 10^(r - i))
    列开
    sum(l, n)sum(r, n)sum(l, r)a[i] * 10^(r-i)
    移动sum
    sum(1, n)sum(1, i)sum(i, r)a[i] * 10^(r-i)
    发现与l没关系(第二个sum)
    sum(1, n) i * a[i] * sum(0, n - i) * 10^(r)
    就可以合并
    sum(1, n) * [a[i] * sum(0, n - i) * 10^(r)]
    后面转换成10进制 在(r)加上 i * a[i]
    用差分快速求

*/

void Solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<i64> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = s[i - 1] - '0';
    }

    // b[i]就是差分数组
    for (int i = n; i >= 1; i--) {
        b[i] = a[i] * i;
    }
    // 还原，相当于b[i] 前面的和 i看成数位
    for (int i = 1; i <= n; i++) {
        b[i] += b[i - 1];
    }

    for (int i = n; i >= 1; i--) {
        b[i - 1] += b[i] / 10;
        b[i] %= 10;
    }

    if (b[0] != 0) {
        cout << b[0];
    }
    for (int i = 1; i <= n; i++) {
        cout << b[i];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

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