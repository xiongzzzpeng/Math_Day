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

class SegmentTree {
   public:
    SegmentTree(vector<int> &inputArr) {
        int n = inputArr.size();
        arr = inputArr;
        mx.resize(n << 2);
        add.resize(n << 2);
        change.resize(n << 2);
        update.resize(n << 2);
        build(1, n, 1);
    }

    void Rangeadd(int l, int r, i64 v) {
        addRange(l, r, v, 1, arr.size(), 1);
    }

    void Rangeupdate(int l, int r, i64 v) {
        updateRange(l, r, v, 1, arr.size(), 1);
    }

    i64 Mxrange(int l, int r) {
        return query(l, r, 1, arr.size(), 1);
    }

   private:
    vector<int> arr;
    vector<i64> mx;
    vector<i64> add;
    vector<i64> change;
    vector<bool> update;

    void up(int i) {
        mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
    }

    void down(int i) {
        if (update[i]) {
            updateLazy(i << 1, change[i]);
            updateLazy(i << 1 | 1, change[i]);
            update[i] = false;
        }
        if (add[i] != 0) {
            addLazy(i << 1, add[i]);
            addLazy(i << 1 | 1, add[i]);
            add[i] = 0;
        }
    }

    void updateLazy(int i, i64 v) {
        mx[i] = v;
        add[i] = 0;
        change[i] = v;
        update[i] = true;
    }

    void addLazy(int i, i64 v) {
        mx[i] += v;
        add[i] += v;
    }

    void build(int l, int r, int i) {
        if (l == r) {
            mx[i] = arr[l - 1];
        } else {
            int mid = (l + r) >> 1;
            build(l, mid, i << 1);
            build(mid + 1, r, i << 1 | 1);
            up(i);
        }
        add[i] = 0;
        change[i] = 0;
        update[i] = false;
    }

    void updateRange(int jobl, int jobr, i64 jobv, int l, int r, int i) {
        if (jobl <= l && r <= jobr) {
            updateLazy(i, jobv);
        } else {
            int mid = (l + r) >> 1;
            down(i);
            if (jobl <= mid) {
                updateRange(jobl, jobr, jobv, l, mid, i << 1);
            }
            if (jobr > mid) {
                updateRange(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
            }
            up(i);
        }
    }

    void addRange(int jobl, int jobr, i64 jobv, int l, int r, int i) {
        if (jobl <= l && r <= jobr) {
            addLazy(i, jobv);
        } else {
            int mid = (l + r) >> 1;
            down(i);
            if (jobl <= mid) {
                addRange(jobl, jobr, jobv, l, mid, i << 1);
            }
            if (jobr > mid) {
                addRange(jobl, jobr, jobv, mid + 1, r, i << 1 | 1);
            }
            up(i);
        }
    }

    i64 query(int jobl, int jobr, int l, int r, int i) {
        if (jobl <= l && r <= jobr) {
            return mx[i];
        }
        int mid = (l + r) >> 1;
        down(i);
        i64 ans = LLONG_MIN;
        if (jobl <= mid) {
            ans = max(ans, query(jobl, jobr, l, mid, i << 1));
        }
        if (jobr > mid) {
            ans = max(ans, query(jobl, jobr, mid + 1, r, i << 1 | 1));
        }
        return ans;
    }
};

void Solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    SegmentTree seg(a);

    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            seg.Rangeupdate(l, r, x);
        } else if (op == 2) {
            int l, r, x;
            cin >> l >> r >> x;
            seg.Rangeadd(l, r, x);
        } else if (op == 3) {
            int l, r;
            cin >> l >> r;
            cout << seg.Mxrange(l, r) << "\n";
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
