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

class Solution {
   public:
    bool makesquare(vector<int>& arr) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum % 4) {
            return false;
        }

        vector<int> dp((1 << n) - 1, -1);
        auto dfs = [&](auto& self, int s, int len = 0, int res = 4) {
            if (!res) {
                return s == 0;
            }
            if (dp[s] != -1) {
                return dp[s] == 1;
            }
            bool ans = false;
            for (int i = 0; i < n; i++) {
                if ((s & (1 << i)) != 0 && len + arr[i] <= sum / 4) {
                    if (len + arr[i] < sum / 4) {
                        ans = self(self, s ^ (1 << i), len + arr[i], res);
                    } else {
                        ans = self(self, s ^ (1 << i), 0, res - 1);
                    }
                    if (ans) {
                        break;
                    }
                }
            }
            dp[s] = ans ? 1 : 0;
            return ans;
        };

        return dfs(dfs, (1 << n) - 1);
    }
};

void Solve() {
    int res = 7;
    int i = 3;
    while (i > 1) {
        res = res * 10 + 7;
        i--;
    }
    cout << res;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);

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