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

const int mod = 1e9 + 7;

// 矩阵乘法 a的行数一定要等于b的列数
vector<vector<i64>> matrix(vector<vector<i64>>& a, vector<vector<i64>>& b) {
    i64 n = a.size(), m = b[0].size(), k = a[0].size();

    vector<vector<i64>> res(n, vector<i64>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int c = 0; c < k; c++) {
                res[i][j] = (a[i][c] * b[c][j] + res[i][j]) % mod;
            }
        }
    }
    return res;
}

// 矩阵快速幂, a一定要是正方形 O(log(n) * k^3)
vector<vector<i64>> matrix_qpow(vector<vector<i64>>& a, i64 b) {
    i64 n = a.size();
    vector<vector<i64>> res(n, vector<i64>(n));
    for (int i = 0; i < n; i++) {
        res[i][i] = 1;
    }
    while (b) {
        if (b & 1) {
            res = matrix(res, a);
        }
        a = matrix(a, a);
        b >>= 1;
    }
    return res;
}

int numTilings(int n) {
    n -= 1;
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return 2;
    }
    if (n == 2) {
        return 5;
    }
    vector<vector<i64>> start = {{5, 2, 1}};
    vector<vector<i64>> base = {{2, 1, 0}, {0, 0, 1}, {1, 0, 0}};

    // f[n] = f[n - 1] + f[n - 3] 其实是三阶，第二阶是0
    vector<vector<i64>> tmp = matrix_qpow(base, n - 2);  // 三阶就-2
    vector<vector<i64>> ans = matrix(start, tmp);

    return ans[0][0];
}

void Solve() {
    vector<vector<i64>> a = {{1, 2}, {2, 1}};

    vector<vector<i64>> res = matrix_qpow(a, 3);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
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
