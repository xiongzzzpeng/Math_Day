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

// 埃氏筛, 选范围内质数的个数
// O(n * log(log))

void Solve() {
    int n;
    cin >> n;

    vector<int> flag(n + 1);
    for (int i = 2; i * i <= n; i++) {
        if (!flag[i]) {
            for (int j = i * i; j <= n; j += i) {
                flag[j] = 1;
            }
        }
    }

    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (!flag[i]) {
            cnt++;
        }
    }

    cout << cnt << endl;
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
