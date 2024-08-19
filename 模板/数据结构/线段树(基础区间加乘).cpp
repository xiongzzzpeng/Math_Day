#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

// 线段树用于区间合并的问题
// 时间复杂度: 范围修改，范围查询 log^n
// 作用范围: 区间内的 最大值 最小值 累加和(不能维护出现的最多数)

struct SegmentTree {
    const ll P = 1e12 + 7;
    int n;
    std::vector<ll> tag, sum, addTag;

    SegmentTree(int n_) : n(n_), tag(4 * n, 1), sum(4 * n), addTag(4 * n, 0) {}

    void pull(int p) {
        sum[p] = (sum[2 * p] + sum[2 * p + 1]) % P;
    }

    void applyMul(int p, ll v) {
        tag[p] = tag[p] * v % P;
        sum[p] = sum[p] * v % P;
        addTag[p] = addTag[p] * v % P;
    }

    void applyAdd(int p, ll v, int len) {
        sum[p] = (sum[p] + v * len % P) % P;
        addTag[p] = (addTag[p] + v) % P;
    }

    void push(int p, int l, int r) {
        int m = (l + r) / 2;
        applyMul(2 * p, tag[p]);
        applyMul(2 * p + 1, tag[p]);
        applyAdd(2 * p, addTag[p], m - l);
        applyAdd(2 * p + 1, addTag[p], r - m);
        tag[p] = 1;
        addTag[p] = 0;
    }

    // 查询[l, r)的和
    ll query(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return 0;
        }
        if (l >= x && r <= y) {
            return sum[p];
        }
        int m = (l + r) / 2;
        push(p, l, r);
        return (query(2 * p, l, m, x, y) + query(2 * p + 1, m, r, x, y)) % P;
    }

    ll query(int x, int y) {
        return query(1, 0, n, x, y);
    }

    // [l, r)上乘v
    void rangeMul(int p, int l, int r, int x, int y, ll v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            return applyMul(p, v);
        }
        int m = (l + r) / 2;
        push(p, l, r);
        rangeMul(2 * p, l, m, x, y, v);
        rangeMul(2 * p + 1, m, r, x, y, v);
        pull(p);
    }

    void rangeMul(int x, int y, ll v) {
        rangeMul(1, 0, n, x, y, v);
    }

    // [l, r)上加v
    void rangeAdd(int p, int l, int r, int x, int y, ll v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            return applyAdd(p, v, r - l);
        }
        int m = (l + r) / 2;
        push(p, l, r);
        rangeAdd(2 * p, l, m, x, y, v);
        rangeAdd(2 * p + 1, m, r, x, y, v);
        pull(p);
    }

    void rangeAdd(int x, int y, ll v) {
        rangeAdd(1, 0, n, x, y, v);
    }

    void add(int p, int l, int r, int x, ll v) {
        if (r - l == 1) {
            sum[p] = (sum[p] + v) % P;
            return;
        }
        int m = (l + r) / 2;
        push(p, l, r);
        if (x < m) {
            add(2 * p, l, m, x, v);
        } else {
            add(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }

    // 在x上添加v
    void add(int x, ll v) {
        add(1, 0, n, x, v);
    }
};

void Solve() {
    int n = 5;
    SegmentTree segTree(n);

    // 添加值到线段树
    segTree.add(0, 5); // 在索引0添加5
    segTree.add(1, 3); // 在索引1添加3
    segTree.add(2, 7); // 在索引2添加7
    segTree.add(3, 9); // 在索引3添加9
    segTree.add(4, 6); // 在索引4添加6

    // 对范围[1, 4)每个元素加2
    segTree.rangeAdd(1, 4, 2);

    // 查询范围[1, 4)的和 = 25
    cout << segTree.query(1, 4) << endl;

    // 对范围[1, 4)每个元素乘2
    segTree.rangeMul(1, 4, 2);

    // 查询范围[1, 4)的和 = 50
    cout << segTree.query(1, 4) << endl;
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
