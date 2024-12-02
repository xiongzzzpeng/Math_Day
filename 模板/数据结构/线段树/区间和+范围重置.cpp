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
    SegmentTree(vector<int>& inputArr) {
        int n = inputArr.size();
        arr = inputArr;
        sum.resize(4 * n);
        change.resize(4 * n);
        flag.resize(4 * n, false);
        build(1, n, 1);
    }

    // [l, r] 重置为 val, n 是数组大小
    void updateRange(int l, int r, i64 val, int n) {
        update(l, r, val, 1, n, 1);
    }

    // 求 [l, r] 的和
    i64 sumRange(int l, int r, int n) {
        return query(l, r, 1, n, 1);
    }

   private:
    vector<int> arr;     // 原始数据数组
    vector<i64> sum;     // 线段树节点存储区间和
    vector<bool> flag;   // 是否有懒更新标记
    vector<i64> change;  // 存储懒更新值

    // 更新父节点
    void up(int i) {
        sum[i] = sum[i * 2] + sum[i * 2 + 1];
    }

    // 懒更新操作
    void lazy(int i, i64 v, int n) {
        sum[i] = v * n;
        change[i] = v;
        flag[i] = true;
    }

    // 下发懒更新信息
    void down(int i, int ln, int rn) {
        if (flag[i]) {
            lazy(i * 2, change[i], ln);
            lazy(i * 2 + 1, change[i], rn);
            flag[i] = false;  // 清除当前节点的懒更新标记
        }
    }

    // 建立线段树
    void build(int l, int r, int i) {
        if (l == r) {
            sum[i] = arr[l - 1];  // 数组下标从0开始，调整为1-based
        } else {
            int mid = (l + r) / 2;
            build(l, mid, i * 2);          // 左子树
            build(mid + 1, r, i * 2 + 1);  // 右子树
            up(i);                         // 更新当前节点
        }
        change[i] = 0;
        flag[i] = false;
    }

    // 区间更新操作
    void update(int jobl, int jobr, i64 jobv, int l, int r, int i) {
        if (jobl <= l && r <= jobr) {
            lazy(i, jobv, r - l + 1);
        } else {
            int mid = (l + r) / 2;
            down(i, mid - l + 1, r - mid);
            if (jobl <= mid) {
                update(jobl, jobr, jobv, l, mid, i * 2);
            }
            if (jobr > mid) {
                update(jobl, jobr, jobv, mid + 1, r, i * 2 + 1);
            }
            up(i);
        }
    }

    // 区间查询操作
    i64 query(int jobl, int jobr, int l, int r, int i) {
        if (jobl <= l && r <= jobr) {
            return sum[i];
        }
        int mid = (l + r) / 2;
        down(i, mid - l + 1, r - mid);
        i64 ans = 0;
        if (jobl <= mid) {
            ans += query(jobl, jobr, l, mid, i * 2);
        }
        if (jobr > mid) {
            ans += query(jobl, jobr, mid + 1, r, i * 2 + 1);
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
        int op, l, r;
        i64 val;
        cin >> op;
        if (op == 1) {
            cin >> l >> r >> val;
            seg.updateRange(l, r, val, n);
        } else {
            cin >> l >> r;
            cout << seg.sumRange(l, r, n) << "\n";
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
