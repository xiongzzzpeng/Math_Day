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

// 单调栈算区间的题

class Solution {
   public:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();

        vector<int> st;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.back()] >= nums[i]) {
                int tmp = st.back();
                st.pop_back();
                int l = st.empty() ? -1 : st.back();
                ans = max(ans, nums[tmp] * (i - l - 1));
            }
            st.push_back(i);
        }
        while (!st.empty()) {
            int tmp = st.back();
            st.pop_back();
            int l = st.empty() ? -1 : st.back();
            ans = max(ans, (n - l - 1) * nums[tmp]);
        }

        return ans;
    }
};

void Solve() {
    vector<int> nums = {2, 1, 5, 6, 2, 3};
    Solution s1;
    s1.largestRectangleArea(nums);
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
