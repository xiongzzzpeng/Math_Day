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

// 离散化，原数组的每一个元素在副本中的位置，位置即为排名，将其作为离散化后的值。
// [0 , n - 1]
vector<int> LSH(vector<int> &arr) {
    vector<int> tmp(arr);

    sort(tmp.begin(), tmp.end());

    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = lower_bound(tmp.begin(), tmp.end(), arr[i]) - tmp.begin();
    }
    return arr;
}

void Solve() {
    vector<int> a = {30, 1, 5, 6, 100, 2, 90, 2};
    a = LSH(a);
    for (auto x : a) {
        cout << x << " ";
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
