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

void Solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> st;
    int now = 0;
    vector<vector<int>> ans(n, vector<int>(2, -1));

    for (int i = 0; i < n; i++) {
        while (now > 0 && arr[st.back()] >= arr[i]) {
            int cur = st.back();
            st.pop_back();
            now--;
            ans[cur][0] = (now > 0) ? st.back() : -1;
            ans[cur][1] = i;
        }
        st.push_back(i);
        now++;
    }

    while (now > 0) {
        int cur = st.back();
        st.pop_back();
        now--;
        ans[cur][0] = (now > 0) ? st.back() : -1;
        ans[cur][1] = -1;
    }

    for (int i = n - 2; i >= 0; i--) {
        if (ans[i][1] != -1 && arr[ans[i][1]] == arr[i]) {
            ans[i][1] = ans[ans[i][1]][1];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i][0] << " " << ans[i][1] << endl;
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
