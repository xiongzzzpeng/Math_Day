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

// 求max(H[i+1, j]) == H[j] 前缀最大值
// 倒着看单调栈的元素个数

void Solve() {
    int N;
    cin >> N;

    vector<int> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    vector<int> st;
    vector<int> ans(N);
    for (int i = N - 1; i >= 0; i--) {
        ans[i] = st.size();
        while (!st.empty() && H[st.back()] < H[i]) {
            st.pop_back();
        }
        st.push_back(i);
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << " " << " \n"[i == N - 1];
    }
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
