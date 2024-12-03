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
线段树
建树的过程是O(n)
单次查询的时间复杂度O(logn)
区间修改O(logn)
*/

struct Info {
    int max = -1E9;
    int cnt = 0;
    i64 sum = 0;
};

Info operator+(const Info &a, const Info &b) {
    Info res;
    if (a.max > b.max) {
        res.max = a.max;
        res.cnt = a.cnt;
    } else if (a.max < b.max) {
        res.max = b.max;
        res.cnt = b.cnt;
    } else {
        res.max = a.max;
        res.cnt = a.cnt + b.cnt;
    }
    res.sum = a.sum + b.sum;
    return res;
}

class SegmentTree {
   public:
    SegmentTree(int n_) : n(n_), tag(4 * n), info(4 * n) {}

    // 查询，最大值，出现次数
    Info query(int x, int y) {
        return query(1, 0, n, x, y);
    }

    // 返回[x, y)的和
    i64 Sum(int x, int y) {
        return query(1, 0, n, x, y).sum;
    }

    // [x, y)的范围上+v
    void rangeAdd(int x, int y, int v) {
        rangeAdd(1, 0, n, x, y, v);
    }

    // 修改x的单点
    void modify(int x, const Info &v) {
        modify(1, 0, n, x, v);
    }

   private:
    int n;
    vector<int> tag;
    vector<Info> info;

    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }

    void add(int p, int v, int l, int r) {
        tag[p] += v;
        info[p].max += v;
        info[p].sum += v * (r - l);
    }

    void push(int p, int l, int r) {
        int m = (l + r) / 2;
        add(2 * p, tag[p], l, m);
        add(2 * p + 1, tag[p], m, r);
        tag[p] = 0;
    }

    Info query(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return {};
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        push(p, l, r);
        return query(2 * p, l, m, x, y) + query(2 * p + 1, m, r, x, y);
    }

    void rangeAdd(int p, int l, int r, int x, int y, int v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            add(p, v, l, r);
            return;
        }
        int m = (l + r) / 2;
        push(p, l, r);
        rangeAdd(2 * p, l, m, x, y, v);
        rangeAdd(2 * p + 1, m, r, x, y, v);
        pull(p);
    }

    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p, l, r);
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
};

void Solve() {
    int n = 10;
    SegmentTree segTree(n);

    // 初始化
    for (int i = 0; i < n; i++) {
        // i的位置添加i，第三个位置是i
        segTree.modify(i, {i, 1, i});
    }

    Info result = segTree.query(0, 5);
    cout << result.max << result.cnt << endl;

    int sumResult = segTree.Sum(0, 5);
    cout << sumResult << endl;

    segTree.rangeAdd(2, 7, 3);
    cout << segTree.Sum(2, 7) << "\n";

    segTree.rangeAdd(0, 2, 2);
    cout << segTree.Sum(0, 2) << "\n";
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
