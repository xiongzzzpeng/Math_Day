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

// 二维Fenwick
template <typename T>
class Fenwick {
   public:
    Fenwick(int n_, int m_) {
        init(n_, m_);
    }

    // (i, j)的点添加val
    void update(int i, int j, const T& val) {
        add(i + 1, j + 1, val - nums[i + 1][j + 1]);
        nums[i + 1][j + 1] = val;
    }

    // 计算[0, 0]到[i, j]的值
    T sum(int i, int j) {
        T ans{};
        for (int x = i; x > 0; x -= x & -x) {
            for (int y = j; y > 0; y -= y & -y) {
                ans += a[x][y];
            }
        }
        return ans;
    }

    // 计算[x1, y1] 到 [x2, y2]的值
    T rangeSum(int x1, int y1, int x2, int y2) {
        return sum(x2 + 1, y2 + 1) - sum(x1, y2 + 1) - sum(x2 + 1, y1) + sum(x1, y1);
    }

   private:
    int n, m;
    vector<vector<T>> a, nums;

    void init(int n_, int m_) {
        n = n_, m = m_;
        a.assign(n + 2, vector<T>(m + 2, T{}));
        nums.assign(n + 2, vector<T>(m + 2, T{}));
    }

    void add(int i, int j, const T& val) {
        for (int x = i; x <= n; x += x & -x) {
            for (int y = j; y <= m; y += y & -y) {
                a[x][y] += val;
            }
        }
    }
};

void Solve() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Fenwick<int> fenwick(3, 3);

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            fenwick.update(i, j, matrix[i][j]);
        }
    }

    // 用原数组的坐标值
    cout << fenwick.rangeSum(0, 0, 1, 1) << "\n";
    // sum的使用是fenwick的坐标
    cout << fenwick.sum(2, 2) << "\n";
    fenwick.update(1, 1, 10);
    cout << fenwick.rangeSum(0, 0, 1, 1) << "\n";
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
