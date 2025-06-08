#include <bits/stdc++.h>
using namespace std;
#define LOCAL
// #define DEBUG

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using i128 = __int128_t;

constexpr i64 inf = 1e18;
constexpr int MAXN = 50000;

struct Line {
    i64 k = 0.0, b = -inf;
};
struct LineTree {
    int n;
    vector<Line> lines;
    vector<int> tr;  // 记录当前节点范围的最优线段
    vector<i64> xs;  // 记录当前x对应下标

    LineTree(int _n) : n(_n) {
        xs.resize(n);
        for (int i = 0; i < n; i++) {
            xs[i] = i + 1;
        }
        tr.assign(4 * n, 0);
        lines.emplace_back(Line());  // 初始化为哨兵
    }

    inline int getX(int x) {
        return xs[x];
    }

    inline i64 getY(int p, int x) {
        return lines[p].k * getX(x) + lines[p].b;
    }

    void rangeApply(int p, int l, int r, int L, int R, int id) {
        int mid = (l + r) / 2;
        if (L <= l && r <= R) {
            if (getY(tr[p], mid) < getY(id, mid)) {
                swap(id, tr[p]);
            }
            if (getY(tr[p], l) < getY(id, l)) {
                rangeApply(p * 2, l, mid, L, R, id);
            }
            if (getY(tr[p], r) < getY(id, r)) {
                rangeApply(p * 2 + 1, mid + 1, r, L, R, id);
            }
            return;
        }
        if (L <= mid) {
            rangeApply(p * 2, l, mid, L, R, id);
        }
        if (R > mid) {
            rangeApply(p * 2 + 1, mid + 1, r, L, R, id);
        }
    }

    i64 rangeQuery(int p, int l, int r, int x) {
        if (x < l || x > r) {
            return -inf;
        }
        if (l == x && r == x) {
            return getY(tr[p], x);
        }
        int mid = (l + r) / 2;
        if (x <= mid) {
            return max(getY(tr[p], x), rangeQuery(p * 2, l, mid, x));
        }
        return max(getY(tr[p], x), rangeQuery(p * 2 + 1, mid + 1, r, x));
    }
};

void Solve() {
    int N;
    cin >> N;

    LineTree LCT(MAXN);
    bool flag = false;

    while (N--) {
        string op;
        cin >> op;
        if (op == "Project") {
            double s, p;
            cin >> s >> p;  // k = p, b = (s - p)
            Line ln;
            ln.k = p, ln.b = s - p;
            LCT.lines.emplace_back(ln);
            int id = (int)LCT.lines.size() - 1;
            LCT.rangeApply(1, 0, LCT.n - 1, 0, LCT.n - 1, id);
            flag = true;
        } else {
            int t;
            cin >> t;
            double res = 0.0;
            if (flag && t >= 1 && t <= MAXN) {
                double q = LCT.rangeQuery(1, 0, LCT.n - 1, t - 1);
                res = max(0.0, q);
            }

            i64 ans = (i64)(res / 100.0);

            cout << ans << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

#ifdef LOCAL
    clock_t START = clock();
    freopen("zcy.in", "r", stdin);
    freopen("zcy.out", "w", stdout);
#endif

    int T = 1;
    // cin >> T;
    while (T--) {
        Solve();
    }

#ifdef DEBUG
    cerr << "time: " << clock() - START << endl;
#endif

    return 0;
}