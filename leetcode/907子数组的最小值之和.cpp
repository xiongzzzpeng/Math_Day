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

// 单调栈+区间处理

const int mod = 1e9 + 7;

class Solution {
   public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> flag(n + 1, -1);

        i64 ans = 0;
        vector<int> st;
        int now = 0;
        for (int i = 0; i < n; i++) {
            while (now > 0 && arr[st.back()] >= arr[i]) {
                int tmp = st.back();
                st.pop_back();
                now--;
                flag[tmp] = i;
                int l = st.empty() ? -1 : st.back();
                ans = (ans + 1LL * (tmp - l) % mod * (i - tmp) % mod * arr[tmp] % mod) % mod;
            }
            st.push_back(i);
            now++;
        }
        while (now > 0) {
            int tmp = st.back();
            st.pop_back();
            now--;
            int l = st.empty() ? -1 : st.back();
            ans = (ans + 1LL * (tmp - l) % mod * (n - tmp) % mod * arr[tmp] % mod) % mod;
        }

        return ans % mod;
    }
};

void Solve() {}

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
