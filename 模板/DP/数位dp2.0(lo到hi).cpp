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

int count(string num1, string num2, int min_sum, int max_sum) {
    int n = num2.size();
    // 补上前导0
    num1 = string(n - num1.size(), '0') + num1;

    // 根据题意写记忆化数组
    vector<vector<int>> mem(n, vector<int>(min(9 * n, max_sum) + 1, -1));

    // 一般模板是不要sum的，sum根据题意修改
    auto dfs = [&](auto &self, int i, int sum, bool limit_low, bool limit_high) -> int {
        if (sum > max_sum) {
            return 0;
        }
        if (i == n) {
            return sum >= min_sum;
        }
        if (!limit_low && !limit_high && mem[i][sum] != -1) {
            return mem[i][sum];
        }

        int lo = limit_low ? num1[i] - '0' : 0;
        int hi = limit_high ? num2[i] - '0' : 9;

        int res = 0;
        for (int d = lo; d <= hi; d++) {
            res = (res + self(self, i + 1, sum + d, limit_low && d == lo, limit_high && d == hi)) % 1'000'000'007;
        }
        if (!limit_low && !limit_high) {
            mem[i][sum] = res;
        }
        return res;
    };

    return dfs(dfs, 0, 0, true, true);
}

void Solve() {}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

#ifdef LOCAL
    freopen("xzp.in", "r", stdin);
    freopen("xzp.out", "w", stdout);
#endif

    int T = 1;
    cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}