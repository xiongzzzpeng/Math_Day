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

    // 查询区间 [x, y)，能返回区间最大值，区间最大值出现次数
    Info query(int x, int y) {
        return query(1, 0, n, x, y);
    }

    // [x, y)的区间和
    i64 Sum(int x, int y) {
        return query(1, 0, n, x, y).sum;
    }

    // 将 [x, y) 区间内添加 v
    void rangeAdd(int x, int y, int v) {
        rangeAdd(1, 0, n, x, y, v);
    }

    // 将 x 处的值改为 v
    void modify(int x, const Info &v) {
        modify(1, 0, n, x, v);
    }

   private:
    int n;              // 原数组的大小
    vector<int> tag;    // 懒惰标记，用于区间更新
    vector<Info> info;  // 线段树节点，包含区间的信息

    // 从子节点更新当前节点的信息
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }

    // 将值 v 添加到当前节点（用于懒惰传播）
    void add(int p, int v, int l, int r) {
        tag[p] += v;
        info[p].max += v;
        info[p].sum += v * (r - l);
    }

    // 将懒惰标记向子节点传递
    void push(int p, int l, int r) {
        int m = (l + r) / 2;
        add(2 * p, tag[p], l, m);
        add(2 * p + 1, tag[p], m, r);
        tag[p] = 0;
    }

    // 内部查询函数，用于获取区间 [x, y) 的信息
    Info query(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return {};  // 如果超出查询范围，返回空的 Info 对象
        }
        if (l >= x && r <= y) {
            return info[p];  // 完全在查询范围内
        }
        int m = (l + r) / 2;
        push(p, l, r);  // 向下传递懒惰标记，确保所有更新已应用
        return query(2 * p, l, m, x, y) + query(2 * p + 1, m, r, x, y);  // 合并左右子节点的结果
    }

    // 内部函数，将值 v 添加到区间 [x, y) 的所有元素中
    void rangeAdd(int p, int l, int r, int x, int y, int v) {
        if (l >= y || r <= x) {
            return;  // 超出范围
        }
        if (l >= x && r <= y) {
            add(p, v, l, r);  // 完全在范围内，直接添加值
            return;
        }
        int m = (l + r) / 2;
        push(p, l, r);                       // 向下传递懒惰标记，确保所有更新已应用
        rangeAdd(2 * p, l, m, x, y, v);      // 对左子节点应用区间加法
        rangeAdd(2 * p + 1, m, r, x, y, v);  // 对右子节点应用区间加法
        pull(p);                             // 从子节点更新当前节点的信息
    }

    // 内部函数，修改索引 x 处的元素为值 v
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;  // 叶子节点，直接修改
            return;
        }
        int m = (l + r) / 2;
        push(p, l, r);  // 向下传递懒惰标记，确保所有更新已应用
        if (x < m) {
            modify(2 * p, l, m, x, v);  // 在左子节点中修改
        } else {
            modify(2 * p + 1, m, r, x, v);  // 在右子节点中修改
        }
        pull(p);  // 从子节点更新当前节点的信息
    }
};

void Solve() {
    int n = 10;
    SegmentTree segTree(n);

    // 初始化线段树
    for (int i = 0; i < n; i++) {
        // 第三个位置放填入的值
        segTree.modify(i, {i, 1, i});
    }

    // 查询区间 [0, 5) 的最大值和最大值出现次数
    Info result = segTree.query(0, 5);
    cout << result.max << result.cnt << endl;

    // 查询区间 [0, 5) 的累加和
    int sumResult = segTree.Sum(0, 5);
    cout << sumResult << endl;

    // 将区间 [2, 7) 内的所有元素加 3
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
