#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

// 树状数珠用于可差分信息
// 管的范围是x二进制, 如12 (001100) 变成(001001 - 001100)
// 一般是点增加,范围增加是线段树

struct Fenwick {
    int n;
    vector<int> a;

    Fenwick(int n_ = 0) {
        init(n_);
    }

    void init(int n_) {
        n = n_;
        a.assign(n, 0); // 将数组 a 初始化为 0
    }

    void add(int x, int v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }

    // 前缀和[0, x - 1]
    int pre_sum(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }

    // 区间和[l, r - 1]
    int rangeSum(int l, int r) {
        return pre_sum(r) - pre_sum(l);
    }

    // 前缀和 <= k 的最远位置
    int select(int k) {
        int x = 0;
        int cur = 0;
        for (int i = 1 << __lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] <= k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};

void Solve() {
    Fenwick fen(10);

    // 添加一些值
    fen.add(0, 3);
    fen.add(1, 2);
    fen.add(2, 4);
    fen.add(3, -1);
    fen.add(4, 5);

    // 查询前缀和[0, (x - 1)]
    cout << "Sum of first 3 elements: " << fen.pre_sum(3) << endl;

    // 查询区间和[l, (r - 1)]
    cout << "Sum of range [1, 3): " << fen.rangeSum(1, 3) << endl;

    // 使得前缀和小于或等于k，最大的位置
    cout << "Index with prefix sum <= 9: " << fen.select(9) << endl;
}

int main() {
    ios::sync_with_stdio(false);
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
