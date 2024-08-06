#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

// 前缀和：快速得到一个区间的和
// 二维前缀和：左 + 上 - 左上 + 自己

struct PrefixSum {
    vector<int> pre_sum1;
    vector<vector<int>> pre_sum2;

    void md_One(vector<int> &num) {
        int n = num.size();
        pre_sum1.resize(n + 1);

        for (int i = 1; i <= n; i++)
            pre_sum1[i] = pre_sum1[i - 1] + num[i - 1];
    }

    int one_Sum(int a, int b) {
        // return [a, b]
        return pre_sum1[b] - pre_sum1[a - 1];
    }

    void md_Tow(vector<vector<int>> &num) {
        int n = num.size(), m = num[0].size();
        pre_sum2.resize(n + 1, vector<int>(m + 1));

        for (int a = 1, c = 0; c < n; c++, a++) {
            for (int b = 1, d = 0; d < m; d++, b++) {
                pre_sum2[a][b] = num[c][d];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pre_sum2[i][j] += pre_sum2[i - 1][j] + pre_sum2[i][j - 1] -
                                  pre_sum2[i - 1][j - 1];
            }
        }
    }

    int two_Sum(int a, int b, int c, int d) {
        return pre_sum2[c][d] - pre_sum2[c][b - 1] - pre_sum2[a - 1][d] + pre_sum2[a - 1][b - 1];
    }
};

void Solve() {
    vector<int> nums1 = {1, 2, 3, 4, 5};
    PrefixSum ps;
    ps.md_One(nums1);
    cout << ps.one_Sum(2, 4) << endl; // 输出 9 (2+3+4)

    vector<vector<int>> nums2 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    ps.md_Tow(nums2);
    cout << ps.two_Sum(1, 1, 2, 2) << endl; // 输出 28 (5+6+8+9)
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
