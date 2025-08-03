#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr int MOD = 998244353;

i64 inv(i64 a) {
    i64 r = 1, p = MOD - 2;
    while (p) {
        if (p & 1) r = r * a % MOD;
        a = a * a % MOD;
        p >>= 1;
    }
    return r;
}

struct SegTree {
    i64 n;
    vector<i64> sum, lazy;
    vector<bool> marked;
    SegTree(i64 _n) {
        n = _n;
        sum.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        marked.assign(4 * n, 0);
    }
    void push(i64 v, i64 tl, i64 tr) {
        if (!marked[v]) return;
        sum[v] = lazy[v] * (tr - tl + 1) % MOD;
        if (tl != tr) {
            lazy[v * 2] = lazy[v * 2 + 1] = lazy[v];
            marked[v * 2] = marked[v * 2 + 1] = 1;
        }
        marked[v] = 0;
    }
    void build(vector<i64> &a, i64 v, i64 tl, i64 tr) {
        if (tl == tr)
            sum[v] = a[tl];
        else {
            i64 tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            sum[v] = (sum[v * 2] + sum[v * 2 + 1]) % MOD;
        }
    }

    // 区间赋值
    // v是起始位置，tl是开始的位置，tr是结束的位置一般是1和n。
    void range_set(i64 v, i64 tl, i64 tr, i64 l, i64 r, i64 val) {
        push(v, tl, tr);
        if (l > r) return;
        if (l == tl && r == tr) {
            lazy[v] = val;
            marked[v] = 1;
            push(v, tl, tr);
        } else {
            i64 tm = (tl + tr) / 2;
            range_set(v * 2, tl, tm, l, min(r, tm), val);
            range_set(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
            sum[v] = (sum[v * 2] + sum[v * 2 + 1]) % MOD;
        }
    }

    i64 range_sum(i64 v, i64 tl, i64 tr, i64 l, i64 r) {
        push(v, tl, tr);
        if (l > r) return 0;
        if (l == tl && r == tr) return sum[v];
        i64 tm = (tl + tr) / 2;
        return (range_sum(v * 2, tl, tm, l, min(r, tm)) + range_sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)) % MOD;
    }

    // 得到数组元素
    void get_vals(i64 v, i64 tl, i64 tr, vector<i64> &res) {
        push(v, tl, tr);
        if (tl == tr)
            res[tl] = sum[v];
        else {
            i64 tm = (tl + tr) / 2;
            get_vals(v * 2, tl, tm, res);
            get_vals(v * 2 + 1, tm + 1, tr, res);
        }
    }
};

void Solve() {
    int n, m;
    cin >> n >> m;

    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    SegTree st(n);
    st.build(a, 1, 1, n);

    while (m--) {
        int l, r;
        cin >> l >> r;
        i64 tmp = st.range_sum(1, 1, n, l, r);
        i64 len = r - l + 1;
        i64 avg = tmp * inv(len) % MOD;
        st.range_set(1, 1, n, l, r, avg);
    }

    vector<i64> ans(n + 1);
    st.get_vals(1, 1, n, ans);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
