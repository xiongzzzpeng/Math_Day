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

// 树状数组（O(logn)）
// 一定从1下标开始 范围是 [lowbit(x) + 1, x]
// 如 2 0010 取最左边的1 0000 再加1 [0001, 2]
// add: i += 最右侧1 3: 0011 + 0001 = 4 4: 0100 + 0100 = 8
// sum: i -= 最右侧1 3：0011 - 0001 = 2 2： 0010 - 0010 = 0
// 单点增加和范围查询（可拆分信息）

template <typename T>
class Fenwick {
   public:
    Fenwick(int n_ = 0) {
        init(n_);
    }

    // 在i的位置添加val
    void add(int i, const T& val) {
        for (; i <= n; i += i & -i) {
            a[i] += val;
        }
    }

    // 求sum([1, i])
    T sum(int i) {
        T ans{};
        for (; i > 0; i -= i & -i) {
            ans += a[i];
        }
        return ans;
    }

    // 求sum([r, l])
    T rangeSum(int left, int right) {
        return sum(right) - sum(left - 1);
    }

    // 找 <= k的最大下标
    int select(const T& k) {
        int res = 0;
        T cur{};
        for (int i = 1 << __lg(n); i; i /= 2) {
            if (res + i <= n && cur + a[res + i] <= k) {
                res += i;
                cur += a[res];
            }
        }
        return res;
    }

   private:
    int n;
    vector<T> a;

    void init(int n_) {
        n = n_;
        a.assign(n + 2, T{});
    }
};

// 区间增加，点的查询
// 用Fenwick维护差分数组，sum([1, i])就点的值
void diff() {
    int n, m;
    cin >> n >> m;

    Fenwick<int> fenwick(n);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        fenwick.add(i, x);
        fenwick.add(i + 1, -x);
    }
    while (m--) {
        int a;
        cin >> a;
        if (a == 1) {
            int left, right, val;
            cin >> left >> right >> val;
            fenwick.add(left, val);
            fenwick.add(right + 1, -val);
        } else {
            int b;
            cin >> b;
            cout << fenwick.sum(b) << "\n";
        }
    }
}

void Solve() {
    int n, m;
    cin >> n >> m;

    Fenwick<int> fenwick(n);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        fenwick.add(i, x);
    }

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            fenwick.add(b, c);
        }
        if (a == 2) {
            cout << fenwick.rangeSum(b, c) << "\n";
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

#ifdef LOCAL
    freopen("zcy.in", "r", stdin);
    freopen("zcy.out", "w", stdout);
#endif

    int T = 1;
    // cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
